# Határidőnapló

Ez egy menüvezérelt határidőnapló alkalmazás, amely lehetővé teszi a felhasználó számára az események pontos rögzítését, kezelését és keresését egyértelmű és rendezett módon. 

---

## 📋 Funkciók

A program egy interaktív, menüvezérelt felhasználói felületet biztosít, az alábbi lehetőségekkel:
* **Új esemény hozzáadása:** Adatok bekérése lépésenként, formátum-ellenőrzéssel.
* **Kilistázás:** A listában tárolt adatok kiírása a kimenetre.
* **Esemény keresése:** Keresés név (kulcsszó) alapján, az eredmények időrendi sorrendben jelennek meg.
* **Esemény módosítása:** Meglévő rekordok adatainak frissítése.
* **Esemény törlése:** Végleges, vissza nem vonható törlés egyedi azonosító (dátum és név) alapján.
* **Mentés adatbázis fájlba:** A jelenlegi rekordok exportálása külső fájlba.

---

## 💾 Adatmodell és Formátumok

Az események rekordokban tárolódnak az alábbi szerkezet szerint:

| Mező neve | Kötelező? | Formátum / Megengedett értékek | Leírás |
| :--- | :---: | :--- | :--- |
| **Dátum** | Igen | `ÉÉÉÉ-HH-NN` (pl. 2025-11-08) | Az esemény dátuma |
| **Időpont** | Igen | `OO:PP` (24 órás, pl. 18:30) | Az esemény időpontja |
| **Esemény neve** | Igen | Szabad szöveg | Az esemény neve (dátummal együtt egyedi azonosító) |
| **Helyszín** | Nem | Szabad szöveg | Az esemény helyszíne |
| **Megjegyzés** | Nem | Szabad szöveg | Kiegészítő információ az eseményhez |
| **URL (URI)** | Nem | Érvényes webcím (https/) | Kapcsolódó link |
| **Gyakoriság** | Nem | `napi` / `heti` / `havi` | Az esemény ismétlődése |
| **Prioritás** | Nem | `magas` / `alacsony` | Az esemény fontossági szintje |

### Fájlkezelés (I/O)
* **Adatmegosztás:** Az adatok bemeneten és kimeneten is kettősponttal (`:`) vannak elválasztva és tagolva (pl. `Datum:Idopont:Esemeny neve...`).
* **Import/Export:** A program képes bemeneti fájlból vagy interaktív menüből is dolgozni. A kimenet szabványos formátumú, így `.csv` (adatbázis) fájlba irányítható.
* **Validáció:** Ha a bemeneti fájl valamelyik sorából hiányoznak a kötelező adatok (dátum, név), a program azt a sort nem olvassa be.

---

## 🛠️ Hibakezelés és Működés

* **Robusztusság:** Helytelen adatbevitel (pl. hibás dátumformátum) esetén a program figyelmeztetést küld és új adatot kér be.
* **Adatbiztonság:** Hiányzó kötelező mezők esetén a rendszer automatikusan letiltja a mentést.
* **Visszajelzések:** Nem létező esemény keresése vagy törlése esetén hibaüzenetet kap a felhasználó. A futás során minden funkció azonnali visszajelzést biztosít a főmenüben a kilépésig.

---

### Készítette
* **Sziklai Milán**
