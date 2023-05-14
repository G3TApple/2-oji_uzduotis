
#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../../mylib.h"
#include "../../Studentas.h"
#include "catch_amalgamated.hpp"


TEST_CASE("Studento konstruktorius"){
    vector<int> paz{1,2,3};
    Studentas studentas("vardas1", "pavarde1", paz, 9, 5.7, 1.5);
    REQUIRE(studentas.vardas() == "vardas1");
    REQUIRE(studentas.pavarde() == "pavarde1");
    REQUIRE(studentas.egz() == 9);
    REQUIRE(studentas.gal_vid() == (float)5.7);
    REQUIRE(studentas.gal_med() == (float)1.5);
}

TEST_CASE("Studento move priskyrimo operatorius"){
    vector<int> paz{1,2,3};
    Studentas s1("Vardas","Pavarde",paz,4,5.2,8.4);
    Studentas s5;
    s5 = std::move(s1);
    REQUIRE(s5.vardas() == "Vardas");
    REQUIRE(s5.pavarde() == "Pavarde");
    REQUIRE(s5.egz() == 4);
    REQUIRE(s5.gal_vid() == (float)5.2);
    REQUIRE(s5.gal_med() == (float)8.4);

}


TEST_CASE("Studento operatoriaus '<' testavimas"){
    vector<int> paz{1,2,3};
    Studentas A("Vardas","Pavarde",paz,4,5.2,8.4);
    Studentas B("Vardas","Zavarde",paz,4,5.2,8.4);
    bool test = (A<B);
    REQUIRE(test == true);

}
