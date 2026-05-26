#ifndef ONLINEESEMENY_H
#define ONLINEESEMENY_H

#include "Esemeny.h"

class OnlineEsemeny : public Esemeny {
private:
    String url;

public:
    OnlineEsemeny(const String& datum, const String& idopont, const String& nev,
        const String& helyszin, const String& megjegyzes, const String& url);

    const String& getUrl() const;

    void setUrl(const String& ujUrl);

    void kiir() const override;
    ~OnlineEsemeny();
};

#endif
