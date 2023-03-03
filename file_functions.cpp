#include "mylib.h"

extern int paz_skaicius;

void failo_nuskaitymas(vector<Studentas>& grupe){
    paz_skaicius = 0;
    Studentas temp;
    string eilute, readfile, zodis;
    int n = 0;
    cout << "Pasiekiami failai:\n";
    cout << "-----------------------\n";
    system("dir /B *.txt");
    cout << "-----------------------\nIveskite failo pavadinima, is kurio norite nuskaityti duomenis. ";
    cin >> readfile;

    ifstream fd (readfile);
    if(fd){
        int p;
        getline(fd,eilute);  ///Pazymiu kiekio skaiciavimas
        stringstream s(eilute);
        while(s >> zodis)
            paz_skaicius++;
        paz_skaicius -= 3;
        if(paz_skaicius != 0){
            while(fd)
            if(!fd.eof()){
                fd >> temp.vardas >> temp.pavarde;
                for(int i=0;i<paz_skaicius-1;i++){
                    fd>>p;
                    temp.paz.push_back(p);
                }
                fd>>temp.egz;
                fd.ignore(numeric_limits<std::streamsize>::max(), '\n');
                grupe.push_back(temp);
                temp.paz.clear();
                n++;
            }
            else
                break;
        }
        else
            cout << "Klaida: duomenu faile nerasta pazymiu.";
    }
    else if(fd.failbit)
        cout << "Klaida: netinkami duomenys faile, failas tuscias arba nerastas.";
    else if(fd.badbit)
        cout << "Esmine klaida. Rysys su failu sugadintas arba prarastas.";
    fd.close();
}

void spausd_i_faila(const Studentas &temp, int uzkl_2){
    ofstream fr ("output.txt", std::ios::app);
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
