#include "mylib.h"

int stud_ivest(Studentas*& grupe){
    string uzkl;
    int stud_skaicius = 0;
    do{
        pild(grupe[stud_skaicius]);
        cout << "vardas " << grupe[stud_skaicius].vardas <<
        " pavarde " << grupe[stud_skaicius].pavarde <<
        " paz kiekis " << grupe[stud_skaicius].paz_kiekis<< " "
        << grupe[stud_skaicius].egz << endl;

        cout<<"Noredami baigti, iveskite 'n' arba iveskite bet koki klavisa ir toliau veskite kito studento duomenis\n";
        cin.ignore();
        getline(cin, uzkl);
        stud_skaicius++;
        if(stud_skaicius == 50)
            cout << "Daugiau studentu ivest negalima.\n";



    } while (uzkl != "n" && uzkl != "N" && stud_skaicius < 51);
    return stud_skaicius;
}

bool ne_tik_raides(string name){
    return !std::regex_match(name, std::regex("^[A-Za-z]+$"));
}

void pild(Studentas &temp){
    int p, paz_kiekis = 0;
    int *paz = nullptr;
    temp.paz = new int[0];
    temp.paz[0] = -1;
    cout<<"\nIveskite studento varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    while(ne_tik_raides(temp.vardas) || ne_tik_raides(temp.pavarde)){
        cout<<"Neteisinga ivestis. Varde gali buti tik raides. Bandykite dar karta. ";
        cin >> temp.vardas >> temp.pavarde;
    }
    cout << "Iveskite paz. (Noredami nutraukti pazymiu ivedima, iveskite bet kokia raide) ";
    do{
        bool ivesti = true;
        cin>>p;
        if(!cin){
            if(temp.paz[0] == -1){
                cin.clear();
                std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite bent viena pazymi. ";
                ivesti = false;
            }
            else
                break;
        }
        if(p >= 0 && p <= 10 && ivesti){
            paz = new int[paz_kiekis];
            copy(temp.paz,temp.paz+paz_kiekis,paz);
            delete[] temp.paz;
            temp.paz = new int[paz_kiekis+1];
            copy(paz, paz+paz_kiekis, temp.paz);
            paz_kiekis++;
            temp.paz[paz_kiekis-1] = p;
            delete[] paz;
        }
        else
            cout << "Pazymys turi buti tarp 0 (negautas) ir 10\n";
    } while(cin || temp.paz[0] == -1);
    //cin.clear();
    //std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    temp.paz_kiekis = paz_kiekis;
    cout << "Iveskite egzamino paz. ";
    cin>>temp.egz;
    while(1){
        if(cin.fail() || temp.egz < 0 || temp.egz > 10 ){
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pazymys turi buti tarp 1 ir 10. ";
            cin >> temp.egz;
        }
        else
            break;
    }
    cout << "Duomenys irasyti." << endl;
}

void spausd(Studentas &temp, int uzkl_2, int max_paz_kiekis){
    if(uzkl_2 == 1)
        vidurkis(temp,max_paz_kiekis);
    if(uzkl_2 == 2)
        mediana(temp);
    cout<<left<<setw(15)<<temp.vardas<<setw(20)<<temp.pavarde;
    if(uzkl_2 == 1 || uzkl_2 == 2)
        cout<<setw(3)<<fixed<<setprecision(2)<<temp.galutinis<<"       \n";
    if(uzkl_2 == 3){
        for(int i=0;i<temp.paz_kiekis;i++)
            cout << setw(3) << temp.paz[i] << " ";
        cout << right << setw(10+(max_paz_kiekis-temp.paz_kiekis)*4) << "Egz.: " << temp.egz << endl;
    }
}

void gen_paz(int kelintas, int pazym_sk, int uzkl_2, Studentas*& grupe){
    grupe[kelintas].paz = new int[pazym_sk];
    static std::random_device _rd;
    static std::mt19937 _rnd{_rd()};
    static std::uniform_int_distribution<int> dist(0,10);
    static std::uniform_int_distribution<int> dist_egz(1,10);
    grupe[kelintas].vardas = "Vardas" + to_string(kelintas);
    grupe[kelintas].pavarde = "Pavarde" + to_string(kelintas);
    grupe[kelintas].egz = dist(_rnd);
    grupe[kelintas].paz_kiekis = pazym_sk;
    for(int i=0;i<pazym_sk;i++){
        grupe[kelintas].paz[i] = dist_egz(_rnd);
    }
    if(uzkl_2 == 1)
        vidurkis(grupe[kelintas],pazym_sk);
    if(uzkl_2 == 2)
        mediana(grupe[kelintas]);
}

int stud_gen(Studentas*& grupe, int uzkl_2, int* n){
    int pazym_sk = 0;
    cout << "Kiek studentu norite generuoti? ";
    cin >> *n;
    while (*n < 1){
            cout << "Neteisinga ivestis. Iveskite skaiciu, didesni uz 0.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    cout << "Kiek daugiausia pazymiu norite skirti kiekvienam studentui? ";
    cin >> pazym_sk;
    while(pazym_sk < 1){
            cout << "Neteisinga ivestis. Iveskite skaiciu, didesni uz 0.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    delete[] grupe;
    grupe = new Studentas [*n];
    for(int i=0;i<*n;i++)
        gen_paz(i,pazym_sk,uzkl_2,grupe);
    return pazym_sk;
}

void vidurkis(Studentas &temp, int paz_sk){
    double paz_suma = accumulate(temp.paz,temp.paz+temp.paz_kiekis,0.);
    temp.galutinis = 0.6*temp.egz+0.4*paz_suma/paz_sk;
}

void mediana(Studentas &temp){
    double med;
    sort(temp.paz,temp.paz+temp.paz_kiekis);
    if(temp.paz_kiekis%2 == 0) /// jei pazymiu skaicius lyginis
        med = (temp.paz[(temp.paz_kiekis)/2-1] + temp.paz[(temp.paz_kiekis)/2])/2.0;
    else                /// jei pazymiu skaicius nelyginis
        med = temp.paz[(temp.paz_kiekis)/2];
    temp.galutinis = 0.4*med+0.6*temp.egz;
}
