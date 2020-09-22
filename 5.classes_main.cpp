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
        Person(string nameValue, Birthday birthdayValue): name(nameValue), birthday(birthdayValue) {

        }
        void printInfo(){
            cout << name << endl;
            birthday.printDate();
        }
        // Notice that we call the birthday member's printDate() function, since it's of type Birthday,
        // which has that function defined.
    private:
        string name;
        Birthday birthday;
};
// We create Person class, which includes the Birthday class.
// The Person class has a name and a Birthday member, and a constructor to initialize them.
// Ensure that the corresponding header files are included (If created).


class MyClass3 {
    public:
        MyClass3(int a): var(a){

        }
        void printInfo(){
            cout << var << endl;
            cout << this->var << endl;
            cout << (*this).var << endl;
        }
        // printInfo() method offers three alternatives for printing the member variable of the class.
        // this is a pointer to the object, so the arrow selection operator is used to select the member variable.
    private:
        int var;
};


class MyClass4 {
    private:
    public:
        int var;
        MyClass4() {}
        MyClass4(int a): var(a){}
    
    // Now, we need to define what our function does.
    // We need our + operator to return a new MyClass4 object with a member variable equal to sum of the 
    // two object's member variables.
    MyClass4 operator+(MyClass4 &obj){
        MyClass4 res;
        res.var = this->var+obj.var;
        return res;
    }
    // Here, we declared a new res object.
    // We then assigned the sum of the member variables of the current object (this) and the parameter object (obj)
    // to the res object's var member variable.
    // The res object is returned as the result
    // This gives us the ability to create objects in main and use the overloaded + operator to add them together.
    
};
// A simple class to demonstrate operator overloading.
// Our clss has two constructors and one member variable.
// We will be overloading the + operator, to enable adding two objects of our class together.


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

    Composition is used for objects that share a has-a relationship, as in "A Person has a Birthday.".

    Now, we've defined our Birthday and Person classes, we can go to our main, create a Birthday object,
    and then pass it to a Person object.

    In general, composition serves to keep each individual class relatively simple, straightforward,
    and focused on performing one task.
    It also enables each sub-object to be self-contained, allowing for reusability (we can use the Birthday
    class within various other classes.)
    */
    cout << "39. Compositions" << endl;

    Birthday birthday(2,21,1996);
    Person person("Prashik", birthday);
    person.printInfo();
    // We've created a Birthday object for the date of 2/21/1996.
    // We then created a Person object and passed the Birthday object to its constructor.
    // We then used the Person object's printInfo() function to print its data.

    cout << endl << endl;
    /*
    Prashik
    2/21/1996
    */


    /*
    FRIEND FUNCTIONS:
    Normally, private members of a class cannot be accessed from outside of that class.
    However, declaring a non-member function as a friend of a class allows it to access the 
    class' private members.
    This is accomplished by including a declaration of this external funciton within the class, and 
    preceding it with the keyword friend.
    In the example below, someFunc(), which is not a member funciton of the class, is a friend of MyClass
    and can access its private members.

    We can declare a function friend across any number of classes.
    Similar to friend functions, we can define a friend class, which has access to the private members of another class.
    */
    cout << "40. Friend Functions" << endl;

    // Create new object and call friend function.
    MyClass obj;
    someFunc(obj);
    // someFunc() has the ability to modify the private member of the object and print its value.
    // Typical use cases of friend functions are operations that are conducted between two different classes
    // accessing private members of both.

    cout << endl << endl; 



    /*
    THE THIS KEYWORD:
    Every object in C++ has access to its own address through an important pointer called the this pointer.
    Inside a member function this may be used to refer to the invoking object.

    Friend functions do not have a this pointer, because friends are not members of a class.

    We may be wondering why it's necessary to use the this keyword, when we have the option
    to directly specifying the variable.

    The this keyword has an important role in operator overloading.
    */
    cout << "41. The this keyword" << endl;

    MyClass3 obj3(42);
    obj3.printInfo();
    // All three of the ways to access the member variable work.
    // Only member functions have a this pointer.

    cout << endl << endl;
    /*
    Outputs:
    42
    42
    42
    */



    /*
    OPERATOR OVERLOADING.
    Most of the C++ built-in operators can be redefind or overloaded.
    Thus, operators can be used with user-defined types as well (for e.g., allowing us to add two objects together.)

    Operators that can't be overloaded are :: | .* | . | ?: [only 4]
    All other operators can be overloaded.

    Overloaded operators are functions, defined by the keyword operator followed by the symbol for the operator being defined.
    An overloaded operator is similar to other functions in that it has a return type and a parameter list.

    In our example, we will be overloading the + operator.
    It will return an object of our class as its parameter.

    With the overloaded operators, we can use any custom logic needed.
    However, it's not possible to alter the operator's precedence, grouping, or number of operands.
    */
    cout << "42. Operator Overloading" << endl;

    MyClass4 obj4(12), obj5(13);
    MyClass4 res = obj4 + obj5;
    cout << res.var << endl;

    cout << endl << endl;
    /*
    Output:
    25
    */



    return 0;
}