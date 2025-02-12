# mygrep

Tampereen ammattikorkeakoulussa _Ohjelmoinnin edistyneet piirteet_ -kurssilla suoritettava pieni projekti. Projektin ideana on toteuttaa mygrep-niminen ohjelma, joka pohjautuu Unix/Linux-ympäristössä yleisesti käytettyyn grep-työkaluun.

<br>

## Kääntäminen **CMaken** ja **Ninjan** avulla

Tämä projekti käyttää **CMakea** ja **Ninjaa** ohjelman kääntämiseen. Kääntäminen onnistuu myös ilman Ninjaa.

### Kääntäminen Ninjan kanssa

```sh
# Luo build-kansion ja konfiguroi projektin käyttäen Ninjaa rakentajana
cmake -B build -G Ninja
# Rakentaa ohjelman build-kansiossa
ninja -C build
```

### Kääntäminen ilman Ninjaa:

```sh
# Luo build-kansion ja konfiguroi projektin (käyttää oletusrakentajaa)
cmake -B build
# Rakentaa ohjelman build-kansiossa
cmake --build build
```

Ohjelman voi suorittaa käännöksen jälkeen ajamalla:

```sh
./build/mygrep      # Linux / MSYS2
build\mygrep.exe    # Windows (cmd)
```

<br>

## Tehtävänanto lyhyesti omin sanoin

Tehtävänä on tehdä oma grep-tyylinen ohjelma. Projektiin kuuluu inkrementtejä, joita tekemällä saa pisteitä. Jokaiseen inkrementtiin täytyy sisältyä myös aikaisempien inkrementtien ominaisuudet.

### 1. inkrementti (1 piste)

Ohjelma käynnistetään komentoriviltä ilman argumentteja. Käynnistyksen jälkeen ohjelma kysyy käyttäjältä:

1. Merkkijonoa, josta haetaan.
1. Merkkijonoa jota haetaan.

Ohjelma tulostaa joko:

- Rivin, josta etsittiin, sekä indeksin josta haettava merkkijono löytyi.
- Viestin, että merkkijonoa ei löytynyt.

Ohjelman esimerkkiajo:

```
./mygrep
Give a string from which to search for: Tähän teksti josta haetaan
Give search string: teksti
"teksti" found in "Tähän teksti josta haetaan" in position 6
```

```
./mygrep
Give a string from which to search for: Tähän toinen teksti josta haetaan
Give search string: tätä ei löydy
"tätä ei löydy" NOT found in "Tähän toinen teksti josta haetaan"
```

### 2. inkrementti (3 pistettä)

Ohjelmalle annetaan komentoriviargumentteina:

1. Merkkijono, jota haetaan.
1. Tekstitiedosto, josta haetaan.

Ohjelma tulostaa rivit, joilta haettava merkkijono löytyi.

Esimerkkiajo:

```
./mygrep etsi tiedosto.txt
Tämä rivi etsitään ja löydetään.
Tässä on toinen etsittävä rivi.
```

### 3. inkrementti (4 pistettä)

Ohjelmaan lisätään optioita, joilla voi muuttaa tulostusmuotoa. Optioita syötettäessä kirjoitetaan ensimmäiseksi argumentiksi `-o`, jonka jälkeen heti perään ilman väliä haluttu optio.

| Optio                | Selite                                          |
| -------------------- | ----------------------------------------------- |
| `l` (line numbering) | Tulostaa rivinumerot löydettyjen rivien eteen.  |
| `o` (occurrences)    | Tulostaa lopuksi löytyneiden rivien lukumäärän. |

Esimerkki optioiden käytöstä:

```
./mygrep -olo etsi tiedosto.txt
5:Tämä rivi etsitään ja löydetään.
12:Tässä on toinen etsittävä rivi.

Occurrences of lines containing "etsi": 2
```

### 4. inkrementti (5 pistettä)

Ohjelmassa pitää soveltaa jossain kohtaa poikkeuskäsittelyä. Lisäksi lisätään kaksi optiota.

| Optio                | Selite                                        |
| -------------------- | --------------------------------------------- |
| `r` (reverse search) | Käänteinen etsiminen.                         |
| `i` (ignore case)    | Isot ja pienet kirjaimet ovat saman arvoisia. |
