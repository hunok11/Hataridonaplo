#ifndef FONTOSESEMENY_H
#define FONTOSESEMENY_H

#include "Esemeny.h"
class FontosEsemeny : public Esemeny {
private:
    String prioritas;

public:
    FontosEsemeny(const String& datum, const String& idopont, const String& nev,
        const String& helyszin, const String& megjegyzes, const String& prioritas);

    const String& getPrioritas() const;

    void setPrioritas(const String& ujPrioritas);

    void kiir() const override;
    ~FontosEsemeny();
};

#endif