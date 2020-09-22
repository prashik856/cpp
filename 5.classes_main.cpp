/*
    To use our classes in our main, we need to include the header file.
    For e.g., to use our newly created MyClass in main:
*/
#include <iostream>
#include "MyClass.h"
using namespace std;
// The header declares "what" a class (or whatever is being implemented) will do, while the cpp source file 
// defines "how" it will perform those features.


class Birthday {
    public:
        Birthday(int m, int d, int y):month(m), day(d), year(d){
            // Constructor
        }
        void printDate(){
            cout << month << "/" << day << "/" << year << endl;
        }
    private:
        int month;
        int day;
        int year;
};
// Birthday class has three member variales. 
// It also has a constructor that initializers the members using a member initialization list.
// The class was declared in a single file for the sake of simplicity.
// Alternatively, we could use header and source files.
// Adding printDate() function in the birthday Class.

class Person{
    public:
    
    private:
};



int main(){
    MyClass obj;

    /*
    DESTRUCTORS:
    Destructors are special functions, as well.
    They're called when an object is destroyed or deleted.

    Objects are destroyed when they go out of scope, or whenever the delete expression
    is applied to a pointer directed at an object of a class.

    The name of a destructor will be exactly the same as the class, only prefixed with a tilde(~).
    A destructor can't return a value or take any paramters.

    We declare a destructor in the header file of MyClass.h
    After declaring the destructor in the header file, we can write the implementation in the 
    source file MyClass.cpp

    Since destructors can't take parameters, they also can't be overloaded.
    Each class will have just one destructor.

    Defining a destructor is not mandatory.
    If we don't need one, we don't have to define one.
    */
    cout << "35. Destructors" << endl;

    // Destructors can be very useful for releasing resources before coming out of the program.
    // This can include closing files, releasing memory, and so on.
    // In main, we included the class' header file and then created an object of that type.
    // This returns the output of Constructor and Destructor function that we have defined.
    // When the program runs, it creates the object and calls the constructor.
    // The object is deleted and the destructor is called when the program's execution is completed.
    // So we printed "Constructor" from the constructor and "Destructor" from the destructor.

    cout << endl << endl;
    /*
    Outpus:
    Constructor
    Destructor
    */



    /*
    SELECTION OPERATOR:
    We created separate header and source files for our class, which resulted in our header file MyClass.h

    ifndef: stands for "if not defined". This first pair of statements tells the program to define the
    MyClass header file if it has not been defined already.
    endif: ends the condition

    This prevents a header file from being included more than once within one file.

    Dot Operator:
    We'll create an object of the type MyClass, and call its myPrint() function using the dot(.) operator.

    Pointers:
    We can also use pointer to access the object's members.
    We can do this as implemented below.

    The arrow member selection operator (->) is used to access an object's members with a pointer.
    */
    cout << "36. Selection Operator" << endl;

    // Create a sample function called myPrint() in our class.
    MyClass obj1;
    obj1.myPrint();
    MyClass *ptr;
    ptr = &obj1;
    // We have defined a pointer of type MyClass.
    // The type of the pointer is MyClass, as it points to an object of that type.
    ptr->myPrint();
    // When working with an object, use the dot member selection operator (.).
    // When working with pointer to the object, use the arrow member selection operator (->).

    cout << endl << endl;
    /*
    Outputs:
    Hello
    */


    /*
    CONST OBJECTS:
    a constant is an expression with a fixed value.
    It cannot be changed while the program is running.
    Using the const keyword to define a constant variable.

    Constant Object:
    As with the built-in data types, we can make class objects constant by using the const keyword.
    All const variables must be initialized when they're creaed.
    In the case of classes, this initialization is done via constructors.
    If a class is not initialized using a parameterized constructor, a public 
    default constructor must be provided - if no public constructor is provided,
    a compiler error will occur.

    Once a const class object has been initialized via the constructor, we cannot modify the object's member
    variables.
    This includes both directly making changes to public member variables and calling member functions that set
    the value of member variables.
    When we've used const to declare an object, we can't change its data members during the objects lifetime.

    Only non-const objects can call non-const functions.
    A constant object can't call a regular function.
    Hence, for a constant object to work, we need a constant function.

    To specify a function as a const member, the const keyword must follow the function prototype, outside of its
    parameters' closing parenthesis.
    For const member functions that are defined outside of the class definition, the const keyword must be used 
    on both the function prototype and definition.

    Attempting to call a regular function from a constant object results in an error.
    In addition, a compiler error is generated when any const member function atempts to change
    a member variable or to call a non-const member function.

    Defining constant objects and functions ensures that corresponding data members cannot be 
    unexpectedly modified.
    */
    cout << "37. Const Objects" << endl;

    const int x = 42;
    // A constant variable must be initialized at the time of their creation.
    const MyClass obj2;
    obj2.myPrint();

    cout << endl << endl;
    /*
    Outputs:
    Hello constant
    */



    
    /*
    MEMBER INITIALIZERS:
    Constant variables are variables that cannot be changed, and that all const variables must be
    initialized at the time of creation.
    C++ Provides a handy syntax for initializing members of the class called the member initializer list
    (also called a constructor initializer)

    The initialization list eliminates the need to place explicit assignments in the constructor body.
    Also, the initialization list does not end with a semicolon.

    The member initialization list may be used for regular variables, and must be used for constant variables.
    Even in cases in which member variables are not constant, it makes good sense to use the member initializer syntax.
    */
    cout << "38. Member initializers" << endl;

    cout << endl << endl;




    /*
    COMPOSITIONS:
    In the real world, complex objects are typically built using smaller, smipler objects.
    For e.g., a car is assembled using a metal frame, an engine, tires, and a large number of
    other parts.
    This process is called composition.

    In C++, object composition involves using classes as member variables in other classes.
    This sample program demonstrates composition in action.
    It contains Person and Birthday classes and each Person will have Birthday object as its member.
    */

    return 0;
}