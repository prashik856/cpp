#include<iostream>
using namespace std;

int main(){
    /*
    EXCEPTIONS:
    Problems that occur during the program execution are called exceptions.
    In C++ exceptions are responses to anomalies that arises while the program is running, such as an attempt to
    divide by zero.

    Throwing Exceptions:
    C++ exception handling is build upon three keywords: try, catch and throw
    throw is used to throw an exception when a problem shows up.

    Catching Exceptions:
    A try block identifies a block of code that will activate specific exceptions.
    It's followed by one or more catch blocks.
    The catch keyword represents a block of code that executes when a particular exception is thrown.
    Code that could generate an exception is surrounded with the try/catch block.
    We can specify what type of exception we want to catch by the exception declaration that appears
    in parentheses following the keyword catch.
    Multiple catch statements may be listed to handle various exceptions in case multiple exceptions
    are thrown by the try block.

    Exception Hanlding:
    Exception handling is particularly useful when dealing with user input.
    For example, for a program that requests user input of two numbers, and then
    outputs their division, be sure that we handle division by zero, in case our user enters
    0 as a second number.
    */
    cout << "49. EXCEPTIONS" << endl;

    try{
        int motherAge = 29;
            int sonAge = 36;
            if (sonAge > motherAge){
               throw 99;
            }
    }
    catch(int x){
        cout << "Wrong age values - Error - " << x;
    }
    // The code looks at sonAge and motherAge, and throws an exception if sonAge
    // is found to be greater of the two.
    // In the throw statement, the operand determines a type for the exception.
    // The type of the expression's result will determine the type of the exception thrown
    // The try block throws the exception, and the catch block then handles it.
    // The error code 99, which is an integer, appears in the throw statement, so it results
    // in an exception of type int.

    try{
        int num1;
        cout << "Enter first number: " << endl;
        //cin >> num1;
        cout << "Enter second number: " << endl;
        //cin >> num2;

        if (num2 == 0){
            throw 0;
        }

        cout << "Result: " << num1/num2 << endl;
    }
    catch(int x){
        cout << "Division by zero!" << endl;
    }
    // This results in the output of "Division by zero!" as an alternative to
    // a program crash, when 0 is entered as the second number
    // In our case, we catch exceptions of type integer only.
    // It is possible to specify that our catch block handles an type of exception
    // thrown in a try block.
    // To accomplish this, add an ellipsis(...) between the parentheses of catch.

    /*
    try{
        //code
    } catch(...){
        // code to handle exceptions
    }
    */

    // This program works perfectly if the user enters any number besides 0.
    // In case of 0, the program crashes, so we need to handle that input.

    // In the event that the second number is equal to 0, we need to throw an exception.
    // The code throws an exceptinon with the code 0 of type integer.
    // We can add try/catch to handle these exceptions

    cout << endl << endl;

    return 0;
}