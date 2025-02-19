#include "search.h"

#include <stdexcept>
#include <unordered_map>
#include <string_view>
#include <unordered_set>
#include <cctype> // tolower

#include "input_output.h"
#include "constants.h"

using std::string_view;
using std::unordered_map;
using std::unordered_set;

vector<string> read_textfile(const string &filename)
{
    io::ifstream file(filename.c_str());

    // Jos tiedostoa ei saada avattua, heitetään poikkeus
    if (!file)
        throw std::runtime_error("Could not open file \"" + filename + "\"");

    vector<string> lines;
    string line;
    // Luetaan tiedosto rivi kerrallaan ja tallennetaan vektoriin
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

int find_substr(const string &haystack, const string &needle)
{
    size_t pos = haystack.find(needle);
    return (pos == string::npos) ? -1 : static_cast<int>(pos);
}

bool is_2byte_char(const unsigned char &c)
{
    if (c >= 0xC0)
        return true;
    else
        return false;
}

void tolower_str(string &str)
{
    // Määritellään merkkijono, johon tallennetaan pieniksi kirjaimiksi muutettu merkkijono
    string lower;
    // Käydään läpi jokainen merkkijonon indeksi
    for (size_t i = 0; i < str.size(); i++)
    {
        // Jos on ääkkönen muutetaan manuaalisesti kirjaimet pieniksi
        if (is_2byte_char(str[i]))
        {
            if (str.substr(i, 2) == "Ä")
                lower += "ä";

            else if (str.substr(i, 2) == "Ö")
                lower += "ö";

            else if (str.substr(i, 2) == "Å")
                lower += "å";

            // Jos on ääkkönen, mutta on valmiiksi pieni
            else
                lower += str.substr(i, 2);

            // Lisätään ylimääräinen indeksiluku, koska ääkköset vievät kaksi merkkipaikkaa
            i++;
        }
        // Normaalit kirjaimet muutetaan normaalisti
        else
            lower += tolower(str[i]);
    }
    str = lower; // Muutetaan alkuperäinen merkkijono muutetuksi.
    return;
}

void grep_arg(const int &argc, const char *const argv[])
{
    // Aliohjelma toimii vain jos komentoriviargumentteja on 2 tai 3 ohjelmakutsun jälkeen
    if (argc <= 2 || argc >= 5)
        throw std::runtime_error("Unknown number of arguments!");

    unordered_set<char> options; // Käyttäjän syöttämät optiot

    // Virhetarkastelut optioille
    if (argc == 4)
    {
        // Option tarkastaminen
        if (argv[1][0] != '-' || argv[1][1] != 'o')
            throw std::runtime_error("Unknown option!");

        if (strlen(argv[1]) == 2)
            throw std::runtime_error("No options after -o!");

        // Liikaa optioita -o jälkeen
        if (strlen(argv[1]) > OPTIONS.size() + 2)
            throw std::runtime_error("Option list too long after -o!");

        unordered_map<char, int> option_tag_count;
        // Merkkijononäkymä std::string_view mahdollistaa char*-tyyppisen merkkijonon
        // käsittelyn kuten std::string, mutta ilman ylimääräistä kopiointia tai muistiallokointia.
        // Sisältää vain optiot -o jälkeen.
        string_view option_tag_str(argv[1] + 2);

        for (char c : option_tag_str)
        {
            // Jos -o jälkeen on muita kuin sallittuja optiomerkkejä.
            if (OPTIONS.find(c) == OPTIONS.end())
                throw std::runtime_error("Contains illegal options after -o!");

            // Jos sama on useamman kerran.
            if (++option_tag_count[c] > 1)
                throw std::runtime_error("Same option multiple times after -o!");
        }

        // Lisätään käyttäjän syöttämät optiot settiin helpompaa käsittelyä varten.
        for (int i = 0; i < option_tag_str.length(); i++)
        {
            options.insert(option_tag_str[i]);
        }
    }

    // Optiot
    bool line_numbering = options.find('l') != options.end();
    bool occurrences = options.find('o') != options.end();
    bool reverse = options.find('r') != options.end();
    bool ignore_case = options.find('i') != options.end();

    string filename = argv[argc == 3 ? 2 : 3];
    string needle = argv[argc == 3 ? 1 : 2]; // Merkkijono jota haetaan.
    // Hakuun käytettävä needle-muuttuja.
    // Säilytetään alkuperäinen alkuperäisessä kunnossa esim. ignore-case-tapauksessa.
    string needle_srch = needle;
    vector<string> haystack = read_textfile(filename);

    if (ignore_case)
        tolower_str(needle_srch);

    int lines_found = 0;

    // Käydään joka rivi läpi tiedostosta.
    for (int i = 0; i < haystack.size(); i++)
    {
        // Jos, ignore-case, niin muokataan tätä pieneksi.
        // Säilytetään alkupreäinen teksti haystack-muuttujassa.
        string haystack_line = haystack[i];
        if (ignore_case)
            tolower_str(haystack_line);

        if (!reverse && find_substr(haystack_line, needle_srch) >= 0 ||
            reverse && find_substr(haystack_line, needle_srch) == -1)
        {
            lines_found++;
            if (line_numbering)
            {
                io::cout << i + 1 << ":";
            }
            io::cout << haystack[i] << "\n";
        }
    }
    if (occurrences)
    {
        if (reverse)
            io::cout << "\nOccurrences of lines NOT containing \"" << needle << "\""
                     << (ignore_case ? " case ignored" : "") << ": " << lines_found;
        else
            io::cout << "\nOccurrences of lines containing \"" << needle << "\""
                     << (ignore_case ? " case ignored" : "") << ": " << lines_found;
    }

    return;
}

void grep_basic()
{
    string haystack; // Merkkijono josta etsitään
    string needle;   // Merkkijono jota etsitään

    io::cout << "Give a string from which to search for: ";
    getline(io::cin, haystack);
    io::cout << "Give search string: ";
    getline(io::cin, needle);

    int found_index = find_substr(haystack, needle);

    // Jos löytyy
    if (found_index >= 0)
        io::cout << "\"" << needle << "\" found in \"" << haystack
                 << "\" in position " << found_index << "\n";

    // Jos ei löydy
    else
        io::cout << "\"" << needle << "\" NOT found in \"" << haystack << "\"\n";

    return;
}