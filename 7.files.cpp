#include<iostream>
using namespace std;

/*
Function without template.
int sum(int a, int b){
    return a+b;
}
*/

template <class T>
T sum(T a, T b){
    return a + b;
}
// The function returns a value of the generic type T, taking two parameters, also of type T.
// Our new function worked exactly as the previous one for integer values did.
// We can use this function with other data types as well.

template <class T, class U>
T smaller(T a, U b){
    return (a < b ? a : b);
}
// The ternary operator checks the a < b condition and returns the corresponding result.
// The expressions ( a < b ? a : b ) is equivalent to the expression if a is smaller than b, return a, else, return b.


int main(){
    /*
    FUNCTION TEMPLATES:
    Functions and classes help to make programs easier to write, safer, and more maintainable.
    However, while functions and classes do have all of those advantages, in certain cases they 
    can also be somewhat limited by C++'s requirement that we specify types for all of our parameters.

    For e.g., we might want to write a function that calculates the sum of two numbers similar to this:

    We can use templates to define functions as well as classes.

    It becomes necessary to write a new function for each new type, such as doubles.
    double sum(double a, double b){
        return a + b;
    }
    Wouldn't it be much more efficient to be able to write one version of sum to work with parameters
    of any type?
    Function templates give us the ability to do that!
    With function templates, the basic idea is to avoid the necessity to specifying an exact type
    of each variable.
    Instead, C++ provides us with the capability of defining the functions using placeholders types, called
    template type parameters.

    To define a function template, use the keyword template, followed by template type definition:
    template <class T>
    We named our template type T, which is a generic data type.
    Now we use our generic data type T in the function

    When creating a template type parameter, the keyword typename may be used as an alternative to the keyword
    class: template <typename T>
    In this context, the keywords are identical.

    Template functions can save a lot of time, because they are written only once, and work with different types.
    Template functions reduce code maintenance, bacause duplicate code is reduced significantly.

    Enhanced safety is another advantage in using template functions, since it's not necessary to manually copy
    functions and change types.

    Function templates also make it possible to work with multiple generic data types.
    Define the data types using a comma-separated list.
    Create a function that compares arguments of varying data types (an int and a double), and prints the smaller one.
    
    template <class T, class U>
    As we can see, this template declares two different generic data types, T and U.

    T is short for Type, and is widely used name for type parameters.
    It's not necessary to use T, however; we can declare our type parameters using any identifiers
    that work for us.
    The only terms we need to avoid are C++ keywords.

    Remember that when we declare a template parameter, we absolutely must use it in our function definition.
    Otherwise, the compiler will complain.
    */
    cout << "47. Function Templates" << endl;

    int x = 7, y = 15;
    cout << sum(x,y) << endl;
    // The function works as expected, but is limited solely to integers.
    double x1 = 7.123, y1 = 2.3232;
    cout << sum(x1, y1) << endl;
    // The compiler automatically calls the function for the corresponding type.
    int x2=566;
    double y2 = 73.3232;
    cout << smaller(x2, y2) << endl;
    // Outputs 73
    // The output converts to an integer, because we specified the function template's return type
    // to be of the same type as the first parameter (T), which is an integer.

    cout << endl << endl;
    /*
    Output:
    22
    9.4462
    73
    */

    return 0;
}