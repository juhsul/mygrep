#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

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
 * @brief Muuttaa merkkijonon kaikki kirjaimet pieniksi kirjaimiksi.
 *
 * @param str Muutettava merkkijono.
 */
void tolower_str(string &str);

/**
 * @brief Tulostaa löydetyt rivit annettujen tietojen avulla.
 *
 * @param argc Komentoriviargumenttien määrä.
 * @param argv Komentoriviargumenttien taulukko.
 */
void grep_arg(const int &argc, const char *const argv[]);

/**
 * @brief Kysyy käyttäjältä merkkijonoa, jota etsitään, sekä merkkijonoa, mistä etsitään.
 *  Ohjelman yksinkertaisin toiminta.
 *
 */
void grep_basic();