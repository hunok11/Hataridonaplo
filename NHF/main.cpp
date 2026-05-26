#include "gtest_lite.h"
#include <iostream>
#include "string5.h"
#include "EsemenyKezelo.h"
#include "FajlKezelo.h"
#include "Felhasznalo.h"
#include "memtrace.h"
int main() {
    EsemenyKezelo kezelom;
    const char* fajlNev = "esemenyek.txt";
    Esemeny** beolvasott = FajlKezelo::beolvasFajlbol((char*)fajlNev);

    if (!beolvasott) {
        std::cerr << "Nem sikerült beolvasni a fájlt.\n";
        return 1;
    }

    for (size_t i = 0; beolvasott[i] != nullptr; ++i) {
        kezelom.beleteszEsemeny(beolvasott[i]);
    }
    delete[] beolvasott;

    Felhasznalo felh;
    felh.menu(kezelom);

    return 0;
}