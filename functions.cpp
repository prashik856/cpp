#include<iostream>
using namespace std;

void printSomething(){
    cout << "Hi there!" << endl;
}
// Here's an example, we define a function that does not return a value
// and just prints a line of text to the screen.
// our function, entitled printSomething, returns void, and has no parameters.
// We must declare a function prior to calling it.
// Putting the declaration after the main() function results in an error.

//Function declaration
void printSomethingElse();

int main(){
    /*
    INTRODUCTION TO FUNCTIONS:
    A function is a group of statements that perform a particular task.
    We may need to define our own functions in c++.

    Using functions can have many advantages, including the following.
    - We can reuse the code within a function.
    - We can easily test individual functions.
    - If it's necessary to make any code modifications, we can make modifications within a single 
    function, without altering the program structure.
    - We can use the same function for different inputs.
    Every valid C++ program has at least one function - the main() function.

    The Return type:
    The main function takes the following general form:
    int main(){
        //some code
        return 0;
    }
    A function's return type is declared before its name.
    In the example above, the return type is int, which indicates that the function returns an integer value.
    Occasionally, a function will perform the desired operations without returning a value.
    Such functions are defined with the keyword void.
    viod is a basic data type that defines a valueless state.

    Defining a function:
    Define a C++ function using the following syntax:
    return_type function_name(parameter list){
        body of the function
    }
    return_type: Data type of the value returned by the function.
    function_name: Name of the function
    parameters: When a function is invoked, we pass a value to the parameter.
    This value is referred to as actual parameter or argument.
    The parameter list refers to the type, order, and number of the parameters of a function.
    body of the function: A collection of statements defining what the function does.
    Parameters are optional; that is, we can have a function with no parameters.

    A function declaration, or function prototype, tells the compiler about a function name and how to call the function.
    The actual body of the function can be defined separately.
    */
    cout << "24. Functions" << endl;

    printSomething();
    // We can use our function in main() as above code.
    // To call a function, we simply need to pass the required parameters along with the function name.

    cout << endl << endl;




    return 0;
}

// Function Definition
void printSomethingElse(){
    cout << "Hi there!" << endl;
}
/*
Function declaration is required when we define a function in one source file and we call that function in another file.
In such case, we should declare the function at the top of the file calling the function.
*/

