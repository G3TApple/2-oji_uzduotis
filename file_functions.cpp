#include "mylib.h"
#include "file_functions.h"

extern int paz_skaicius;

double failo_nuskaitymas(vector<Studentas>& grupe, int uzkl_2){
    paz_skaicius = -3;
    Studentas temp;
    string eilute, eilute2, readfile, zodis;
    int p;
    cout << "Pasiekiami failai:\n";
    cout << "-----------------------\n";
    system("dir /B *.txt");
    cout << "-----------------------\nIveskite failo pavadinima, is kurio norite nuskaityti duomenis: ";
    ifstream fd;
    char buffer[1048576];
    fd.rdbuf()->pubsetbuf(buffer,1048576);      /// pakeiciamas buferio dydis is 512B i 1MB
    while(1){
        cin >> readfile;
        fd.open(readfile);
        if(!(fd.good()))
            cout << "Toks failas nerastas. Bandykite dar karta. \n";
        else
            break;
    }
    Timer t;
    getline(fd,eilute);
    stringstream s(eilute);
    while(s >> zodis)
        paz_skaicius++;
    getline(fd,eilute);
    if(paz_skaicius > 0){
        stringstream buf;
        buf << fd.rdbuf();

        while(buf >> temp.vardas >> temp.pavarde){
            temp.paz.reserve(paz_skaicius);
            for(int i=0;i<paz_skaicius;i++){
                buf >> p;
                temp.paz.push_back(p);
            }
            buf >> temp.egz;
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
            temp.paz.clear();
            grupe.push_back(temp);
        }
    } else {
        cout << "Klaida: duomenu faile nerasta pazymiu.";
        exit(0);
    }


//    Timer t;
//    getline(fd,eilute);  ///Pazymiu kiekio skaiciavimas
//    stringstream s(eilute);
//    while(s >> zodis)
//        paz_skaicius++;
//    paz_skaicius -= 3;
//    getline(fd,eilute);
//    if(paz_skaicius > 0){
//        while(!(fd.eof())){
//            getline(fd, eilute2);
//            stringstream ss(eilute2);
//            ss >> temp.vardas >> temp.pavarde;
//            for(int i=0;i<paz_skaicius;i++){
//                ss>>p;
//                temp.paz.push_back(p);
//            }
//            ss>>temp.egz;
//            switch(uzkl_2){
//            case 1:
//                vidurkis(temp);
//                break;
//            case 2:
//                mediana(temp);
//                break;
//            case 3:
//                vidurkis(temp);
//                mediana(temp);
//                break;
//            case 4:
//                break;
//            }
//            grupe.push_back(temp);
//            temp.paz.clear();
//        }
//    } else {
//        cout << "Klaida: duomenu faile nerasta pazymiu.";
//        exit(0);
//    }
    cout << "Skaitymas is failo uztruko: "<< t.elapsed() << "s\n";
    fd.close();
    return t.elapsed();
}

void spausd_i_faila(vector<Studentas>& grupe, int uzkl_1, int uzkl_2, string filename){
    ofstream fr (filename);
    unique_ptr<ostringstream> oss(new ostringstream());
    (*oss) <<left<<setw(15)<<"Vardas"<<setw(20)<<"Pavarde";
    switch(uzkl_2){
        case 1:
            (*oss)<<setw(15)<<"Galutinis (Vid.)\n";
            break;
        case 2:
            (*oss)<<setw(15)<<"Galutinis (Med.)\n";
            break;
        case 3:
            (*oss)<<setw(15)<<"Galutinis (Vid. / Med.)\n";
            break;
        case 4:
            for(int i=1;i<=paz_skaicius;i++)
                (*oss)<<"ND"<<setw(4)<<to_string(i);
            (*oss)<<"Egz.\n";
            break;
        }
    (*oss)<<"----------------------------------------------------------------------------------------------------------------------\n";
    fr << oss->str();
    oss->str("");      /// oss reset
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
    case 4:
        for(const auto &i:grupe){
            (*oss)<<setw(15)<<i.vardas<<setw(20)<<i.pavarde;
            for (const auto &j: i.paz)
                (*oss) << setw(5) << j << " ";
            (*oss) << setw(5) << i.egz << "\n";
        }
        break;
    }
    fr << oss->str();
    oss->str("");
    fr.close();
}
