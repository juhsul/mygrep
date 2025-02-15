#include "search.h"

#include <fstream>
#include <iostream>

vector<string> read_textfile(const string &filename)
{
    ifstream file(filename.c_str());

    // Jos tiedostoa ei saada avattua, heitetään poikkeus
    if (!file)
        throw runtime_error("Could not open file \"" + filename + "\"");

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
            cout << line << "\n";
        }
    }

    return;
}

void grep_basic()
{
    string haystack; // Merkkijono josta etsitään
    string needle;   // Merkkijono jota etsitään

    cout << "Give a string from which to search for: ";
    getline(cin, haystack);
    cout << "Give search string: ";
    getline(cin, needle);

    int found_index = find_substr(haystack, needle);

    // Jos löytyy
    if (found_index >= 0)
        cout << "\"" << needle << "\" found in \"" << haystack
             << "\" in position " << found_index << "\n";

    // Jos ei löydy
    else
        cout << "\"" << needle << "\" NOT found in \"" << haystack << "\"\n";

    return;
}