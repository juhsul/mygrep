#pragma once

#include <string>

using namespace std;

/**
 * @brief Muuntaa string-tietotyypin wstring-tietotyypiksi.
 *
 * @param x Muunnettava string.
 * @return wstring Muunnettu wstring.
 */
wstring convert_to_wstr(const string &str);