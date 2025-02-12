// █████████████████████████████████████████████████████████████████████████████████████████████████
// █▌                                                                                             ▐█
// █▌                                                                                             ▐█
// █▌                                                                                             ▐█
// █▌                                                                                             ▐█
// █▌              █████████████   █████ ████  ███████ ████████   ██████  ████████                ▐█
// █▌             ░░███░░███░░███ ░░███ ░███  ███░░███░░███░░███ ███░░███░░███░░███               ▐█
// █▌              ░███ ░███ ░███  ░███ ░███ ░███ ░███ ░███ ░░░ ░███████  ░███ ░███               ▐█
// █▌              ░███ ░███ ░███  ░███ ░███ ░███ ░███ ░███     ░███░░░   ░███ ░███               ▐█
// █▌              █████░███ █████ ░░███████ ░░███████ █████    ░░██████  ░███████                ▐█
// █▌             ░░░░░ ░░░ ░░░░░   ░░░░░███  ░░░░░███░░░░░      ░░░░░░   ░███░░░                 ▐█
// █▌                               ███ ░███  ███ ░███                    ░███                    ▐█
// █▌                              ░░██████  ░░██████                     █████                   ▐█
// █▌                               ░░░░░░    ░░░░░░                     ░░░░░                    ▐█
// █▌                                                                                             ▐█
// █▌                                                                                             ▐█
// █████████████████████████████████████████████████████████████████████████████████████████████████

// ▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌
// ▐                             ▌
// ▐      * Juho Sulkonen        ▌
// ▐      * 2408450              ▌
// ▐      * TAMK 24TIETOB        ▌
// ▐      * Helmikuu 2025        ▌
// ▐                             ▌
// ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌

#include <iostream>

#include "search.h"

using namespace std;

int main(int argc, char *argv[])
{

    wstring haystack; // Merkkijono josta etsitään
    wstring needle;   // Merkkijono jota etsitään

    // Jos ohjelma käynnistetään ilman komentoriviargumentteja
    if (argc == 1)
    {
        wcout << L"Give a string from which to search for: ";
        getline(wcin, haystack);
        wcout << L"Give search string: ";
        getline(wcin, needle);

        int found_index = find_substr(haystack, needle);

        // Jos löytyy
        if (found_index >= 0)
        {
            wcout << "\"" << needle << "\" found in \"" << haystack
                  << "\" in position " << found_index << endl;
        }
        // Jos ei löydy
        else
        {
            wcout << "\"" << needle << "\" NOT found in \"" << haystack << "\"\n";
        }
    }

    return 0;
}