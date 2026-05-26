# Határidőnapló

[cite_start]Ez egy menüvezérelt határidőnapló alkalmazás, amely lehetővez teszi a felhasználó számára az események pontos rögzítését, kezelését és keresését egyértelmű és rendezett módon[cite: 2, 5, 17]. 

---

## 📋 Funkciók

[cite_start]A program egy interaktív, menüvezérelt felhasználói felületet biztosít, az alábbi lehetőségekkel[cite: 17, 18]:
* [cite_start]**Új esemény hozzáadása:** Adatok bekérése lépésenként, formátum-ellenőrzéssel[cite: 27, 28, 29].
* [cite_start]**Kilistázás:** A listában tárolt adatok kiírása a kimenetre[cite: 26].
* [cite_start]**Esemény keresése:** Keresés név (kulcsszó) alapján, az eredmények időrendi sorrendben jelennek meg[cite: 32, 33, 34].
* [cite_start]**Esemény módosítása:** Meglévő rekordok adatainak frissítése[cite: 21].
* [cite_start]**Esemény törlése:** Végleges, vissza nem vonható törlés egyedi azonosító (dátum és név) alapján[cite: 30, 31].
* [cite_start]**Mentés adatbázis fájlba:** A jelenlegi rekordok exportálása külső fájlba[cite: 35, 36].

---

## 💾 Adatmodell és Formátumok

[cite_start]Az események rekordokban tárolódnak az alábbi szerkezet szerint[cite: 4]:

| Mező neve | Kötelező? | Formátum / Megengedett értékek | Leírás |
| :--- | :---: | :--- | :--- |
| **Dátum** | Igen | `ÉÉÉÉ-HH-NN` (pl. 2025-11-08) | [cite_start]Az esemény dátuma [cite: 51] |
| **Időpont** | Igen | `OO:PP` (24 órás, pl. 18:30) | [cite_start]Az esemény időpontja [cite: 51] |
| **Esemény neve** | Igen | Szabad szöveg | [cite_start]Az esemény neve (dátummal együtt egyedi azonosító) [cite: 51] |
| **Helyszín** | Nem | Szabad szöveg | [cite_start]Az esemény helyszíne [cite: 51] |
| **Megjegyzés** | Nem | Szabad szöveg | [cite_start]Kiegészítő információ az eseményhez [cite: 51] |
| **URL (URI)** | Nem | Érvényes webcím (https/) | [cite_start]Kapcsolódó link [cite: 13, 51] |
| **Gyakoriság** | Nem | `napi` / `heti` / `havi` | [cite_start]Az esemény ismétlődése [cite: 51] |
| **Prioritás** | Nem | `magas` / `alacsony` | [cite_start]Az esemény fontossági szintje [cite: 51] |

### Fájlkezelés (I/O)
* [cite_start]**Adatmegosztás:** Az adatok bemeneten és kimeneten is kettősponttal (`:`) vannak elválasztva és tagolva (pl. `Datum:Idopont:Esemeny neve...`)[cite: 41].
* [cite_start]**Import/Export:** A program képes bemeneti fájlból vagy interaktív menüből is dolgozni[cite: 38]. [cite_start]A kimenet szabványos formátumú, így `.csv` (adatbázis) fájlba irányítható[cite: 40].
* [cite_start]**Validáció:** Ha a bemeneti fájl valamelyik sorából hiányoznak a kötelező adatok (dátum, név), a program azt a sort nem olvassa be[cite: 39].

---

## 🛠️ Hibakezelés és Működés

* [cite_start]**Robusztusság:** Helytelen adatbevitel (pl. hibás dátumformátum) esetén a program figyelmeztetést küld és új adatot kér be[cite: 43].
* [cite_start]**Adatbiztonság:** Hiányzó kötelező mezők esetén a rendszer automatikusan letiltja a mentést[cite: 44].
* [cite_start]**Visszajelzések:** Nem létező esemény keresése vagy törlése esetén hibaüzenetet kap a felhasználó[cite: 45]. [cite_start]A futás során minden funkció azonnali visszajelzést biztosít a főmenüben a kilépésig[cite: 47, 48, 49].

---

### Készítette
* [cite_start]**Sziklai Milán** [cite: 54]
