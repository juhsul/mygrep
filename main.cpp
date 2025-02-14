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
#include <vector>
#include <fcntl.h> // Unicode tulostuksen pakotukseen

#include "search.h"
#include "wide_exception.h"
#include "convert_wide.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        // Käyttää järjestelmän nykyistä kieli ja merkistöasetusta.
        setlocale(LC_ALL, "");
        _setmode(_fileno(stdout), _O_U16TEXT); // Pakottaa Unicode-tulostuksen
        _setmode(_fileno(stdin), _O_U16TEXT);  // Pakottaa Unicode-inputin

        vector<wstring> wargv; // Vektori komentoriviargumenttien leveille merkkijonoille.
        // Komentoriviargumenttien muuttaminen leveiksi merkkijonoiksi.
        for (int i = 0; i < argc; i++)
        {
            wargv.push_back(convert_to_wstr(argv[i]));
        }

        // Jos ohjelma käynnistetään ilman komentoriviargumentteja
        if (argc == 1)
        {
            grep_basic();
        }
        else if (argc == 3)
        {
            grep_arg(wargv[1], wargv[2]);
        }
    }
    catch (const WruntimeError &e)
    {
        wcerr << L"An exception occurred. " << e.wwhat() << L"\n";
    }

    return 0;
}