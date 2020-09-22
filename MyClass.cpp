#include "MyClass.h"
#include<iostream>
using namespace std;
/*
SCOPE RESOLUTION OPERATOR:
The double colon in the source file (.cpp) is called the scope resolution operator, and it's used for the 
constructor definition.
The scope resolution operator is used to define a particular class' member functions, 
which have already been declared.
Remember that we have defined the constructor prototype in the header file.

So, basically, MyClass::MyClass() refers to the MyClass() member function - or, in this case, constructor - 
of the MyClass class.

*/

// We have included <iostream> header to use the cout

MyClass::MyClass(){
// code here.
    cout << "Constructor" << endl;
}

MyClass::~MyClass(){
    cout << "Destructor" << endl;
}

void MyClass::myPrint(){
    cout << "Hello" << endl;
    // Since myPrint() is a regular member function, it's necessary to specify its return type in both 
    // the declaration and the definition.
}

void MyClass::myPrint() const {
    cout << "Hello constant" << endl;
    // Now the myPrint() function is a constant member function.
    // As suchk it can be called by our constant ojbect.
}

/*
void MyClass::MyClass(int a, int b){
    regVar = a;
    constVar = b;
}
*/
