
#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../../mylib.h"
#include "../../Studentas.h"
#include "catch_amalgamated.hpp"


TEST_CASE("vidurkis"){
    vector<int> paz {1,2,3};
    int egz = 5;
    REQUIRE(vidurkis(paz,egz))
}

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

TEST_CASE("Studento copy testavimas"){
    vector<int> paz{1,2,3};
    Studentas s1("Vardas","Pavarde",paz,4,5.2,8.4);
    Studentas s5;
    s5= s1;
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
    REQUIRE(test == false);

}

/*
#include <iostream>
#include <vector>
#include "../../myvector.h"

template <typename T>
void printTestResult(bool result, const T& expected, const T& actual, const std::string& testName) {
    std::cout << testName << ": ";
    if (result) {
        std::cout << "Pavyko";
    } else {
        std::cout << "Nepavyko";
    }
    std::cout << " (naudojant std::vector: " << expected << ", naudojant Vector: " << actual << ")" << std::endl;
}

template <typename T>
void testVectorFunctions() {
    // Test default constructor
    Vector<T> myVector;
    std::vector<T> stdVector;
    printTestResult(myVector.size() == stdVector.size(), stdVector.size(), myVector.size(), "Default konstruktorius");

    // Test constructor with size and value
    Vector<T> myVector2(3, 10);
    std::vector<T> stdVector2(3, 10);
    printTestResult(myVector2.size() == stdVector2.size(), stdVector2.size(), myVector2.size(), "Konstruktorius su dydziu ir reiksme");

    // Test initializer list constructor
    Vector<T> myVector3{1, 2, 3};
    std::vector<T> stdVector3{1, 2, 3};
    printTestResult(myVector3.size() == stdVector3.size(), stdVector3.size(), myVector3.size(), "Initializer List konstruktorius");


    // Test copy constructor
    Vector<T> myCopyVector(myVector2);
    std::vector<T> stdCopyVector(stdVector2);
    printTestResult(myCopyVector.size() == stdCopyVector.size(), stdCopyVector.size(), myCopyVector.size(), "Copy konstruktorius");

    // Test move constructor
    Vector<T> myMoveVector(std::move(myVector2));
    std::vector<T> stdMoveVector(std::move(stdVector2));
    printTestResult(myMoveVector.size() == stdMoveVector.size(), stdMoveVector.size(), myMoveVector.size(), "Move konstruktorius");

    // Test copy assignment operator
    Vector<T> myCopyAssignedVector;
    std::vector<T> stdCopyAssignedVector;
    myCopyAssignedVector = myCopyVector;
    stdCopyAssignedVector = stdCopyVector;
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Copy priskyrimo operatorius");

    // Test move assignment operator
    Vector<T> myMoveAssignedVector;
    std::vector<T> stdMoveAssignedVector;
    myMoveAssignedVector = std::move(myMoveVector);
    stdMoveAssignedVector = std::move(stdMoveVector);
    printTestResult(myMoveAssignedVector.size() == stdMoveAssignedVector.size(), stdMoveAssignedVector.size(), myMoveAssignedVector.size(), "Move priskyrimo operatorius");

    // Test indexing operator
    printTestResult(myCopyAssignedVector[0] == stdCopyAssignedVector[0], stdCopyAssignedVector[0], myCopyAssignedVector[0], "Indeksavimas");

    // Test front and back functions
    printTestResult(myCopyAssignedVector.front() == stdCopyAssignedVector.front(), stdCopyAssignedVector.front(), myCopyAssignedVector.front(), "Front");
    printTestResult(myCopyAssignedVector.back() == stdCopyAssignedVector.back(), stdCopyAssignedVector.back(), myCopyAssignedVector.back(), "Back");

    // Test iterators
    bool iteratorsMatch = std::equal(myCopyAssignedVector.begin(), myCopyAssignedVector.end(), stdCopyAssignedVector.begin());
    printTestResult(iteratorsMatch, true, iteratorsMatch, "Iteratoriai");

    // Test assign function
    myCopyAssignedVector.assign(4, 20);
    stdCopyAssignedVector.assign(4, 20);
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Assign");

    // Test clear function
    myCopyAssignedVector.clear();
    stdCopyAssignedVector.clear();
    printTestResult(myCopyAssignedVector.empty() == stdCopyAssignedVector.empty(), true, myCopyAssignedVector.empty(), "Clear");

    // Test insert function
    myCopyAssignedVector.insert(myCopyAssignedVector.begin(), 15);
    stdCopyAssignedVector.insert(stdCopyAssignedVector.begin(), 15);
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Insert");

    // Test erase function
    myCopyAssignedVector.erase(myCopyAssignedVector.begin());
    stdCopyAssignedVector.erase(stdCopyAssignedVector.begin());
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Erase");

    // Test emplace function
    myCopyAssignedVector.emplace(myCopyAssignedVector.begin(), 25);
    stdCopyAssignedVector.emplace(stdCopyAssignedVector.begin(), 25);
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Emplace");


    // Test emplace_back function
    myCopyAssignedVector.emplace_back(30);
    stdCopyAssignedVector.emplace_back(30);
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Emplace_back");

    // Test pop_back function
    myCopyAssignedVector.pop_back();
    stdCopyAssignedVector.pop_back();
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Pop_back");

    // Test resize function
    myCopyAssignedVector.resize(2);
    stdCopyAssignedVector.resize(2);
    printTestResult(myCopyAssignedVector.size() == stdCopyAssignedVector.size(), stdCopyAssignedVector.size(), myCopyAssignedVector.size(), "Resize");

    // Test swap function
    Vector<T> mySwapVector;
    std::vector<T> stdSwapVector;
    mySwapVector.swap(myCopyAssignedVector);
    stdSwapVector.swap(stdCopyAssignedVector);
    printTestResult(mySwapVector.size() == stdSwapVector.size(), stdSwapVector.size(), mySwapVector.size(), "Swap");

    // Test shrink_to_fit function
    mySwapVector.shrink_to_fit();
    stdSwapVector.shrink_to_fit();
    printTestResult(mySwapVector.capacity() == stdSwapVector.capacity(), stdSwapVector.capacity(), mySwapVector.capacity(), "Shrink_to_fit");
}

int main() {
    testVectorFunctions<int>();
    return 0;
}
*/
