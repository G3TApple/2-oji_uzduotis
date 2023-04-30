#include "mylib.h"
#include "file_functions.h"

size_t paz_skaicius;

int main()
{
    //int uzkl_1 = -1, uzkl_2 = -1, uzkl_3 = -1, uzkl_4 = -1, uzkl_5 = -1, uzkl_6 = -1;
    vector<Studentas> grupe;
    Studentas temp;
    double visa_trukme = 0;
    /*cout << "Ar norite: \n 1. Ivesti vardus ir pazymius (iveskite '1')\n 2. Generuoti vardus ir pazymius atsitiktinai (iveskite '2')\n 3. Skaityti vardus ir pazymius is failo (iveskite '3')\n";
    int_input_check(uzkl_1,(vector<int>){1, 2, 3});
    cout << "\nAr norite:\n 1. Skaiciuoti vidurki (iveskite '1')\n 2. Skaiciuoti mediana (iveskite '2')\n 3. Skaiciuoti mediana ir vidurki (iveskite '3')\n 4. Spausdinti pazymius (iveskite '4')\n";
    int_input_check(uzkl_2,(vector<int>){1, 2, 3, 4});
    if(uzkl_1 == 2){        /// Jei generuojami pazymiai - ar isvesti i ekrana, ar i faila
        cout << "\nAr norite: \n 1. Isvesti pazymius i ekrana (iveskite '1')\n 2. Isvesti rezultata i faila (iveskite '2')\n";
        int_input_check(uzkl_3,(vector<int>){1, 2});
    }
    if(uzkl_1 == 3 || uzkl_3 == 2){     /// Jei studentai skaitomi arba generuojami
        cout << "\nAr norite skirstyti studentus i mokslincius ir tinginius? Iveskite '1', jei taip, '0', jei ne.\n";
        int_input_check(uzkl_5,(vector<int>){1, 0});
    }
    if(uzkl_5 == 1){
        cout << "\nIveskite '1', jei norite naudoti 1 strategija (du nauji konteineriai) arba '2', jei norite naudoti 2 strategija (vienas naujas konteineris).\n";
        int_input_check(uzkl_6,(vector<int>){1, 2});
    }
    switch(uzkl_1){
    case 1:
        stud_ivest(grupe,temp,uzkl_2);
        break;
    case 3:
        visa_trukme += failo_nuskaitymas(grupe,uzkl_2);
        break;
    default:
        visa_trukme += stud_gen(grupe,temp,uzkl_2);
        break;
    }
    if(uzkl_1 != 3 && uzkl_3 != 2)   /// Jei rezultatai rasomi ne i faila
        isvedimas_i_ekrana(grupe,uzkl_4,uzkl_2,uzkl_1);
    else {
        if(uzkl_5 == 0){ /// Jei studentai neskirstomi i mokslincius ir tinginius
            Timer print;
            if(uzkl_2 == 4) /// Jeigu generuojami studentu pazymiai velesniam naudojimui
                spausd_i_faila(grupe,uzkl_1,uzkl_2,"studentai"+to_string(grupe.size())+".txt");
            else
                spausd_i_faila(grupe,uzkl_1,uzkl_2,"output.txt");
            cout << "Studentu duomenu spausdinimas i faila uztruko: " << print.elapsed() << "s\n";
            visa_trukme += print.elapsed();
        }
        else
            skirstymas(uzkl_6,uzkl_2,uzkl_1,grupe,visa_trukme);
    }
    */

    visa_trukme += failo_nuskaitymas(grupe,1);
    Timer print;
    spausd_i_faila(grupe,3,1,"output.txt");
    visa_trukme += print.elapsed();

    cout << "Visas programos darbas truko: "<< visa_trukme << "s\n";
    system("pause");
}
