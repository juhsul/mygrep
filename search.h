#pragma once

#include <string>

using namespace std;

/**
 * @brief Etsii riviltä annettua merkkijonoa.
 *
 * @param haystack Merkkijono josta haetaan.
 * @param needle Merkkijono jota haetaan.
 * @return int Indeksi josta merkkijono löydettiin. -1 jos ei löydy.
 */
int find_substr(const wstring &haystack, const wstring &needle);