#include "MyClass2.h"
#include<iostream>
using namespace std;

// This class has two members variables, regVar and constVar.
// It also has a constructor that takes two parameters, which are used to initialize the member variables.
// Running this code returns and error, because one of it's member variables is a constant, which cannot be 
// assigned a value afer declaration.
// In cases like this one, a member initializatino list can be used to assign values to the member variables.
MyClass2::MyClass2(int a, int b): regVar(a), constVar(b){
    cout << regVar << endl;
    cout << constVar << endl;
}
// Note that, in the syntax, the initialization list follows the constructor parameters.
// The list begins with a colon (:), and then lists each variable to be initialized, along with the 
// value for that variable, with a comma to separate them.
// Using the syntax variable(value) to assign values.

// We have added cout statements in the constructor to print the values of the member variables.
// The constructor is used to create the object, assigning two parameters to the member variables via the 
// member initialization list.