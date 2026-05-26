#include "FontosEsemeny.h"
#include <iostream>

FontosEsemeny::FontosEsemeny(const String& datum, const String& idopont, const String& nev,
    const String& helyszin, const String& megjegyzes, const String& prioritas)
    : Esemeny(datum, idopont, nev, helyszin, megjegyzes), prioritas(prioritas) {
}

void FontosEsemeny::kiir() const {
    Esemeny::kiir();
    std::cout << "Fontossag: " << prioritas << "\n";
}

const String& FontosEsemeny::getPrioritas() const { return prioritas; }

void FontosEsemeny::setPrioritas(const String& ujPrioritas) { prioritas = ujPrioritas; }

FontosEsemeny::~FontosEsemeny() {}
