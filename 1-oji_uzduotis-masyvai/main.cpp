#include "mylib.h"

int main()
{
    int uzkl_1 = 0, uzkl_2 = 0, uzkl_3 = 0;
    int n = 50;
    int* max_paz_kiekis_1 = new int[n];
    int max_paz_kiekis_2 = 0;
    Studentas* grupe = new Studentas [n];
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
        max_paz_kiekis_2 = stud_gen(grupe,uzkl_2,&n);
    else{
        n = stud_ivest(grupe);
        delete[] max_paz_kiekis_1;
        max_paz_kiekis_1 = new int[n];  ///didiauzio pazymiu kiekio skaiciavimas
        for(int i=0;i<n;i++)
            max_paz_kiekis_1[i] = grupe[i].paz_kiekis;
    }
    cout<<endl<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
    if(uzkl_2 == 1)
        cout<<setw(15)<<"Galutinis (Vid.)"<<endl;
    if(uzkl_2 == 2)
        cout<<setw(15)<<"Galutinis (Med.)"<<endl;
    if(uzkl_2 == 3)
        cout<<setw(15)<<"Pazymiai"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    for(int i=0;i<n;i++){
        if(uzkl_1 == 2)
            spausd(grupe[i],uzkl_2,max_paz_kiekis_2);
        else
            spausd(grupe[i],uzkl_2,*max_element(max_paz_kiekis_1,max_paz_kiekis_1+n));
    }
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
            for(int i=0;i<n;i++){
                if(uzkl_1 == 2)
                    spausd(grupe[i],uzkl_3,max_paz_kiekis_2);
                else
                    spausd(grupe[i],uzkl_3,*max_element(max_paz_kiekis_1,max_paz_kiekis_1+n));
            }
    }
    for(int i=0;i<n;i++)
        delete[] grupe[i].paz;
    delete [] grupe;
    return 0;
}
