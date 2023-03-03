#include "mylib.h"

int paz_skaicius;

int main()
{
    int uzkl_1 = 0, uzkl_2 = 0, uzkl_3 = 0;
    vector<Studentas> grupe;
    Studentas temp;
    while (uzkl_1 != 1 && uzkl_1 != 2){
        cout << "Ar norite: \n 1. Ivesti vardus ir pazymius (iveskite '1') \n 2. Generuoti vardus ir pazymius atsitiktinai (iveskite '2') \n";
        if (!(cin >> uzkl_1)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        if(uzkl_1 != 1 && uzkl_1 != 2) cout << "\nNeteisinga ivestis. Iveskite '1' arba '2'.\n" << endl;
    }
    while (uzkl_2 != 1 && uzkl_2 != 2 && uzkl_2 != 3){
        cout << "\nAr norite: \n 1. Skaiciuoti vidurki (iveskite '1') \n 2. Skaiciuoti mediana (iveskite '2') \n 3. Spausdinti pazymius (iveskite '3') \n";
        if (!(cin >> uzkl_2)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        if(uzkl_2 != 1 && uzkl_2 != 2 && uzkl_2 != 3) cout << "Neteisinga ivestis. Iveskite '1', '2' arba '3'." << endl;
    }
    if(uzkl_1 == 2)
        stud_gen(grupe,temp,uzkl_2);
    else
        stud_ivest(grupe,temp,uzkl_2);
    cout<<endl<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
    if(uzkl_2 == 1)
        cout<<setw(15)<<"Galutinis (Vid.)"<<endl;
    if(uzkl_2 == 2)
        cout<<setw(15)<<"Galutinis (Med.)"<<endl;
    if(uzkl_2 == 3)
        cout<<setw(15)<<"Pazymiai"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    for(const auto &i:grupe) spausd(i,uzkl_2);
    if(uzkl_2 != 3){
        cout << "\nAr norite spausdinti pazymius? (jei taip - iveskite '3', jei ne - '4')";
        while(uzkl_3 != 3 && uzkl_3 != 4){
            if (!(cin >> uzkl_3)) {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            }
            if(uzkl_3 != 3 && uzkl_3 != 4) cout << "Neteisinga ivestis. Iveskite '3' arba '4'.\n" << endl;
        }
        if(uzkl_3 == 3)
            for(const auto &i:grupe) spausd(i,uzkl_3);
    }
    grupe.clear();
    return 0;
}
