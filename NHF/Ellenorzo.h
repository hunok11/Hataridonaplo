#ifndef ELLENORZO_H
#define ELLENORZO_H
#include "string5.h"

class Ellenorzo {
public:
    static bool ervenyesDatum(const String& datum);
    static bool ervenyesIdopont(const String& idopont);
    static bool ervenyesNev(const String& nev);
    static bool csakSzamjegyek(const String& str);
    static bool ervenyesMenuPont(const String& input, int& menuPont);
};

#endif
