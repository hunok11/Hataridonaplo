
#include "Ellenorzo.h"

bool Ellenorzo::ervenyesDatum(const String& datum) {
    if (datum.size() != 10) return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (datum[i] != '-') return false;
        }
        else {
            if (datum[i] < '0' || datum[i] > '9') return false;
        }
    }

    int honap = (datum[5] - '0') * 10 + (datum[6] - '0');
    int nap = (datum[8] - '0') * 10 + (datum[9] - '0');

    if (honap < 1 || honap > 12) return false;
    if (nap < 1 || nap > 31) return false;

    return true;
}
bool Ellenorzo::ervenyesIdopont(const String& idopont) {
    if (idopont.size() != 5) return false;

    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            if (idopont[i] != ':') return false;
        }
        else {
            if (idopont[i] < '0' || idopont[i] > '9') return false;
        }
    }

    int ora = (idopont[0] - '0') * 10 + (idopont[1] - '0');
    int perc = (idopont[3] - '0') * 10 + (idopont[4] - '0');

    if (ora < 0 || ora > 23) return false;
    if (perc < 0 || perc > 59) return false;

    return true;
}
bool Ellenorzo::ervenyesNev(const String& nev) {
    if (nev.size() == 0) return false;
    return true;
}
bool Ellenorzo::csakSzamjegyek(const String& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}
bool Ellenorzo::ervenyesMenuPont(const String& input, int& menuPont) {
    if (!csakSzamjegyek(input) || input.size() == 0) {
        return false;
    }

    menuPont = 0;
    for (size_t i = 0; i < input.size(); ++i) {
        menuPont = menuPont * 10 + (input[i] - '0');
    }
    return (menuPont >= 1 && menuPont <= 7);
}