#include<iostream>

// To include rand() function 
#include<cstdlib>

// To include time() function.
#include<ctime>

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


//Function with arguments
void printSomethingElse2(int x){
    cout << x;
}


int timesTwo(int x){
    return x*2;
}
// The function defined above takes one integer parameter and returns its value, multiplied by 2.
// We can now use that function with different arguments.


int addNumbers(int x, int y){
    return x + y;
}
// As defined, the addNumbers function takes two parameters of type int and returns int.
// Data type and name should be defined for each parameter.


int addMultipleNumbers(int x, int y, int z, int a){
    return x + y + z + a;
}
// If we have multiple parameters, remember to separate them with commas, both when declaring them and when 
// passing the arguments.


// Default Argument Function
int sum(int a, int b=42){
    return a + b;
}
// This assigns a default value of 42 to the b parameter.
// If we call the function without passing the value for the b parameter, the default value will be used.


// Another example of default argument function
int volume(int l=1, int w=1, int h=1){
    return l*w*h;
}


// Function Overloading Example
void printNumber(int a){
    cout << a << endl;
}
// This is effective with integer arguments only.
// Overloading it will make it available for other types such as floats.
void printNumber(float a){
    cout << a << endl;
}
// Now, the same printNumber() function name will work for both integers and floats.


// Recursion funciton
int factorial(int n){
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
/*
The if statement defines the exit condition.
In this case, it's when n equals one, return 1 ( the factorial of one is one).
We placed the recursive function call in the else statement, which returns n multiplied by 
the factorial of n-1.
for e.g., if you call the factorial funciton with the argument 4, it will execute as follows:
return 4 * factorial(3), which is:
4 * 3 * factorial(2) => 4 * 3 * 2 * factorial(1) => 4 * 3 * 2 * 1
The factorial function calls itself, and then condinues to do so , until argument equals 1.
*/

// Arrays and Functions
void printArray(int arr[], int size){
    for(int x = 0; x<size; x++){
        cout << arr[x] << endl;
    }
}
// We can use our function in main(), and call it for our sample array.


// Passing by Value example
void myFunc(int x) {
    x = 100;
}


// Passing by Reference
void myFunc(int *x) {
    *x = 100;
}


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



    /*
    FUNCTION PARAMETERS:
    For a function to use arguments, it must declare formal parameters, which are variables
    that accept the argument's values.

    for e.g.
    void printSomething(int x){
        cout << x;
    }

    This defines a function that takes one integer parameter and prints its value.
    Formal parameters behave within the function similarly to other local variables.
    They are created upon entering the function, and are destroyed upon exiting the funtion.

    Once parameters have been defined, we can pass the corresponding arguments when the function is called.

    We can pass different arguments to the same function.

    Multiple Parameters:
    We can define as many parameters as we want for our functions, by separating them with commas.
    
    */
    cout << "25. Function Parameters" << endl;

    printSomethingElse2(42);
    // Outputs 42
    // The value 42 is passed to the function as an argument, and is assigned to the formal parameter
    // of the function: x.
    // Making changes to the parameter within the function does not alter the argument.
    cout << timesTwo(8) << endl;
    cout << timesTwo(5) << endl;
    cout << timesTwo(42) << endl;
    // Outputs
    // 16
    // 10
    // 84
    cout << addNumbers(4,5) << endl;
    // Outputs 9
    cout << addMultipleNumbers(1,2,3,4) << endl;
    // Outputs 10

    cout << endl << endl;
    /*
    Output:
    42
    16
    10
    84
    9
    10
    */




    /*
    RANDOM NUMBERS:
    Being able to generate random numbers is helpful in a number of situations, including when creating games,
    statistical modeling programs, and similar end products.

    In the C++ standard library, we can access a pseudo random number generator function that's called rand().
    When used, we are required to include the header <cstdlib>. 

    A for loop can be used to generate multiple random numbers.   

    Use the modulo(%) operator to generate random numbers within a specific range.

    However, the rand() function will only return a pseudo random number.
    This means that each time the code is run, it generates the same numbers.

    The srand() Function:
    The srand() function is used to generate truly random numbers.
    This function allows to specify a seed value as its parameter, which is used for the rand() funciton's algorithm.

    Truly Random Numbers
    A solution to generate truly random numbers, is to use the current time as a seed value for the srand() funcion.
    Here, we make use of the time() function to get the number of seconds on our system time, and randomly seed the rand()
    function. For this, we need to include <ctime> header.
    */
    cout << "26. Random Numbers" << endl;

    cout << rand() << endl;
    // This will output a random number
    for(int x = 1; x <= 10; x++){
        cout << rand() << endl;
    }
    for(int x = 1; x <= 10; x++){
        cout << 1 + (rand() % 6) << endl;
    }
    srand(98);
    for(int x = 1; x <= 10; x++){
        cout << 1 + (rand() % 6) << endl;
    }
    // Changing the seed value changes the return of rand().
    // However, the same argument will result in the same output.
    srand(time(0));
    for(int x = 1; x <= 10; x++){
        cout << 1 + (rand() % 6) << endl;
    }
    // time(0) will return the current second count, prompting the srand() function to set a different seed
    // for the the rand() function each time the program runs.
    // using this seed value will create a different output each time we run the program.

    cout << endl << endl;
    /*
    Output:
    <random-number>
    10 random-numbers are printed by for loop.
    10 random-numbers which are less than 6  and >= 1 are printed.
    10 random-numbers which are less than 6  and >= 1 are printed.
    10 random-numbers which are less than 6  and >= 1 are printed.
    */


    /*
    DEFAULT ARGUMENTS:
    Default values for Parameters:
    When defining a function, we can specify a default value for each of the last parameters.
    If the correspoding argument is mising when we call a function, it uses the default value.

    To do this, use the assignment operator to assign values to the arguments in the functions
    definition.
    */
    cout << "27. Default Arguments" << endl;

    int x = 24;
    int y = 36;
    // Calling the function with both parameters
    int result = sum(x, y);
    cout << result << endl;
    // Outputs 60
    // Calling the function without b
    result = sum(x);
    cout << result << endl;
    // Outputs 66
    // The second call to the function does not pass a value for the second parameter, and the default 
    // value of 42 is used.
    cout << volume() << endl;
    cout << volume(5) << endl;
    cout << volume(2,3) << endl;
    cout << volume(3,7,6) << endl;
    // As we can see, default parameter values can be used for calling the same function in different
    // situations, when one or more of its parameters are not used.

    cout << endl;
    /*
    Output:
    60
    66
    1
    5
    6
    126
    */


    /*
    FUNCTION OVERLOADING:
    Function overloading allows to create multiple functions with the same name, so long as they 
    have different parameters.
    e.g. we might need a printNumber() function that prints the value of its parameter.

    When overloading functinos, the definition of the function must differ from each other by the
    types and/or the number of arguments in the argument list.

    We CAN NOT overload function declarations that differ only by return type.
    int printName(int a) {}
    float printName(int b) {}
    double printName(int c) {}
    Although each function uses the same name, the only difference from one to the other is the return type,
    which is not allowed.
    */
    cout << "28. Function Overloading" << endl;

    int a = 15;
    float b = 54.541;
    printNumber(a);
    printNumber(b);
    // The function call is based on the argument provided.
    // An integer argument will call the function implementation that takes an integer parameter.
    // A float argument will call the implementation taking a float parameter.

    cout << endl << endl;
    /*
    Output:
    15
    54.541
    */


    /*
    RECURSION:
    A recursive function in C++ is a function that call itself.
    To avoid having the recursion run indefinitely, we must include a termination condition.

    To demonstrate recursion, let's create a program to calculate a number's factorial.
    In mathematics, the term factorial refers to the product of all positive integers that are less than
    or equal to a specific non-negative integer(n).
    The factorial of n is denoted by n!.

    For e.g. 4! = 4 * 3 * 2 * 1 = 24
    
    Recursion is a method of solving a problem where the solution depends on the solutions
    to smaller instances of the same problem

    We need to keep in mind that a base case is necessary for real recursion.
    Without it, the recursion will keep running forever.
    */
    cout << "29. Recurion" << endl;

    cout << factorial(5) << endl;

    cout << endl << endl;
    /*
    Output:
    120
    */


    /*
    PASSING ARRAYS TO FUNCTIONS:
    An array can also be passed to a function as an argument.
    The parameter should be defined as an array using square brackets, when declaring the function.
    Remember to specify the array's name without square brackets when passing as an argument to a function.

    There are two ways to pass arguments to a function as the function is being called.
    By value:
    This method copies the argument's actual value into the function's formal parameter. 
    Here, we can make changes to the parameter within the function without having any effect on the argument.

    By reference:
    This method copies the argument's reference into the formatl parameter.
    Within the function, the reference is used to access the actual argument used in the call.
    This means that any change made to the parameter affects the argument.
    
    By default, C++ used call by value to pass arguments.

    Summary:
    In general, passing by value is faster and more effective.
    Pass by reference when our function needs to modify the argument, or when we need to pass a data type, 
    that uses a lot of memory and is expensive to copy.
    
    */
    cout << "30.Arrays and Functions" << endl;

    int myArr[3] = {42, 44, 898};
    printArray(myArr, 3);
    // The printArray function takes an array as its parameter (int arr[]), and iterates over the array using a for loop.
    // We call the function in main(), which is where we pass the myArr array to the function which prints its elements.
    int var = 20;
    myFunc(var);
    cout << var << endl;
    // By default, arguments in C++ are passed by value.
    // When passed by value, a copy of the argument is passed to the function.
    // Because a copy of the argument is passed to the function, the original argument is not modified by the function.
    myFunc(&var);
    cout << var << endl;
    // Pass-by-reference copies an argument's address into the formal parameter.
    // Inside the function, the address is sued to access the actual argument used in the call.
    // This means that changes made to the parameter affect the argument.
    // To pass the value by reference, argument pointers are passed to the functions just like any other value.
    // We passed the variable directly to the fucntion using the address-of-operator &
    // The function declaration says that the function takes a pointer as its parameter (defined using the * operator).
    // AS a result, the function has actually changed the argument's value, as accessed it via the pointer.

    cout << endl << endl;
    /*
     Outputs:
     42
     44
     898
     20
     100
    */

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

