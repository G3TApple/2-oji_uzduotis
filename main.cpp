#include "mylib.h"
#include "file_functions.h"

int paz_skaicius;

int main()
{
    int uzkl_1 = -1, uzkl_2 = -1, uzkl_3 = -1;
    vector<Studentas> grupe;
    Studentas temp;
    while (uzkl_1 != 1 && uzkl_1 != 2 && uzkl_1 != 3){
        cout << "Ar norite: \n 1. Ivesti vardus ir pazymius (iveskite '1')\n 2. Generuoti vardus ir pazymius atsitiktinai (iveskite '2')\n 3. Skaityti vardus ir pazymius is failo (iveskite '3')\n";
        if (!(cin >> uzkl_1)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        if(uzkl_1 != 1 && uzkl_1 != 2 && uzkl_1 != 3) cout << "\nNeteisinga ivestis. Iveskite '1', '2' arba '3'.\n" << endl;
    }
    while (uzkl_2 != 1 && uzkl_2 != 2 && uzkl_2 != 3 && uzkl_2 != 4){
        cout << "\nAr norite:\n 1. Skaiciuoti vidurki (iveskite '1')\n 2. Skaiciuoti mediana (iveskite '2')\n 3. Skaiciuoti mediana ir vidurki (iveskite '3')\n";
        if(uzkl_1 != 3)
            cout << " 4. Spausdinti pazymius (iveskite '4')\n";
        if (!(cin >> uzkl_2)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
        if(uzkl_2 != 1 && uzkl_2 != 2 && uzkl_2 != 3 && uzkl_2 != 4) cout << "Neteisinga ivestis. Iveskite '1', '2', '3' arba '4'." << endl;
    }
    switch(uzkl_1){
    case 1:
        stud_ivest(grupe,temp,uzkl_2);
        break;
    case 2:
        stud_gen(grupe,temp,uzkl_2);
        break;
    case 3:
        failo_nuskaitymas(grupe,uzkl_2);
        break;
    }
    if(uzkl_1 != 3){    /// Jei rezultatai rasomi ne i faila
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
            while(uzkl_3 != 4 && uzkl_3 != 0){
                if (!(cin >> uzkl_3)) {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                }
                if(uzkl_3 != 3 && uzkl_3 != 4) cout << "Neteisinga ivestis. Iveskite '4' arba '0'.\n" << endl;
            }
            if(uzkl_3 == 4)
                for(const auto &i:grupe)
                    spausd(i,uzkl_3,uzkl_1);
        }
    } else
        for(const auto &i:grupe)
            spausd(i,uzkl_2,uzkl_1);
    for(auto &i:grupe) i.paz.clear(); /// anksciau nebuvo; ar reikia?
    grupe.clear();
    return 0;
}
