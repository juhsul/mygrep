#include "search.h"

#include <stdexcept>

#include "input_output.h"

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

void grep_arg(const string &needle, const string &filename)
{
    vector<string> haystack = read_textfile(filename);

    for (string line : haystack)
    {
        if (find_substr(line, needle) >= 0)
        {
            io::cout << line << "\n";
        }
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