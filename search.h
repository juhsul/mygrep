#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * @brief Lukee annetun tekstitiedoston.
 *
 * @param filename Luettavan tiedoston tiedostonimi.
 * @return vector<string> Luettu tekstitiedosto. Jokainen rivi omalla indeksillään.
 */
vector<string> read_textfile(const string &filename);

/**
 * @brief Etsii riviltä annettua merkkijonoa.
 *
 * @param haystack Merkkijono josta haetaan.
 * @param needle Merkkijono jota haetaan.
 * @return int Indeksi josta merkkijono löydettiin. -1 jos ei löydy.
 */
int find_substr(const string &haystack, const string &needle);

/**
 * @brief Tulostaa löydetyt rivit annettujen tietojen avulla.
 *
 * @param needle Etsittävä merkkijono.
 * @param filename Tiedoston nimi, josta etsitään.
 */
void grep_arg(const string &needle, const string &filename);

/**
 * @brief Kysyy käyttäjältä merkkijonoa, jota etsitään, sekä merkkijonoa, mistä etsitään.
 *  Ohjelman yksinkertaisin toiminta.
 *
 */
void grep_basic();