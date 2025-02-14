#include "search.h"
#include "wide_exception.h"
#include "convert_wide.h"

#include <fstream>
#include <iostream>

vector<wstring> read_textfile(const wstring &filename)
{
    wifstream file(filename.c_str());

    // Jos tiedostoa ei saada avattua, heitetään poikkeus
    if (!file)
        throw WruntimeError(L"Could not open file \"" + filename + L"\"");

    vector<wstring> lines;
    wstring line;
    // Luetaan tiedosto rivi kerrallaan ja tallennetaan vektoriin
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    return lines;
}

int find_substr(const wstring &haystack, const wstring &needle)
{
    size_t pos = haystack.find(needle);
    return (pos == wstring::npos) ? -1 : static_cast<int>(pos);
}

void grep_arg(const wstring &needle, const wstring &filename)
{
    vector<wstring> haystack = read_textfile(filename);

    for (wstring line : haystack)
    {
        if (find_substr(line, needle) >= 0)
        {
            wcout << line << L"\n";
        }
    }

    return;
}

void grep_basic()
{
    wstring haystack; // Merkkijono josta etsitään
    wstring needle;   // Merkkijono jota etsitään

    wcout << L"Give a string from which to search for: ";
    getline(wcin, haystack);
    wcout << L"Give search string: ";
    getline(wcin, needle);

    int found_index = find_substr(haystack, needle);

    // Jos löytyy
    if (found_index >= 0)
        wcout << L"\"" << needle << L"\" found in \"" << haystack
              << L"\" in position " << found_index << L"\n";

    // Jos ei löydy
    else
        wcout << L"\"" << needle << L"\" NOT found in \"" << haystack << L"\"\n";

    return;
}