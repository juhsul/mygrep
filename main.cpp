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

#include <cstdlib>

#include "search.h"
#include "input_output.h"

int main(int argc, char *argv[])
{
// Windowsissa muuntaa komentoriviargumentit UTF-8-muotoon
#ifdef _WIN32
    io::args _(argc, argv);
#endif

    try
    {
        // Jos ohjelma käynnistetään ilman komentoriviargumentteja
        if (argc == 1)
        {
            grep_basic();
        }
        else
        {
            grep_arg(argc, argv);
        }
    }
    catch (const std::runtime_error &e)
    {
        io::cerr << "An exception occurred. " << e.what() << "\n";
    }

    return 0;
}