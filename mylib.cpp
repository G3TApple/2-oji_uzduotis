#include "mylib.h"
#include "file_functions.h"

extern size_t paz_skaicius;


void skirstymas(int& uzkl_6, int& uzkl_2, int& uzkl_1, vector<Studentas>& grupe, double& visa_trukme){
    if(uzkl_6 == 1) {       /// Jei du nauji konteineriai
        vector<Studentas> tinginiai, mokslinciai;
        Timer tinginiai_mokslinciai;

        if(uzkl_2 == 1 || uzkl_2 == 3){     /// skaiciuojama pagal vidurki, jei galutinis yra vidurkis arba vidurkis/mediana
            partition(grupe.begin(), grupe.end(), [](Studentas s)
            {
                return s.gal_vid>5.0;
            });
            auto it = std::find_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.gal_vid<5.0; });
            tinginiai = {it, grupe.end()};
            mokslinciai = {grupe.begin(), it};
        }
        if(uzkl_2 == 2){        /// skaiciuojama pagal mediana, jei galutinis yra mediana
            partition(grupe.begin(), grupe.end(), [](Studentas s)
            {
                return s.gal_med>5.0;
            });
            auto it = std::find_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.gal_med<5.0; });
            tinginiai = {it, grupe.end()};
            mokslinciai = {grupe.begin(), it};
        }
        cout << "Studentu rusiavimas i dvi grupes truko: "<< tinginiai_mokslinciai.elapsed() << "s\n";
        visa_trukme += tinginiai_mokslinciai.elapsed();
        tinginiai.shrink_to_fit();
        mokslinciai.shrink_to_fit();
        Timer rusiavimas;
        sort(tinginiai.begin(), tinginiai.end(), grupes_rik_pagal_varda);
        sort(mokslinciai.begin(), mokslinciai.end(), grupes_rik_pagal_varda);
        cout << "Studentu rusiavimas didejimo tvarka uztruko: " << rusiavimas.elapsed() << "s\n";
        visa_trukme += rusiavimas.elapsed();
        Timer rus_spausd;
        spausd_i_faila(tinginiai,uzkl_1,uzkl_2,"output_tinginiai.txt");
        spausd_i_faila(mokslinciai,uzkl_1,uzkl_2,"output_mokslinciai.txt");
        cout << "Surusiuotu studentu isvedimas i du failus uztruko: " << rus_spausd.elapsed() << "s\n";
        visa_trukme += rus_spausd.elapsed();
        for(auto &i:tinginiai) i.paz.clear();
        tinginiai.clear();
        for(auto &i:mokslinciai) i.paz.clear();
        mokslinciai.clear();
    } else {        /// Jei vienas naujas konteineris
        vector<Studentas> tinginiai;
        Timer tinginiai_mokslinciai;
        if(uzkl_2 == 1 || uzkl_2 == 3){      /// Jei galutinis yra vidurkis arba vidurkis/mediana - skaiciuojama pagal vidurki
            partition(grupe.begin(), grupe.end(), [](Studentas s)
            {
                return s.gal_vid>5.0;
            });
            auto it = std::find_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.gal_vid<5.0; });
            tinginiai = {it, grupe.end()};
            grupe.erase(it, grupe.end());
        }
        if(uzkl_2 == 2){        /// Jei galutinis yra mediana - skaiciuojama pagal mediana
            partition(grupe.begin(), grupe.end(), [](Studentas s)
            {
                return s.gal_med>5.0;
            });
            auto it = std::find_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.gal_med<5.0; });
            tinginiai = {it, grupe.end()};
            grupe.erase(it, grupe.end());
        }
        cout << "Studentu rusiavimas i dvi grupes truko: "<< tinginiai_mokslinciai.elapsed() << "s\n";
        visa_trukme += tinginiai_mokslinciai.elapsed();
        tinginiai.shrink_to_fit();
        grupe.shrink_to_fit();
        Timer rusiavimas;
        sort(grupe.begin(), grupe.end(), grupes_rik_pagal_varda);
        sort(tinginiai.begin(), tinginiai.end(), grupes_rik_pagal_varda);
        cout << "Studentu rusiavimas didejimo tvarka uztruko: " << rusiavimas.elapsed() << "s\n";
        visa_trukme += rusiavimas.elapsed();
        Timer rus_spausd;
        spausd_i_faila(tinginiai,uzkl_1,uzkl_2,"output_tinginiai.txt");
        spausd_i_faila(grupe,uzkl_1,uzkl_2,"output_mokslinciai.txt");
        cout << "Surusiuotu studentu isvedimas i du failus uztruko: " << rus_spausd.elapsed() << "s\n";
        visa_trukme += rus_spausd.elapsed();
        for(auto &i:tinginiai) i.paz.clear();
        tinginiai.clear();
    }
}

void stud_ivest(vector<Studentas> &grupe, Studentas &temp, int uzkl_2){
    string uzkl;
    cout << "\nKiek daugiausia pazymiu gales tureti kiekvienas studentas? ";
    cin >> paz_skaicius;
    while(paz_skaicius < 1 || paz_skaicius > 20){
            cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 20. " << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }
    do{
        pild(temp,uzkl_2);
        grupe.push_back(temp);
        temp.paz.clear();
        cout<<"Noredami baigti, iveskite 'n' arba iveskite bet koki klavisa ir toliau veskite kito studento duomenis\n";
        //statistika(grupe);
        cin.ignore();
        getline(cin, uzkl);
    } while (uzkl != "n" && uzkl != "N");
}

void pild(Studentas &temp, int uzkl_2){
    int p;
    cout<<"\nIveskite studento varda ir pavarde: ";
    cin >> temp.vardas >> temp.pavarde;
    while(tik_raides(temp.vardas) || tik_raides(temp.pavarde)){
        cout<<"Neteisinga ivestis. Varde gali buti tik raides. Bandykite dar karta. ";
        cin >> temp.vardas >> temp.pavarde;
    }
    cout << "Iveskite " << paz_skaicius << " paz. (Veskite tik sveikuosius skaicius. Noredami nutraukti pazymiu ivedima, iveskite bet kokia raide). ";
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
        if(temp.paz.size() > paz_skaicius){
            cout << "Ivedete per daug pazymiu. Bus irasyti tik pirmi " << paz_skaicius << " pazymiai.\n";
            break;
        }
        //statistika(temp.paz);
    } while((temp.paz.size() < paz_skaicius) || temp.paz.empty()); /// AR CIA VISKAS GERAI?
    cin.clear();
    std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    cout << "Iveskite egzamino paz. ";
    cin>>temp.egz;
    while(1){
        if(cin.fail() || temp.egz < 1 || temp.egz > 10 ){
            cin.clear();
            std::cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pazymys turi buti tarp 1 ir 10. ";
            cin >> temp.egz;
        }
        else
            break;
    }
    switch(uzkl_2){
    case 1:
        vidurkis(temp);
        break;
    case 2:
        mediana(temp);
        break;
    case 3:
        vidurkis(temp);
        mediana(temp);
        break;
    case 4:
        break;
    }
    cout << "Duomenys irasyti." << endl;
}

void spausd(const Studentas &temp, int uzkl_2, int uzkl_1){
    cout<<left<<setw(15)<<temp.vardas<<setw(20)<<temp.pavarde;
    switch(uzkl_2){
    case 1:
        cout<<setw(3)<<fixed<<setprecision(2)<<temp.gal_vid<<"       \n";
        break;
    case 2:
        cout<<setw(3)<<fixed<<setprecision(2)<<temp.gal_med<<"       \n";
        break;
    case 3:
        cout<<setw(3)<<fixed<<setprecision(2)<<temp.gal_vid<<" / "<<temp.gal_med<<"\n";
        break;
    case 4:
        for (const auto &i: temp.paz) cout << setw(3) << i << " ";
        cout << right << setw(10+(paz_skaicius-temp.paz.size())*4) << "Egz.: " << temp.egz << endl;
        break;
    }
}

void gen_paz(int kelintas, int uzkl_2, Studentas &temp){
    static std::random_device _rd;
    static std::mt19937 _rnd{_rd()};
    static std::uniform_int_distribution<int> dist(0,10);
    static std::uniform_int_distribution<int> dist_egz(1,10);
    temp.vardas = "Vardas" + to_string(kelintas);
    temp.pavarde = "Pavarde" + to_string(kelintas);
    temp.egz = dist_egz(_rnd);
    for(size_t i=0;i<paz_skaicius;i++)
        temp.paz.push_back(dist(_rnd));
    switch(uzkl_2){
    case 1:
        vidurkis(temp);
        break;
    case 2:
        mediana(temp);
        break;
    case 3:
        vidurkis(temp);
        mediana(temp);
        break;
    case 4:
        break;
    }
}

double stud_gen(vector<Studentas> &grupe, Studentas &temp, int uzkl_2){
    int stud_sk;
    cout << "Kiek studentu norite generuoti? ";
    cin >> stud_sk;
    while (stud_sk < 1){
            cout << "Neteisinga ivestis. Iveskite skaiciu, didesni uz 0.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    cout << "Kiek daugiausia pazymiu norite skirti kiekvienam studentui? ";
    cin >> paz_skaicius;
    while(paz_skaicius < 1){
            cout << "Neteisinga ivestis. Iveskite skaiciu, didesni uz 0.\n" << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    Timer gen;
    for(int i=0;i<stud_sk;i++){
        gen_paz(i,uzkl_2,temp);
        grupe.push_back(temp);
        temp.paz.clear();
    }
    cout << "Studentu duomenu generavimas uztruko: " << gen.elapsed() << "s\n";
    return gen.elapsed();
}

///Pagalbines funkcijos/////////////////////////////////////////////////////////

void vidurkis(Studentas &temp){
    double paz_suma = accumulate(temp.paz.begin(),temp.paz.end(),0.);
    temp.gal_vid = 0.6*temp.egz+0.4*paz_suma/paz_skaicius;
}

void mediana(Studentas &temp){
    double med;
    sort(temp.paz.begin(),temp.paz.end());
    if(temp.paz.size()%2 == 0) /// jei pazymiu skaicius lyginis
        med = (temp.paz[temp.paz.size()/2-1]+temp.paz[temp.paz.size()/2])/2.0;
    else                /// jei pazymiu skaicius nelyginis
        med = temp.paz[temp.paz.size()/2];
    temp.gal_med = 0.4*med+0.6*temp.egz;
}

bool tik_raides(string name){
    return !std::regex_match(name, std::regex("^[A-Za-z]+$"));
}

void int_input_check(int& input, vector<int> correct){
    if (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    for(int i : correct)
        if(input == i)
            return;
    cout << "Klaidinga ivestis. Turite ivesti viena is siu skaiciu: ";
    for(size_t i=0;i<correct.size();i++)
        if(correct.size()-i-1 != 0)
            cout << "'" << correct[i] << "', ";
        else
            cout << "'" << correct[i] << "'.\n";
    int_input_check(input,correct);
}

bool grupes_rik_pagal_varda(const Studentas &a, const Studentas &b){
    if (a.pavarde == b.pavarde)
        return a.vardas < b.vardas;
    else
        return a.pavarde < b.pavarde;
}
