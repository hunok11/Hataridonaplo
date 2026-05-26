#include "Felhasznalo.h"
#include "EsemenyKezelo.h"
#include "FajlKezelo.h"
#include "Esemeny.h"
#include "OnlineEsemeny.h"
#include "VisszateroEsemeny.h"
#include "FontosEsemeny.h"
#include "Ellenorzo.h"
#include <iostream>

using namespace std;

void Felhasznalo::menu(EsemenyKezelo& kezelo) {
    int menupont = 0;
    String input;

    do {
        std::cout <<
            "\n--- Hataridonaplo Menu ---\n"
            "1: Esemenyek listazasa\n"
            "2: Uj esemeny hozzaadasa\n"
            "3: Esemeny keresese nev alapjan\n"
            "4: Esemeny modositasa\n"
            "5: Esemeny torlese\n"
            "6: Mentes fajlba\n"
            "7: Kilepes\n"
            "Valasztas: ";

        std::cin >> input;

        if (!Ellenorzo::ervenyesMenuPont(input, menupont)) {
            std::cout << "Ervenytelen valasztás! 1-7 kozott valassz.\n";
            continue;
        }

        switch (menupont) {
        case 1:
            kezelo.listazEsemenyek();
            break;
        case 2:
            kezelo.hozzaadEsemeny();
            break;
        case 3:
            kezelo.keresEsemeny();
            break;
        case 4:
            kezelo.modositEsemeny();
            break;
        case 5:
            kezelo.torolEsemeny();
            break;
        case 6: {
            FajlKezelo::mentesFajlba(kezelo.getEsemenyek(), kezelo.getMeret());
            break;
        }
        case 7:
            std::cout << "Kilepes...\n";
            break;
        }

    } while (menupont != 7);
}