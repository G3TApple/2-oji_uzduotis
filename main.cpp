#include "mylib.h"
#include "file_functions.h"

size_t paz_skaicius;

int main()
{
    int uzkl_1 = -1, uzkl_2 = -1, uzkl_3 = -1, uzkl_4 = -1, uzkl_5 = -1;
    vector<Studentas> grupe;
    Studentas temp;
    double visa_trukme = 0;
    cout << "Ar norite: \n 1. Ivesti vardus ir pazymius (iveskite '1')\n 2. Generuoti vardus ir pazymius atsitiktinai (iveskite '2')\n 3. Skaityti vardus ir pazymius is failo (iveskite '3')\n";
    int_input_check(uzkl_1,(vector<int>){1, 2, 3});
    cout << "\nAr norite:\n 1. Skaiciuoti vidurki (iveskite '1')\n 2. Skaiciuoti mediana (iveskite '2')\n 3. Skaiciuoti mediana ir vidurki (iveskite '3')\n 4. Spausdinti pazymius (iveskite '4')\n";
    int_input_check(uzkl_2,(vector<int>){1, 2, 3, 4});
    if(uzkl_1 == 2){        /// Jei generuojami pazymiai - ar isvesti i ekrana, ar i faila
        cout << "\nAr norite: \n 1. Isvesti pazymius i ekrana (iveskite '1')\n 2. Isvesti rezultata i faila (iveskite '2')\n";
        int_input_check(uzkl_3,(vector<int>){1, 2});
    }
    if(uzkl_1 == 3 || uzkl_3 == 2){
        cout << "\nAr norite skirstyti studentus i mokslincius ir tinginius? Iveskite '1', jei taip, '0', jei ne.\n";
        int_input_check(uzkl_5,(vector<int>){1, 0});
    }
    switch(uzkl_1){
    case 1:
        stud_ivest(grupe,temp,uzkl_2);
        break;
    case 3:
        visa_trukme += failo_nuskaitymas(grupe,uzkl_2);
        break;
    default: /// jeigu uzkl_1 = 2,4 arba 5
        visa_trukme += stud_gen(grupe,temp,uzkl_2);
        break;
    }
    if(uzkl_1 != 3 && uzkl_3 != 2){    /// Jei rezultatai rasomi ne i faila
        cout<<endl<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
        switch(uzkl_2){
        case 1:
            cout<<setw(15)<<"Galutinis (Vid.)"<<endl;
            break;
        case 2:
            cout<<setw(15)<<"Galutinis (Med.)"<<endl;
            break;
        case 3:
            cout<<setw(15)<<"Galutinis (Vid. / Med.)"<<endl;
            break;
        case 4:
            cout<<setw(15)<<"Pazymiai"<<endl;
            break;
        }
        cout<<"---------------------------------------------------"<<endl;
        for(const auto &i:grupe)
            spausd(i,uzkl_2,uzkl_1);
        if(uzkl_2 != 4){    /// Jei pazymiai dar nebuvo spausdinti
            cout << "\nAr norite spausdinti pazymius? (jei taip - iveskite '4', jei ne - '0')";
            int_input_check(uzkl_4,(vector<int>){4, 0});
            if(uzkl_4 == 4)
                for(const auto &i:grupe)
                    spausd(i,uzkl_4,uzkl_1);
        }
    } else {
        if(uzkl_5 == 0){
            Timer print;
            spausd_i_faila(grupe,uzkl_1,uzkl_2,"studentai"+to_string(grupe.size())+".txt");
            cout << "Studentu duomenu spausdinimas i faila uztruko: " << print.elapsed() << "s\n";
            visa_trukme += print.elapsed();
        }
        else {
            vector<Studentas> tinginiai;
            tinginiai.reserve(1000000);
            Timer rusiavimas;
            ting_moksl(grupe,tinginiai,uzkl_2);
            cout << "Studentu rusiavimas i dvi grupes truko: "<< rusiavimas.elapsed() << "s\n";
            visa_trukme += rusiavimas.elapsed();
            Timer rus_spausd;
            spausd_i_faila(tinginiai,uzkl_1,uzkl_2,"output_tinginiai.txt");
            spausd_i_faila(grupe,uzkl_1,uzkl_2,"output_mokslinciai.txt");
            cout << "Surusiuotu studentu isvedimas i du failus uztruko: " << rus_spausd.elapsed() << "s\n";
            visa_trukme += rus_spausd.elapsed();
        }
    }
    for(auto &i:grupe) i.paz.clear();
    grupe.clear();
    cout << "Visas programos darbas truko: "<< visa_trukme << "s\n";
    return 0;
}
