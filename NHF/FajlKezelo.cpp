#include <cstdio>
#include <fstream>
#include "FajlKezelo.h"
#include "Esemeny.h"
#include "OnlineEsemeny.h"
#include "VisszateroEsemeny.h"
#include "FontosEsemeny.h"
#include "Ellenorzo.h"
#include <cstring>
#define MAX_SOR 1024

void FajlKezelo::mentesFajlba(Esemeny** esemenyek, int meret) {
    char fajlNev[100];
    std::cout << "Add meg a mentesi fajl nevet (pl. kimenet.csv): ";
    std::cin.ignore();  // ha előző cin >> után vagyunk
    std::cin.getline(fajlNev, 100);

    std::ofstream fajl(fajlNev);
    if (!fajl.is_open()) {
        std::cerr << "Hiba a fajl megnyitásakor: " << fajlNev << "\n";
        return;
    }

    for (int i = 0; i < meret; ++i) {
        if (esemenyek[i] == nullptr) continue;

        const String& datum = esemenyek[i]->getDatum();
        const String& idopont = esemenyek[i]->getIdopont();
        const String& nev = esemenyek[i]->getNev();
        const String& helyszin = esemenyek[i]->getHelyszin();
        const String& megjegyzes = esemenyek[i]->getMegjegyzes();

        fajl << datum.c_str() << ";"
            << idopont.c_str() << ";"
            << nev.c_str() << ";"
            << helyszin.c_str() << ";"
            << megjegyzes.c_str();

        if (auto* o = dynamic_cast<OnlineEsemeny*>(esemenyek[i])) {
            fajl << ";" << o->getUrl().c_str();
        }
        else if (auto* v = dynamic_cast<VisszateroEsemeny*>(esemenyek[i])) {
            fajl << ";" << v->getGyakorisag().c_str();
        }
        else if (auto* f = dynamic_cast<FontosEsemeny*>(esemenyek[i])) {
            fajl << ";" << f->getPrioritas().c_str();
        }

        fajl << "\n";
    }

    fajl.close();
    std::cout << "Mentes sikeresen megtortent: " << fajlNev << std::endl;
}
Esemeny** FajlKezelo::beolvasFajlbol(char* fajlNev) {
    std::ifstream fajl(fajlNev);
    if (!fajl.is_open()) {
        std::cerr << "Hiba! Nem sikerult megnyitni a fajlt: " << fajlNev << "\n";
        return nullptr;
    }

    char sor[MAX_SOR];
    size_t kapacitas = 10;
    size_t index = 0;
    Esemeny** tomb = new Esemeny * [kapacitas +1];

    while (fajl.getline(sor, MAX_SOR)) {
        sor[strcspn(sor, "\n")] = 0;

        String sorStr(sor);
        String mezok[6];
        size_t i = 0;

        size_t start = 0;
        for (size_t pos = 0; pos < sorStr.size(); ++pos) {
            if (sorStr[pos] == ';') {
                String mezo = "";
                for (size_t j = start; j < pos; ++j) {
                    mezo = mezo + sorStr[j];
                }
                mezok[i++] = mezo;
                start = pos + 1;
            }
        }
        if (start < sorStr.size() && i < 6) {
            String mezo = "";
            for (size_t j = start; j < sorStr.size(); ++j) {
                mezo = mezo + sorStr[j];
            }
            mezok[i++] = mezo;
        }

        if (!Ellenorzo::ervenyesDatum(mezok[0]) || !Ellenorzo::ervenyesIdopont(mezok[1]) ||
            !Ellenorzo::ervenyesNev(mezok[2])) {
            continue;
        }

        Esemeny* uj = nullptr;
        const char* tipus = mezok[5].c_str();

        if (mezok[5].size() > 0) {
            if (strstr(tipus, "https:")) {
                uj = new OnlineEsemeny(mezok[0], mezok[1], mezok[2],
                    mezok[3], mezok[4], mezok[5]);
            }
            else if (strcmp(tipus, "napi") == 0 || strcmp(tipus, "heti") == 0 || strcmp(tipus, "havi") == 0) {
                uj = new VisszateroEsemeny(mezok[0], mezok[1], mezok[2],
                    mezok[3], mezok[4], mezok[5]);
            }
            else if (strcmp(tipus, "magas") == 0 || strcmp(tipus, "alacsony") == 0) {
                uj = new FontosEsemeny(mezok[0], mezok[1], mezok[2],
                    mezok[3], mezok[4], mezok[5]);
            }
            else {
                uj = new Esemeny(mezok[0], mezok[1], mezok[2],
                    mezok[3], mezok[4]);
            }
        }
        else {
            uj = new Esemeny(mezok[0], mezok[1], mezok[2],
                mezok[3], mezok[4]);
        }

        
        if (index >= kapacitas) {
            kapacitas *= 2;
            Esemeny** ujTomb = new Esemeny * [kapacitas+1];
            for (size_t j = 0; j < index; ++j) {
                ujTomb[j] = tomb[j];
            }
            delete[] tomb;
            tomb = ujTomb;
        }

        tomb[index++] = uj;
    }

    fajl.close();

    tomb[index] = nullptr; 
    return tomb;
}