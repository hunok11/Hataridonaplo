#include <iostream>
#include "Esemeny.h"
#include "string5.h"
#include "EsemenyKezelo.h"
#include "Ellenorzo.h"
#include "OnlineEsemeny.h"
#include "VisszateroEsemeny.h"
#include "FontosEsemeny.h"
#include <cstring>
#include <cstddef>
using namespace std;
EsemenyKezelo::EsemenyKezelo(size_t kezdoKapacitas)
    : meret(0), kapacitas(kezdoKapacitas) {
    esemenyek = new Esemeny * [kapacitas];
}
void EsemenyKezelo::bovitKapacitast() {
    kapacitas *= 2;
    Esemeny** ujTomb = new Esemeny * [kapacitas];
    for (size_t i = 0; i < meret; ++i) {
        ujTomb[i] = esemenyek[i];
    }
    delete[] esemenyek;
    esemenyek = ujTomb;
}


void EsemenyKezelo::beleteszEsemeny(Esemeny* e) {
    if (meret >= kapacitas) {
        bovitKapacitast();
    }
    esemenyek[meret++] = e;
}

void EsemenyKezelo::listazEsemenyek() const {
    for (size_t i = 0; i < meret; ++i) {
        if (esemenyek[i] != nullptr) {
            esemenyek[i]->kiir();
            cout << "------------------------------\n";
        }
    }
}
void EsemenyKezelo::hozzaadEsemeny() {
    String datum, idopont, nev, helyszin, leiras, tipus;

    while (true) {
        cout << "Add meg az esemeny datumat (YYYY-MM-DD): ";
        cin >> datum;
        if (!Ellenorzo::ervenyesDatum(datum)) {
            cout << "Hibas datumformatum!\n";
            continue;
        }

        cout << "Add meg az esemeny idopontjat (HH:MM): ";
        cin >> idopont;
        if (!Ellenorzo::ervenyesIdopont(idopont)) {
            std::cout << "Hibas idopontformatum!\n";
            continue;
        }
        cin.ignore();


        cout << "Add meg az esemeny nevet: ";
        nev.beolvas(cin);
        if (!Ellenorzo::ervenyesNev(nev)) {
            std::cout << "Hibas nev!\n";
            continue;
        }

        cout << "Add meg az esemeny helyszinet: ";
        helyszin.beolvas(cin);

        cout << "Add meg az esemeny leirasat: ";
        leiras.beolvas(cin);

        cout << "Add meg az esemeny tipusat (https://..., napi/heti/havi, magas/alacsony vagy hagyd uresen): ";
        tipus.beolvas(cin);

        Esemeny* uj = nullptr;
        const char* tipusC = tipus.c_str();

        if (tipus.size() > 0) {
            if (strstr(tipusC, "https:")) {
                uj = new OnlineEsemeny(datum, idopont, nev, helyszin, leiras, tipus);
            }
            else if (strcmp(tipusC, "napi") == 0 || strcmp(tipusC, "heti") == 0 || strcmp(tipusC, "havi") == 0) {
                uj = new VisszateroEsemeny(datum, idopont, nev, helyszin, leiras, tipus);
            }
            else if (strcmp(tipusC, "magas") == 0 || strcmp(tipusC, "alacsony") == 0) {
                std::cout << "Fontos létrehozva";
                uj = new FontosEsemeny(datum, idopont, nev, helyszin, leiras, tipus);
            }
            else {
                cout << "Ismeretlen tipus. Alapertelmezett esemenykent mentve.\n";
                uj = new Esemeny(datum, idopont, nev, helyszin, leiras);
            }
        }
        else {
            uj = new Esemeny(datum, idopont, nev, helyszin, leiras);
        }

        beleteszEsemeny(uj);
        cout << "Esemeny sikeresen hozzaadva!\n";
        break;
    }
}

void EsemenyKezelo::keresEsemeny() const {
    std::cout << "Add meg a keresett esemeny nevet vagy annak egy reszletet: ";
    String keresett;
    std::cin >> keresett;

    bool talalat = false;

    for (size_t i = 0; i < meret; ++i) {
        Esemeny* e = esemenyek[i];
        if (e != nullptr) {
            if (e->getNev().tartalmaz(keresett)) {  
                e->kiir();
                std::cout << "--------------------------\n";
                talalat = true;
            }
        }
    }

    if (!talalat) {
        std::cout << "Nincs talalat a megadott kifejezesre.\n";
    }
}


void EsemenyKezelo::modositEsemeny() {
    std::cout << "Add meg a modositani kivant esemeny datumat (YYYY-MM-DD): ";
    String regiDatum;
    std::cin >> regiDatum;
    std::cin.ignore();

    std::cout << "Add meg a modositani kivant esemeny nevet: ";
    String regiNev;
    regiNev.beolvas(std::cin);

    bool talalt = false;
    for (size_t i = 0; i < meret; ++i) {
        if (esemenyek[i] != nullptr &&
            esemenyek[i]->getDatum() == regiDatum &&
            esemenyek[i]->getNev() == regiNev) {

            
            String ujDatum, ujIdopont, ujNev, ujHelyszin, ujMegjegyzes;

            std::cout << "Add meg az uj datumot (YYYY-MM-DD): ";
            std::cin >> ujDatum;

            std::cout << "Add meg az uj idopontot (HH:MM): ";
            std::cin >> ujIdopont;
            std::cin.ignore();

            std::cout << "Add meg az uj nevet: ";
            ujNev.beolvas(std::cin);

            std::cout << "Add meg az uj helyszint: ";
            ujHelyszin.beolvas(std::cin);

            std::cout << "Add meg az uj megjegyzest: ";
            ujMegjegyzes.beolvas(std::cin);

            
            Ellenorzo ellenorzo;
            if (!ellenorzo.ervenyesDatum(ujDatum) ||
                !ellenorzo.ervenyesIdopont(ujIdopont) ||
                !ellenorzo.ervenyesNev(ujNev)) {
                std::cout << "Ervenytelen adat(ok)! A modositas megszakitva.\n";
                return;
            }

            
            if (dynamic_cast<FontosEsemeny*>(esemenyek[i])) {
                FontosEsemeny* fontos = dynamic_cast<FontosEsemeny*>(esemenyek[i]);
                String ujPrioritas;
                std::cout << "Add meg az uj prioritast(magas/alacsony): ";
                std::cin >> ujPrioritas;
                fontos->setPrioritas(ujPrioritas);
            }
            else if (dynamic_cast<OnlineEsemeny*>(esemenyek[i])) {
                OnlineEsemeny* online = dynamic_cast<OnlineEsemeny*>(esemenyek[i]);
                String ujUrl;
                std::cout << "Add meg az uj URL-t(https:):";
                std::cin >> ujUrl;
                online->setUrl(ujUrl);
            }
            else if (dynamic_cast<VisszateroEsemeny*>(esemenyek[i])) {
                VisszateroEsemeny* visszatero = dynamic_cast<VisszateroEsemeny*>(esemenyek[i]);
                String ujGyakorisag;
                std::cout << "Add meg az uj gyakorisagot(havi/heti/napi): ";
                std::cin >> ujGyakorisag;
                visszatero->setGyakorisag(ujGyakorisag);
            }

            
            esemenyek[i]->setDatum(ujDatum);
            esemenyek[i]->setIdopont(ujIdopont);
            esemenyek[i]->setNev(ujNev);
            esemenyek[i]->setHelyszin(ujHelyszin);
            esemenyek[i]->setMegjegyzes(ujMegjegyzes);

            talalt = true;
            std::cout << "Esemény sikeresen modositva.\n";
            break;
        }
    }

    if (!talalt) {
        std::cout << "Nem talaltam az adott datumu es nevu esemenyt.\n";
    }
}

void EsemenyKezelo::torolEsemeny() {
    std::cout << "Add meg a torolni kivant esemény datumat (YYYY-MM-DD): ";
    String datum;
    std::cin >> datum;
    std::cin.ignore();

    std::cout << "Add meg a torolni kivant esemeny nevet: ";
    String nev;
    nev.beolvas(std::cin);

    bool talalt = false;
    for (size_t i = 0; i < meret; ++i) {
        if (esemenyek[i] != nullptr) {
            if (esemenyek[i]->getDatum() == datum && esemenyek[i]->getNev() == nev) {
                delete esemenyek[i];
                esemenyek[i] = nullptr;
                talalt = true;
                std::cout << "Esemeny torolve.\n";
                break;  
            }
        }
    }
    if (!talalt) {
        std::cout << "Nem talaltam az adott datumu és nevu esemenyt.\n";
    }
}

EsemenyKezelo::~EsemenyKezelo() {
    for (size_t i = 0; i < meret; ++i) {
        if (esemenyek[i] != nullptr) {  
            delete esemenyek[i];
            esemenyek[i] = nullptr;    
        }
    }
    delete[] esemenyek;
}