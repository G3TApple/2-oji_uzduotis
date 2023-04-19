# Objektinio programavimo laboratorinis darbas - 1-oji užduotis.

### **Programa, skirta studentų galutinio balo skaičiavimui.**

**Duomenų įvedimas ranka:**
1. Įveskite didžiausią įmanomą pažymių skaičių. 
2. Toliau įveskite studento vardą ir pavardę bei gautus pažymius. Norėdami nutraukti pažymių vedimą, įveskite bet kokį simbolį vietoj pažymio. Tuomet išsaugota bus tik tiek pažymių, kiek įvedėte. Įvedus pažymius prašoma įvesti egzamino pažymį.
3. Galima pasirinkti - vesti dar vieno studento duomenis arba baigti įvedimą.
4. Baigus įvedimą, į ekraną išvedamas galutinis balas. 
5. Po išvedimo suteikiamas pasirinkimas papildomai išvesti ir visus pažymius, jei jie dar nebuvo išvesti.

<br>**Duomenų generavimas:**
1. Pasirinkite - skaičiuoti vidurkį, medianą, abu ar spausdinti pažymius.
2. Tada pasirinkite, ar norite išvesti rezultatus į ekraną, ar į failą
3. Toliau pasirinkite, ar norite skirstyti studentus į mokslinčius ir tinginius, ar ne. Pasirinkę „Taip“ galite rinktis iš dviejų skirstymo strategijų.
4. Įveskite, kiek studentų norite generuoti. Vėliau įveskite, kiek daugiausia pažymių norite skirti kiekvienam studentui.
5. Baigus įvedimą, programa išveda sugeneruotus vardus, pavardes bei pažymius arba galutinius pažymius.

<br>**Duomenų nuskaitymas iš failo**
1. Pasirinkite - skaičiuoti vidurkį, medianą, abu ar spausdinti pažymius.
2. Tada pasirinkite, ar skirstyti studentus į mokslinčius ir tinginius, ar ne. Pasirinkę „Taip“ galite rinktis iš dviejų skirstymo strategijų.
3. Parodomi pasiekiami tekstiniai failai - pasirinkę norimą turite įvesti jo pavadinimą (nuskaitant duomenis iš failo automatiškai suskaičiuojama, kiek pažymių gavo studentai, jei duomenų failas suformatuotas teisingai).
4. Programa į failą išveda sugeneruotus vardus, pavardes bei pažymius arba galutinius pažymius.


- Visada, kai vartotojui leidžiama įvesti duomenis, juos įvedus programa tikrina, ar duomenys teisingi. Jei ne - pateikia atitinkamą pranešimą.



### Formulė galutinio pažymio skaičiavimui: <br>
![image](https://user-images.githubusercontent.com/116343289/221124441-e0c14ec4-e460-4933-825f-db93016aa331.png)

### Programos veikimo nuotrauka (v0.1): 
![image](https://user-images.githubusercontent.com/116343289/221123906-367b75ab-b0f9-49ac-924d-c2dc56dcebd6.png)

### Studentų generavimo spartos lentelė (naudojant _vector_): <br>
|                  **Studentų kiekis** | **1.000** | **10.000** | **100.000** | **1.000.000** | **10.000.000** |
|-------------------------------------:|-----------|------------|-------------|---------------|----------------|
| _Duomenų generavimas (laikas, s)_    | 0,002     | 0,006      | 0,056       | 0,484         | 5,229          |
| _Spausdinimas į failą (laikas, s)_   | 0,003     | 0,013      | 0,112       | 1,082         | 10,332         |
| _Visas programos darbas (laikas, s)_ | 0,005     | 0,019      | 0,168       | 1,566         | 15.561         |

---
### Duomenų skaitymo spartos lentelė (naudojant _vector_): <br>
|                               **Studentų kiekis** | **1.000** | **10.000** | **100.000** | **1.000.000** | **10.000.000** |
|--------------------------------------------------:|-----------|------------|-------------|---------------|----------------|
| _Skaitymas iš failo (laikas, s)_                  | 0.004     | 0.031      | 0.296       | 2.950         | 30.730         |
| _Studentų rūšiavimas didėjimo tvarka (laikas, s)_ | 0.001     | 0.003      | 0.027       | 0.325         | 3.745         |
| _Studentų rūšiavimas į dvi grupes (laikas, s)_    | 0.001     | 0.003      | 0.035       | 0.429         | 5.035         |
| _Visas konteinerių darbas (laikas, s)_ 	        | 0.006     | 0.037      | 0.358       | 3.704         | 39.51         |

### Duomenų skaitymo spartos lentelė (naudojant _list_): <br>
|                               **Studentų kiekis** | **1.000** | **10.000** | **100.000** | **1.000.000** | **10.000.000** |
|--------------------------------------------------:|-----------|------------|-------------|---------------|----------------|
| _Skaitymas iš failo (laikas, s)_                  | 0.005     | 0.048      | 0.434       | 4.440         | 44.013         |
| _Studentų rūšiavimas didėjimo tvarka (laikas, s)_ | 0.001     | 0.003      | 0.046       | 0.781         | 11.736         |
| _Studentų rūšiavimas į dvi grupes (laikas, s)_    | 0.001     | 0.002      | 0.029       | 0.556         | 9.938          |
| _Visas konteinerių darbas (laikas, s)_ 	        | 0.007     | 0.053      | 0.509       | 5.777         | 65.687         |

### Duomenų skaitymo spartos lentelė (naudojant _deque_): <br>
|                               **Studentų kiekis** | **1.000** | **10.000** | **100.000** | **1.000.000** | **10.000.000** |
|--------------------------------------------------:|-----------|------------|-------------|---------------|----------------|
| _Skaitymas iš failo (laikas, s)_                  | 0.005     | 0.037      | 0.360       | 3.488         | 35.975         |
| _Studentų rūšiavimas didėjimo tvarka (laikas, s)_ | 0.001     | 0.005      | 0.067       | 2.438         | 11.276         |
| _Studentų rūšiavimas į dvi grupes (laikas, s)_    | 0.001     | 0.010      | 0.134       | 1.858         | 24.836         |
| _Visas konteinerių darbas (laikas, s)_ 	        | 0.007     | 0.052      | 0.561       | 7.784         | 72.087         |

---
### Programos veikimo spartos lentelė, priklausomai nuo studentų dalijimo strategijos: **(su 1 mln. studentų)** <br>

|          | **1 strategija** | **RAM apkrova** | 	| **2 strategija** | **RAM apkrova** |
|----------|------------------|-----------------|---|------------------|-----------------|
| _Vector_ | 3.98s            | 363MB           | 	| 4.01s            | 175MB           |
| _Deque_  | 6.78s            | 1584MB          | 	| 6.44s            | 926MB           |
| _List_   | 6.15s            | 621MB           | 	| 5.62s            | 523MB           |

### Programos veikimo spartos lentelė, priklausomai nuo studentų dalijimo strategijos: **(su 10 mln. studentų)** <br>

|          | **1 strategija** | **RAM apkrova** | 	| **2 strategija** | **RAM apkrova** |
|----------|------------------|-----------------|---|------------------|-----------------|
| _Vector_ | 51.00s           | 3640MB          | 	| 49.91s           | 2361MB          |
| _Deque_  | 104.763s         | *12062MB\**     | 	| 82.07s           | 9415MB          |
| _List_   | 62.81s           | 4490MB          | 	| 73.11s           | 6193MB          |

*naudojamą atmintį limituoja kompiuteris

Naudojamo kompiuterio specifikacijos:
- CPU: AMD Ryzen 7 2700X 3.70 GHz 8c/16t
- RAM: Corsair 2x8GB DDR4 3200MHz
- Storage: Samsung 970 EVO Plus SSD 500GB NVMe M.2 (read/write - 3,500/3,300 MB/s)

---

## v1.0
- Sukurtos dvi skirstymo į dvi grupes strategijos
- Pašalintos funkcijos, skirtos rikiavimui pagal vidurkį ir medianą
- Nuo šiol su vektoriais naudojami algoritmai: find_if, partition - su jais programa veikia ~5s trumpiau (su 10 mln. studentų failu)
- Nuskaitymas iš failo naudojant stringstream - apie 4s spartesnis (su 10 mln. studentų failu)
- Sukurtas Makefile

## v0.5
- Konteinerių testavimas: vector, deque ir list

## v0.4
- Atlikta programos spartos analizė (lentelė README faile). Spartos matavimui sukurta klasė Timer.
- Nuo dabar sugeneruotus studentų duomenis galima įrašyti į failą. Priklausomai nuo vartotojo pasirinkimo sukuriamas vienas išvesties failas output.txt arba du - output_tinginiai.txt ir output_mokslinciai.txt (pagal kategorijas)
- Visas vartotojo pasirinkimų įvedimas tikrinimas sutrauktas į vieną funkciją, išvengiant pasikartojančio kodo
- Kodo refactoringas

## v0.3

- Pridėtas try/catch metodas, bandant atidaryti neegzistuojantį failą.
- Programos veikimo pabaigoje ištrinami visi vektoriai.

## v0.2

- Galima pasirinkti skaitymą iš failo bei rašymą į failą. Šios funkcijos patalpintos faile file_functions.cpp
- Rezultatai, išrašomi faile yra išrikiuojami abėcėlės tvarka
- Vietoj daugelio if/else naudojamas switch
- Pašalinta masyvų versija

## v0.1

- Pradinė programos versija
