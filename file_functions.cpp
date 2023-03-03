#include "mylib.h"

extern int paz_skaicius;

void failo_nuskaitymas(vector<Studentas>& grupe, int uzkl_2){
    paz_skaicius = 0;
    Studentas temp;
    string eilute, eilute2, readfile, zodis;
    int n = 0;
    ofstream fr ("output.txt");
    fr<<endl<<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
    switch(uzkl_2){
        case 1:
            fr<<setw(15)<<"Galutinis (Vid.)\n"<<endl;
            break;
        case 2:
            fr<<setw(15)<<"Galutinis (Med.)\n"<<endl;
            break;
        case 3:
            fr<<setw(15)<<"Galutinis (Vid. / Med.)\n"<<endl;
            break;
        };
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

void spausd_i_faila(const Studentas &temp, int uzkl_2){
    ofstream fr ("output.txt",std::ios::app);
    fr<<left<<setw(15)<<temp.vardas<<setw(20)<<temp.pavarde;
    switch(uzkl_2){
    case 1:
        fr<<setw(3)<<fixed<<setprecision(2)<<temp.gal_vid<<"       \n";
        break;
    case 2:
        fr<<setw(3)<<fixed<<setprecision(2)<<temp.gal_med<<"       \n";
        break;
    case 3:
        fr<<setw(3)<<fixed<<setprecision(2)<<temp.gal_vid<<" / "<<temp.gal_med<<"\n";
        break;
    case 4:
        for (const auto &i: temp.paz) fr << setw(3) << i << " ";
        fr << right << setw(10+(paz_skaicius-temp.paz.size())*4) << "Egz.: " << temp.egz << endl;
        break;
    }
}
