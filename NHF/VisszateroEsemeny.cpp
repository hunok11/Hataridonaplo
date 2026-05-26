#include "VisszateroEsemeny.h"
#include <iostream>

VisszateroEsemeny::VisszateroEsemeny(const String& datum, const String& idopont, const String& nev,
    const String& helyszin, const String& megjegyzes, const String& gyakorisag)
    : Esemeny(datum, idopont, nev, helyszin, megjegyzes), gyakorisag(gyakorisag) {
}

void VisszateroEsemeny::kiir() const {
    Esemeny::kiir();
    std::cout << "Rendszeresseg: " << gyakorisag << "\n";
}
const String& VisszateroEsemeny::getGyakorisag()const { return gyakorisag; }

void VisszateroEsemeny::setGyakorisag(const String& ujGyakorisag) { gyakorisag = ujGyakorisag; }

VisszateroEsemeny::~VisszateroEsemeny() {}