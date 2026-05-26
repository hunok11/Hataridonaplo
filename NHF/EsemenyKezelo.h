#ifndef ESEMENYKEZELO_H
#define ESEMENYKEZELO_H

#include "Esemeny.h"
#include "string5.h"


class EsemenyKezelo {
private:
    Esemeny** esemenyek;
    size_t meret;
    size_t kapacitas;
    void bovitKapacitast();

public:
    EsemenyKezelo(size_t kezdoKapacitas=10);
    ~EsemenyKezelo();

    void beleteszEsemeny(Esemeny* e);
    void hozzaadEsemeny();
    void modositEsemeny();
    void torolEsemeny();
    void listazEsemenyek() const;
    void keresEsemeny() const;
    Esemeny** getEsemenyek() { return esemenyek; }
    int getMeret() const { return (int)meret; }
};

#endif
