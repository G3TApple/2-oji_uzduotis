#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <random>
#include <ctime>
#include <numeric> // kam reikia?
#include <chrono> // ar reikia?
#include <regex>
#include <fstream>
#include <cstdlib> // gal nereikia?
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;
using std::vector;
using std::numeric_limits;
using std::to_string;
using std::sort;
using std::accumulate;
using std::getline;
using std::stringstream;
using std::ifstream;
using std::ofstream;

template <class T>
void statistika (vector <T> &temp){
    cout<<"\n vector size: "<<temp.size()<<" vector capacity: "<<temp.capacity()<<"\n";
}

struct Studentas{
    string vardas = "", pavarde = "";
    vector<int> paz;
    int egz = 0;
    double gal_vid = 0, gal_med = 0;
};

void stud_ivest(vector<Studentas> &grupe, Studentas &temp, int uzkl_2);
void pild(Studentas &temp, int uzkl_2);
void spausd(const Studentas &temp, int uzkl_2, int uzkl_1);
void stud_gen(vector<Studentas> &grupe, Studentas &temp, int uzkl_2);
void gen_paz(int kelintas, int uzkl_2, Studentas &temp);
void mediana(Studentas &temp);
void vidurkis(Studentas &temp);

#endif // MYLIB_H_INCLUDED
