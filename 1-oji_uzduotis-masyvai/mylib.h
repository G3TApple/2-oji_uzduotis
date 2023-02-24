#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <numeric>
#include <chrono>
#include <regex>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::fixed;
using std::setw;
using std::setprecision;
using std::string;
using std::numeric_limits;
using std::sort;
using std::accumulate;
using std::getline;
using std::max_element;
using std::copy;
using std::to_string;

struct Studentas{
    string vardas = "", pavarde = "";
    int* paz=nullptr;
    int paz_kiekis = 0;
    int egz = 0;
    double galutinis = 0;
};

int stud_ivest(Studentas*& grupe);
void pild(Studentas &temp);
void spausd(Studentas &temp, int uzkl_2, int max_paz_kiekis);
int stud_gen(Studentas*& grupe, int uzkl_2, int *n);
void gen_paz(int kelintas, int pazym_sk, int uzkl_2, Studentas*& grupe);
void mediana(Studentas &temp);
void vidurkis(Studentas &temp, int paz_sk);
bool ne_tik_raides(string name);

#endif // MYLIB_H_INCLUDED
