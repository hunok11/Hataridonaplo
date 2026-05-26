#ifndef ESEMENY_H
#define ESEMENY_H

#include <iostream>
#include "string5.h"   

class Esemeny {
protected:
    String datum;
    String idopont;
    String nev;
    String helyszin;
    String megjegyzes;

public:
    Esemeny(const String& datum, const String& idopont, const String& nev, const String& helyszin, const String& megjegyzes);
    const String& getDatum() const;
    const String& getIdopont() const;
    const String& getNev() const;
    const String& getHelyszin() const;
    const String& getMegjegyzes() const;

    void setDatum(const String& ujDatum);
    void setIdopont(const String& ujIdopont);
    void setNev(const String& ujNev);
    void setHelyszin(const String& ujHelyszin);
    void setMegjegyzes(const String& ujMegjegyzes);

    virtual void kiir() const;
    virtual ~Esemeny();
};

#endif

