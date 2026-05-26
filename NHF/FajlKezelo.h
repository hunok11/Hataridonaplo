#ifndef FAJLKEZELO_H
#define FAJLKEZELO_H

#include "Esemeny.h"
#include "OnlineEsemeny.h"
#include "VisszateroEsemeny.h"
#include "FontosEsemeny.h"
#include "Ellenorzo.h"
class FajlKezelo {
public:
    static void mentesFajlba(Esemeny** esemenyek, int meret);
    static Esemeny** beolvasFajlbol(char* fajlNev);
};

#endif
