# Objektinio programavimo laboratorinis darbas - 1-oji užduotis.

### **Programa, skirta studentų galutinio balo skaičiavimui.**

- Programa leidžia pasirinkti įvesti duomenis vartotojui, duomenis generuoti automatiškai arba nuskaityti duomenis iš failo. Toliau galima pasirinkti generuoti vidurkį, medianą, vidurkį ir medianą arba spausdinti visus pažymius (tik įvedant arba generuojant duomenis).

**Duomenų įvedimas ranka:**
1. Vartotojas turi įvesti didžiausią įmanomą pažymių skaičių. 
2. Toliau programa prašo įvesti studento vardą ir pavardę bei gautus pažymius. Norint nutraukti pažymių vedimą, neįvedus maksimalaus pažymių skaičiaus, galima įvesti bet kokį simbolį vietoj pažymio. Tuomet išsaugota bus tik tiek pažymių, kiek įvedė vartotojas. Įvedus pažymius prašoma įvesti egzamino pažymį.
3. Galima pasirinkti - vesti dar vieno studento duomenis arba baigti įvedimą.
4. Baigus įvedimą, į ekraną išvedamas galutinis balas. 
5. Po išvedimo suteikiamas pasirinkimas papildomai išvesti ir visus pažymius, jei jie dar nebuvo išvesti.

<br>**Duomenų generavimas:**
1. Vartotojas turi įvesti, kiek studentų nori generuoti. Toliau turi įvesti, kiek daugiausia pažymių nori skirti kiekvienam studentui.
2. Baigus įvedimą, programa išveda sugeneruotus vardus, pavardes bei pažymius arba galutinius pažymius.
3. Po išvedimo suteikiamas pasirinkimas papildomai išvesti ir visus pažymius, jei jie dar nebuvo išvesti.

<br>**Duomenų nuskaitymas iš failo**
1. Vartotojui parodomi pasiekiami tekstiniai failai. Pasirinkęs norimą vartotojas turi įvesti jo pavadinimą.
2. Nuskaitant duomenis iš failo automatiškai suskaičiuojama, kiek pažymių gavo studentai, jei duomenų failas suformatuotas teisingai.
3. Baigus įvedimą, programa į failą išveda sugeneruotus vardus, pavardes bei pažymius arba galutinius pažymius.
4. Po išvedimo suteikiamas pasirinkimas papildomai išvesti ir visus pažymius, jei jie dar nebuvo išvesti.



- Visada, kai vartotojui leidžiama įvesti duomenis, juos įvedus programa tikrina, ar duomenys teisingi. Jei ne - pateikia atitinkamą pranešimą.



### Formulė galutinio pažymio skaičiavimui: <br>
![image](https://user-images.githubusercontent.com/116343289/221124441-e0c14ec4-e460-4933-825f-db93016aa331.png)

### Programos veikimo nuotrauka (v0.1): 
![image](https://user-images.githubusercontent.com/116343289/221123906-367b75ab-b0f9-49ac-924d-c2dc56dcebd6.png)

### Programos generavimo spartos lentelė (naudojant _vector_): <br>
|                  **Studentų kiekis** | **1.000** | **10.000** | **100.000** | **1.000.000** | **10.000.000** |
|-------------------------------------:|-----------|------------|-------------|---------------|----------------|
| _Duomenų generavimas (laikas, s)_    | 0,002     | 0,006      | 0,056       | 0,484         | 5,229          |
| _Spausdinimas į failą (laikas, s)_   | 0,003     | 0,013      | 0,112       | 1,082         | 10,332         |
| _Visas programos darbas (laikas, s)_ | 0,005     | 0,019      | 0,168       | 1,566         | 15.561         |


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


Naudojamo kompiuterio specifikacijos:
- CPU: AMD Ryzen 7 2700X 3.70 GHz 8c/16t
- RAM: Corsair 2x8GB DDR4 3200MHz
- Storage: Samsung 970 EVO Plus SSD 500GB NVMe M.2 (read/write - 3,500/3,300 MB/s)
