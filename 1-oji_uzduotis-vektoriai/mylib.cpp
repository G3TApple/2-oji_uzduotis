#include "mylib.h"
extern int paz_skaicius;

void stud_ivest(vector<Studentas> &grupe, Studentas &temp, int uzkl_2){
    string uzkl;
    int paz_sk = 0;
    cout << "\nKiek daugiausia pazymiu gales tureti kiekvienas studentas? ";
    cin >> paz_sk;
    while(paz_sk < 1 || paz_sk > 20){
            cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 20. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    paz_skaicius = paz_sk;
    do{
        if(grupe.size()==grupe.capacity()) grupe.reserve(1000);
        pild(temp,uzkl_2,paz_sk);
        grupe.push_back(temp);
        temp.paz.clear();
        cout<<"Noredami baigti, iveskite 'n' arba iveskite bet koki klavisa ir toliau veskite kito studento duomenis\n";
        //statistika(grupe);
        cin.ignore();
        getline(cin, uzkl);
    } while (uzkl != "n" && uzkl != "N");
}

bool tik_raides(string name){
    return !std::regex_match(name, std::regex("^[A-Za-z]+$"));
}


void pild(Studentas &temp, int uzkl_2, int paz_sk){
    int p;
    cout<<"\nIveskite studento varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    while(tik_raides(temp.vardas) || tik_raides(temp.pavarde)){
        cout<<"Neteisinga ivestis. Varde gali buti tik raides. Bandykite dar karta. ";
        cin >> temp.vardas >> temp.pavarde;
    }
    cout << "Iveskite " << paz_sk << " paz. (Noredami nutraukti pazymiu ivedima, iveskite bet kokia raide) ";
    do{
        bool pushback = true;
        cin>>p;
        if(!cin){
            if(temp.paz.empty()){
                cin.clear();
                std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Iveskite bent viena pazymi. ";
                pushback = false;
            }
            else
                break;
        }
        if(p >= 0 && p <= 10 && pushback)
            temp.paz.push_back(p);
        else
            cout << "Pazymys turi buti tarp 0 (negautas) ir 10\n";
        if(temp.paz.size() > paz_sk){
            cout << "Ivedete per daug pazymiu. Bus irasyti tik pirmi " << paz_sk << " pazymiai.\n";
            break;
        }
        //statistika(temp.paz);
    } while(cin && temp.paz.size() < paz_sk || temp.paz.empty());
    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Iveskite egzamino paz. ";
    cin>>temp.egz;
    while(1){
        if(cin.fail() || temp.egz < 0 || temp.egz > 10 ){
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pazymys turi buti tarp 0 (negautas) ir 10. ";
            cin >> temp.egz;
        }
        else
            break;
    }
    if(uzkl_2 == 1)
        vidurkis(temp,paz_sk);
    if(uzkl_2 == 2)
        mediana(temp);
    cout << "Duomenys irasyti." << endl;
}

void spausd(const Studentas &temp, int uzkl_2){
    cout<<left<<setw(15)<<temp.vardas<<setw(20)<<temp.pavarde;
    if(uzkl_2 == 1 || uzkl_2 == 2)
        cout<<setw(3)<<fixed<<setprecision(2)<<temp.galutinis<<"       \n";
    if(uzkl_2 == 3){
        for (const auto &i: temp.paz) cout << setw(3) << i << " ";
        cout << right << setw(10+(paz_skaicius-temp.paz.size())*4) << "Egz.: " << temp.egz << endl;
    }
}

void gen_paz(int kelintas, int pazym_sk, int uzkl_2, Studentas &temp){
    static std::random_device _rd;
    static std::mt19937 _rnd{_rd()};
    static std::uniform_int_distribution<int> dist(0,10);
    static std::uniform_int_distribution<int> dist_egz(1,10);
    temp.vardas = "Vardas" + to_string(kelintas);
    temp.pavarde = "Pavarde" + to_string(kelintas);
    temp.egz = dist(_rnd);
    for(int i=0;i<pazym_sk;i++)
        temp.paz.push_back(dist_egz(_rnd));
    if(uzkl_2 == 1)
        vidurkis(temp,pazym_sk);
    if(uzkl_2 == 2)
        mediana(temp);
}

void stud_gen(vector<Studentas> &grupe, Studentas &temp, int uzkl_2){
    int stud_sk, pazym_sk = 0;
    cout << "Kiek studentu norite generuoti? ";
    cin >> stud_sk;
    while (stud_sk < 1){
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
    for(int i=0;i<stud_sk;i++){
        if(grupe.size()==grupe.capacity()) grupe.reserve(1000);
        gen_paz(i,pazym_sk,uzkl_2,temp);
        grupe.push_back(temp);
        temp.paz.clear();
    }
}

void vidurkis(Studentas &temp, int paz_sk){
    double paz_suma = accumulate(temp.paz.begin(),temp.paz.end(),0.);
    temp.galutinis = 0.6*temp.egz+0.4*paz_suma/paz_sk;
}

void mediana(Studentas &temp){
    double med;
    sort(temp.paz.begin(),temp.paz.end());
    if(temp.paz.size()%2 == 0) /// jei pazymiu skaicius lyginis
        med = (temp.paz[temp.paz.size()/2-1]+temp.paz[temp.paz.size()/2])/2.0;
    else                /// jei pazymiu skaicius nelyginis
        med = temp.paz[temp.paz.size()/2];
    temp.galutinis = 0.4*med+0.6*temp.egz;
}
