#ifndef VISSZATEROESEMENY_H
#define VISSZATEROESEMENY_H

#include "Esemeny.h"
class VisszateroEsemeny : public Esemeny {
private:
    String gyakorisag;

public:
    VisszateroEsemeny(const String& datum, const String& idopont, const String& nev,
        const String& helyszin, const String& megjegyzes, const String& gyakorisag);
    
    const String& getGyakorisag() const;

    void setGyakorisag(const String& ujGyakorisag);

    void kiir() const override;
    ~VisszateroEsemeny();
};

#endif
