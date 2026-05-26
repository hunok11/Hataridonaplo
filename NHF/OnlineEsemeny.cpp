#include "OnlineEsemeny.h"
#include <iostream>

OnlineEsemeny::OnlineEsemeny(const String& datum, const String& idopont, const String& nev,
    const String& helyszin, const String& megjegyzes, const String& url)
    : Esemeny(datum, idopont, nev, helyszin, megjegyzes), url(url) {
}

void OnlineEsemeny::kiir() const {
    Esemeny::kiir();
    std::cout << "Csatlakozasi link: " << url << "\n";
}
const String& OnlineEsemeny::getUrl()const { return url; }

void OnlineEsemeny::setUrl(const String& ujUrl) { url = ujUrl; }

OnlineEsemeny::~OnlineEsemeny() {}
