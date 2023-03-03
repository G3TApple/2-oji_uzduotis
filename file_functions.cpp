#include "mylib.h"
#include "file_functions.h"

extern int paz_skaicius;

void failo_nuskaitymas(vector<Studentas>& grupe, int uzkl_2){
    paz_skaicius = 0;
    Studentas temp;
    string eilute, eilute2, readfile, zodis;
    int n = 0;
    cout << "Pasiekiami failai:\n";
    cout << "-----------------------\n";
    system("dir /B *.txt");
    cout << "-----------------------\nIveskite failo pavadinima, is kurio norite nuskaityti duomenis: ";
    cin >> readfile;
    ifstream fd;
    try{
        fd.open(readfile);
        if(!fd.good()) throw "Toks failas nerastas.";

    } catch (const char* e){
        cout << e << endl;
    }
    int p;
    getline(fd,eilute);  ///Pazymiu kiekio skaiciavimas
    stringstream s(eilute);
    while(s >> zodis)
        paz_skaicius++;
    paz_skaicius -= 3;
    if(paz_skaicius != 0){
        while(getline(fd, eilute2))
        if(!fd.eof()){
            stringstream ss(eilute2);
            ss >> temp.vardas >> temp.pavarde;
            for(int i=0;i<paz_skaicius;i++){
                ss>>p;
                temp.paz.push_back(p);
            }
            ss>>temp.egz;
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
            grupe.push_back(temp);
            temp.paz.clear();
            n++;
        }
        else
            break;
    }
    else
        cout << "Klaida: duomenu faile nerasta pazymiu.";
    fd.close();
}

void spausd_i_faila(vector<Studentas>& grupe, int uzkl_2){
    sort(grupe.begin(), grupe.end(), grupes_rikiavimas);
    ofstream fr ("output.txt");
    unique_ptr<ostringstream> oss(new ostringstream());
    (*oss) <<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
    switch(uzkl_2){
        case 1:
            (*oss)<<setw(15)<<"Galutinis (Vid.)"<<endl;
            break;
        case 2:
            (*oss)<<setw(15)<<"Galutinis (Med.)"<<endl;
            break;
        case 3:
            (*oss)<<setw(15)<<"Galutinis (Vid. / Med.)"<<endl;
            break;
        }
    (*oss)<<"---------------------------------------------------------"<<endl;
    fr << oss->str();
    oss->str("");
    switch(uzkl_2){
    case 1:
        for(const auto &i:grupe)
            (*oss)<<setw(15)<<i.vardas<<setw(20)<<i.pavarde<<setw(3)<<fixed<<setprecision(2)<<i.gal_vid<<"       \n";
        break;
    case 2:
        for(const auto &i:grupe)
            (*oss)<<setw(15)<<i.vardas<<setw(20)<<i.pavarde<<setw(3)<<fixed<<setprecision(2)<<i.gal_med<<"       \n";
        break;
    case 3:
        for(const auto &i:grupe)
            (*oss)<<setw(15)<<i.vardas<<setw(20)<<i.pavarde<<setw(3)<<fixed<<setprecision(2)<<i.gal_vid<<" / "<<i.gal_med<<"\n";
        break;
    }

    fr << oss->str();
    oss->str("");
    fr.close();
}

bool grupes_rikiavimas(const Studentas &a, const Studentas &b){
    if (a.pavarde == b.pavarde)
        return a.vardas < b.vardas;
    else
        return a.pavarde < b.pavarde;
}
