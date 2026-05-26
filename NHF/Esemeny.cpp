#include "Esemeny.h"
#include <iostream>
using namespace std;

Esemeny::Esemeny(const String& datum, const String& idopont, const String& nev,
    const String& helyszin, const String& megjegyzes)
    : datum(datum), idopont(idopont), nev(nev), helyszin(helyszin), megjegyzes(megjegyzes) {
}

void Esemeny::kiir() const {
    cout << "Datum: " << datum << '\n'
        << "Idopont: " << idopont << '\n'
        << "Nev: " << nev << '\n'
        << "Helyszin: " << helyszin << '\n'
        << "Megjegyzes: " << megjegyzes << endl;
}

const String& Esemeny::getDatum() const { return datum; }
const String& Esemeny::getIdopont()const { return idopont; }
const String& Esemeny::getNev() const { return nev; }
const String& Esemeny::getHelyszin() const { return helyszin; }
const String& Esemeny::getMegjegyzes() const { return megjegyzes; }

void Esemeny::setDatum(const String& ujDatum) { datum = ujDatum; }
void Esemeny::setIdopont(const String& ujIdopont) { idopont = ujIdopont; }
void Esemeny::setNev(const String& ujNev) { nev = ujNev; }
void Esemeny::setHelyszin(const String& ujHelyszin) { helyszin = ujHelyszin; }
void Esemeny::setMegjegyzes(const String& ujMegjegyzes) { megjegyzes = ujMegjegyzes; }

Esemeny::~Esemeny() {}

