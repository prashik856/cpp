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


template <class T>
class Pair{
    private:
        T first, second;
    public:
        Pair(T a, T b): first(a), second(b) {

        }
        T bigger();
};
// The code above declares a class template Pair, with two private variables of a generic type, and one
// constructor to initialize the variables.

template <class T>
T Pair<T>::bigger(){
    return (first > second ? first : second);
}
// A specific syntax is required in case we define our member functions outside of our class.
// The bigger function returns the greater value of the two member variables.
// the ternary operator compares the two variables, returning the greater one.

template <class T>
class Special{
    public:
        Special(T x){
            cout << x << " - not a char" << endl;
        };
};
// As a regular class template, Special treats all of the various data types in the same way.
// To create differnt behavior for the data type char, we would create a template specialization.

template < >
class Special<char>{
    public:
        Special(char x){
            cout << x << " is a char!" << endl; 
        }
};
// Notice that we precede the class name with template<>, including an empty parameter list.
// This is because all types are known and no template arguments are required for this specialization,
// but still, it is the specialization of a class template, and thus it requires to be noted as such.
// But more important than this prefix, is the <char> specialization parameter after the class template name.
// This specialization parameter itself identifies the type for which the template class is being specialized (char)
/*
In the exapmle above, the first class is the generic template, while the second is the specialization.
If necessary, our specialization can indicate a completely different behavior from the behavior of the generic template.
*/


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


    CLASS TEMPLATES:
    Just as we can define function templates, we can also define class templates, allowing classes to have members
    that use template parameters as types.
    The same syntax is used to define the class template:

    template <class T>
    class MyClass{

    };
    Just as with function templates, we can define more than one generic type by using a comma separated list.
    Create a class Pair, that will be holding a pair of values of a generic type.

    A specific syntax is required in case we define our member functions outside of our class, 
    for e.g., in a separate source file.
    We need to specify the generic type in angle brackets after the class name.
    For e.g., to have a member function bigger() defined outside of the class.

    To create objects of the template class for different types, specify the data type in angle brackets,
    as we did when defining the function outside of the class.
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
    Pair <int> obj(11, 22);
    cout << obj.bigger() << endl;
    // outputs 22
    Pair <double> obj1(23.43, 5.34);
    cout << obj1.bigger() << endl;
    // outputs 23.43

    cout << endl << endl;
    /*
    Output:
    22
    9.4462
    73
    22
    23.43
    */



    /*
    TEMPLATE SPECIALIZATION
    In case of regular class templates, the way the class handles different data types is the same, the same code
    runs for all data types.
    Template specialization allows for the definition of a different implementation of a template when a 
    specific type is passed as a template argument.
    For e.g., we might need to handle the character data type in different manner than we do numeric data types.
    To demonstrate how this works, we can first create a regular template.

    Keep in mind that there is no member "inheritance" from the generic template to the specialization, so 
    all members of the template class specializations must be defined on theri own.
    */
    cout << "48. Template Specialization" << endl;

    Special<int> ob1(42);
    Special<double> ob2(5.47);
    Special<char> ob3('s');
    // As we can see, the generic template worked for int and double, however, our template specialization
    // was invoked for the char data type.

    cout << endl << endl;
    /*
    Output:
    42 - not a char
    5.47 - not a char
    s is a char!
    */

    return 0;
}