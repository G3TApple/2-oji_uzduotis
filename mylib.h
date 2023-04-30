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
#include <numeric>
#include <chrono>
#include <regex>
#include <fstream>
#include <sstream>
#include <tuple>

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
using std::unique_ptr;
using std::ostringstream;
using std::istringstream;
using std::partition;
using std::find_if;
using std::copy;
using std::move;
using std::tie;

#include "Studentas.h"

template <class T>
void statistika (vector <T> &temp){
    cout<<" vector size: "<<temp.size()<<" vector capacity: "<<temp.capacity()<<"\n";
}

class Timer {
    private:
       std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        Timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
            start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
            return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count();
        }
};

bool tik_raides(string name);
void int_input_check(int& input, vector<int> correct);
void skirstymas(int& uzkl_6, int& uzkl_2, int& uzkl_1, vector<Studentas>& grupe, double& visa_trukme);
void stud_ivest(vector<Studentas> &grupe, Studentas &temp, int uzkl_2);
void isvedimas_i_ekrana(vector<Studentas> &grupe,int& uzkl_4,int& uzkl_2,int& uzkl_1);
void pild(Studentas &temp, int uzkl_2);
void spausd(const Studentas &temp, int uzkl_2, int uzkl_1);
double stud_gen(vector<Studentas> &grupe, Studentas &temp, int uzkl_2);
void gen_paz(int kelintas, int uzkl_2, Studentas &temp);
double mediana(vector<int> paz, int egz);
double vidurkis(vector<int> paz, int egz);
bool grupes_rik_pagal_varda(const Studentas &a, const Studentas &b);

#endif // MYLIB_H_INCLUDED
