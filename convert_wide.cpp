#include <string>
#include <stdexcept>

#include "wide_exception.h"

using namespace std;

wstring convert_to_wstr(const string &str)
{
    // Tarkistetaan vaadittu pituus ja samalla tarkistetaan että muunnos on mahdollista.
    size_t len = mbstowcs(nullptr, str.c_str(), 0);
    if (len == static_cast<size_t>(-1))
    {
        throw WruntimeError(L"String conversion failed!");
    }

    wstring wstr(len, L'\0');             // Alustetaan leveä merkkijono oikean pituiseksi.
    mbstowcs(&wstr[0], str.c_str(), len); // Muunnos
    return wstr;
}