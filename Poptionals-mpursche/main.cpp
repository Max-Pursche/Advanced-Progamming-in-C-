#include <iostream>
#include <experimental/optional>
#include <memory>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;

/*
 *  This project will use ASCII art:
 *                                                                  _
 *  A box represents reserved memory (to hold a variable's value): | |
 *                                                                 |_|
 *                                                                              ?_
 *  A box with a question mark in the upper left corner represents an optional: | |
 *                                                                              |_|
 *                                                      _ _ _ _ _ _
 *  A series of consecutive boxes represents a vector: | | | | | | |
 *                                                     |_|_|_|_|_|_|
 *
 *  An arrow represents a pointer: ---->
 *
 *  An arrow with a bar represents a nullptr: -->|
 */
shared_ptr<double> squared(shared_ptr<double>);
int main() {
    /* 1. Create the following optional integers:
     *      ?__
     *      |  |
     *      |__|
     *      ?__
     *      |42|
     *      |__|
     *      ?__?__?__?__?__?__?__?__
     *      |  |90|44|  |79|  |-5|17|
     *      |__|__|__|__|__|__|__|__|
     */
    //Optional ptr
    optional<int> myOptNullInt = experimental::nullopt;
    optional<int> myOptInt = 42;
    vector<optional<int>> myOptVec = {experimental::nullopt, 90, 44, experimental::nullopt, 79, experimental::nullopt, -5, 17};

    /* 2. Create the following smart pointers,
     *    where each one points to a different data type:
     *      Stack           Heap
     *       __              __
     *      |  | ---------> |11|
     *      |__|            |__|
     *       __              ___
     *      |  | ---------> |0.3|
     *      |__|            |___|
     *       __              __
     *      |  | ---------> |d |
     *      |__|            |__|
     *       __              __
     *      |  | ---------> |yo|
     *      |__|            |__|
     *       __              ____
     *      |  | ---------> |true|
     *      |__|            |____|
     *       __              _________
     *      |  | ---------> |123456789|
     *      |__|            |_________|
     */
    //Creating Stack Memory
    unique_ptr<int> intPtr1 = nullptr;
    unique_ptr<float> floatPtr1 = nullptr;
    unique_ptr<char> chrPtr1 = nullptr;
    unique_ptr<string> strPtr1 = nullptr;
    unique_ptr<bool> boolPtr1 = nullptr;
    unique_ptr<long> lngPtr1 = nullptr;

    //putting value in Heap Memory
    intPtr1 = make_unique<int>(11);
    floatPtr1 = make_unique<float>(0.3);
    chrPtr1 = make_unique<char>('d');
    strPtr1 = make_unique<string>("yo");
    boolPtr1 = make_unique<bool>(true);
    lngPtr1 = make_unique<long>(123456789);

    /* 3. Create the following smart pointers:
     * (Note that the orientation is horizontal instead of vertical for Stack and Heap memory on this one.)
     *            __ __ __ __ __ __ __ __ __
     *  Stack    |  |  |  |  |  |  |  |  |  |
     *           |__|__|__|__|__|__|__|__|__|
     *            |  |  |  |  |  |  |  |  |
     *            |  |  v  |  |  v  |  v  |
     *            v  v  -  v  v  -  v  -  v
     *           __  __   __  __   __    __
     *  Heap    |w ||- | |* ||? | |L |  |; |
     *          |__||__| |__||__| |__|  |__|
     */

    unique_ptr<vector<string>> strVecPtr = {};

    strVecPtr->push_back(";");
    strVecPtr->push_back(nullptr);
    strVecPtr->push_back("L");
    strVecPtr->push_back(nullptr);
    strVecPtr->push_back("?");
    strVecPtr->push_back("*");
    strVecPtr->push_back(nullptr);
    strVecPtr->push_back("-");
    strVecPtr->push_back("w");


    /* 4. Create the following smart pointer:
     *      Stack           Heap
     *       __              __ __ __ __ __ __ __ __
     *      |  | ---------> |11|22|33|44|55|66|77|88|
     *      |__|            |__|__|__|__|__|__|__|__|
     */

    vector<int> intVec = {11,22,33,44,55,66,77,88};
    unique_ptr<vector<int>> vecIntPtr;
    vecIntPtr = make_unique<vector<int>>(intVec);

    /* 5. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |  |
     *      |__|       |__|
     *                  |
     *                  v
     *                  __
     *                 |  |
     *                 |__|
     */
    // Declare a shared pointer in stack
    auto sharedPtr = make_unique<unique_ptr<string>>();
    *sharedPtr = make_unique<string>(nullptr);
    **sharedPtr = nullptr;

    /* 6. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |  |
     *      |__|    >  |__|
     *             /
     *       __   /
     *      |  | /
     *      |__|
     */
    //??? maybe
    auto sharedPtr1 = make_shared<string>(nullptr);
    auto sharedPtr2 = make_shared<string>();
    sharedPtr2 = sharedPtr1;


    /* 7. Create the following optional smart pointers:
     *      Stack      Heap
     *      ?__         __
     *      |  | ----> |98|
     *      |__|       |__|
     *
     *      ?__
     *      |  |
     *      |__|
     *
     *      ?__
     *      |  | --->|
     *      |__|
     */
    unique_ptr<optional<int>> myIntNullOpt = make_unique<optional<int>>(98);
    unique_ptr<optional<int>> myIntNullOpt2;
    unique_ptr<optional<int>> myIntNullOpt3 = nullptr;

    /* 8. Create the following smart pointers to optionals:
     *      Stack      Heap
     *       __        ?__
     *      |  | ----> |hi|
     *      |__|       |__|
     *
     *       __        ?__
     *      |  | ----> |  |
     *      |__|       |__|
     *
     *       __
     *      |  | --->|
     *      |__|
     */

    unique_ptr<optional<string>> myStringNullOpt;
    myStringNullOpt = make_unique<optional<string>>("hi");

    unique_ptr<optional<string>> myStringNullOpt2;
    myStringNullOpt2 = make_unique<optional<string>>(experimental::nullopt);

    unique_ptr<optional<string>> myStringNullOpt3 = nullptr;

    /* 9. Write a nontrivial function (trivial is like a getter or a setter) that takes at least one
     *    smart pointer parameter. Its effects and return value
     *    are up to you. Declare the function above main and
     *    define it below main. Call it here.
     */
    shared_ptr<double> dblPtrFnctn = make_shared<double>(3.0);
    squared(dblPtrFnctn);
    /* 10. Write a function that takes a pointer to a vector of
     *     optionals and an unsigned integer index. Return the
     *     value at that index in the vector. If the index is
     *     out of range, return nullopt. Declare the function
     *     above main and define it below main. Call it here.
     */

    return 0;
}

shared_ptr<double> squared(shared_ptr<double> dblPtr1) {
    shared_ptr<double> finalAmt;
    finalAmt = make_unique<double>(pow(*dblPtr1,2.0));
    return finalAmt;
}