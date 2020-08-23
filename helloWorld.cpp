/*
BASIC CONCEPTS
What is c++?
c++ is general purpose programming language.
c++ is used to create computer programs.
Anything from art applications, music players and even video games!
C++ was derived from C, and is largely used based on it.
*/

/*
FIRST C++ PROGRAM
C++ program is a collection of commands or statements.
Below is a simple code that has "Hello World!" as its output
*/
#include <iostream> 
// C++ offers headers, each of which contains information needed for programs to work properly
// This program calls for the header <iostream>
// The number sign(#) at the beginning of a line targets the compiler's pre-processor.
// In this case, #include tells the pre-processor to include the <iostream> header.
// The <iostream> header defines the standard stream objects that input and output data.

// C++ compiler ignores bland lines.
// In general, black lines serve to imporve the code's readability and structure.
// Whitespace, such as spaces, tabs, and newlines, is also ignored, although it is used to enhance the program's visual attractiveness.

using namespace std;
// The line using namespace std; tells compiler to use the std (standard) namespace.
// the std namespace includes features of the C++ Standard Library

int main(){
// Program executon begins with the main function, int main()
// Curly braces indicate the beginning and the end of the function's body.
// The information inside the brackets indicates what the function does when executed.
// The entry point of every C++ program is main(), irrespective of what the program does.
    cout << "1. Hello World Output!" << endl;
    
    cout << "Hello World!";
    
    cout << endl << endl;
    /*
    Output:
    Hello World!
    */
    

    // The next line, cout << "Hello World!", results the display of "Hello World!" to the screen.
    // In C++, streams are used to perform input and output operations.
    // In most programming environments, the standard default output destination is screen.
    // In C++, cout is the stream output object used to access it.
    // cout is used in combination with insertion operator.
    // Write the insertion operator as << to insert the data that comes after it into the stream that comes before.
    // In C++, the semicolon is used to terminate a statement.
    // Each statement must end with a semicolon.
    // It indicates the end of one logical expression.



    /*
    STATEMENTS:
    - A block is a set of logically connected statements, surrounded by opening and closing curly braces.
    {
        cout << "Hello World!";
        return 0;
    }
    is an example of statements.
    - We can have multiple statements on a single line, as long as we remember to end each statement with a semicolon.
    - Failing to do so will result in an error.
    */
    
    /*
    We can add multiple insertion operators after cout
    */
    cout << "2. Multiple inputs in cout." << endl;
    
    cout << "This " << "is " << "awesome!";
    
    cout << endl << endl;
    /*
    Output:
    This is awesome
    */



    /*
    NEWLINE:
    The cout object does not insert a line break at the end of the output
    One way to print two lines is to use the endl manipulator, which will put in a line break.
    the endl manipulator moves down to a new line to print the second text.
    */
    cout << "3. Use of endl manipulator." << endl;
    
    cout << "Hello World!" << endl;
    cout << "I love programming!";
    
    cout << endl << endl;
    /*
    Output:
    Hello World!
    I love programming!
    */



    /*
    NEW LINES:
    The new line character \n can be used as an alernative to endl.
    The backslach(\) is called an escape character, and indicates a "special" character.
    Two new line characters placed together result in a blank line.

    MULTIPLE NEW LINES:
    Using a single cout statement with as many instances of \n as our program requires will print out multiple lines of text.
    */
    cout << "4. Use of \\n special character." << endl;
    
    cout << "Hello World! \n";
    cout << "I love programming!";
    cout << "Blank line: \n\n";
    cout << "Hello \n world! \n I \n love \n programming!";
    
    cout << endl << endl;
    /*
    Output:
    Hello World!
    I love programming!
    Blank line:

    Hello
     world!
     I
     love
     programming!
    */



    /*
    COMMENTS:
    Comments are explanatory statements that we can include in the C++ code to explain what the code is doing.
    The compilere ignores everything that appears in the comment, so none of that information shows in the result.
    A comment beginning with two slashes (/) is called a single line comment.
    The slashes tell the compiler to ignore everything that follows, until the end of the line.
    When the code below is compiled, it will ignore the // prints "Hellow world" statement and will produce result with only cout statement.

    MULTI-LINE COMMENTS:
    Comments that require multiple lines begin with.
    We can place them on the same line or insert one or more lines between them
    If we write wrong code segment, don't delete it immediately. Try to put it into a multi-line comment, and then delete it 
    when we find the right solution.

    USING COMMENTS:
    Comments can be written anywhere, and can be repeated any number of times throughout the code.
    Within a comment marked with multi line comment starter, // characters have no special meaning, and vice versa.
    This allows us to "nest" one comment type with another.
    Adding comments to our code is a good practice.
    It facilitates a clear understanding of the code for us and for others who read it.
    */
    cout << "5. Using comments" << endl;

    //print "Hello world"
    cout << "Hello world!";
    /* This is a comment*/
    /*
    C++ comments can
    span multiple lines
    */
    /*
    Coment out printing of Hello world!
    cout << "Hello world!"; //
    prints Hellow world!
    */
    
    cout << endl << endl;
    /*
    Output:
    Hello world!
    */


    /*
    VARIABLES:
    Creating a variable reserves a memory location, or a space in memory for storing values.
    The compiler requires that we provide a data type for each variable wehen we declare
    C++ offer rich assortment of built-in as well as user defined datat types.
    
    Integer, a built-in type, represents a whole number value.
    Define integer using the keyword int.
    
    C++ requires that we specify the type and the identifier for each variable defined.
    An identifier is a name for a variable, function, class, module, or any other user-defined item.
    An identifier starts with a letter (A-z or a-z) or an undersocre(_), followed by additional letters, underscores, and digits (0-9).
    e.g. define a variable called myVariable that can hold integer values.
    
    Different operating systems can reserve different sizes of memory for the same data type.
    
    C++ programming language is case-sensitive, so myVariable and myvariable are two different identifiers.
    
    Define all variables with a name and a data type before using them in a program.
    In cases in which we have multiple variables of the same type, it is possible to define them in one declaration, separating them with commas.
    
    A variable can be assigned a value, and can be used to perform operations.
    We can create additional variable sum, and add two variables together
    Here, we use + operator to add two numbers.

    Always keep in mind that all variables must be defined with a name and a data type before they can be used.
    */
    cout << "6. Variables" << endl;

    int myVariable = 10;
    cout << myVariable;
    int a,b;
    // defines two variables of type int.
    a = 30;
    b = 15;
    int sum = a + b;
    // Now sum equals 45
    cout << sum; 

    cout << endl << endl;
    /*
    Output:
    45
    */


    /*
    WORKING WITH VARIABLES:
    Declaring Variables: WE have option to assign a value to the variable at the time we declare the variable or to declare it and assign a value later.
    We can also change the value of a variable

    We can assign a value to a variable only in a declared data type.

    User Input: To enable user to input a value, use cin in combination with the extractino operator (>>).
    The variable containing the extracted data follows the operator.
    E.g. shows how to accept user input and store it in the num variable.
    
    As with cout, extractions on cin can be chained to request more than one input in a single statement: cin >> a >> b;

    Accepting User Input: When Program runs, it will display the message "Please enter a number", and then waits for the user to enter a number and press Enter or Return.
    The entered number is stored in the variable a.

    The program will wait for as long as the user needs to type in a number.

    We can accept user input multiple times throughout the program.

    Variables: Specifying the data types is required just once, at the time when the variable is declared.
    After that, the variable may be used without referring to data type.

    Specifying the data type for a given variable more than once results in syntax error.

    The value of variable may be changed as many times as necessary throughout the program.
    */
    cout << "7. Working with Variables" << endl;

    int c;
    int d=42;
    c=10;
    d=3;
    int num;
    // Uncomment below linea to allow user input
    //cin >> num;
    cout << "Please enter a number \n";
    //cin >> a;
    cout << "Enter a number \n";
    //cin >> a;
    cout << "Enter another number \n";
    //cin >> b;
    sum = a + b;
    cout << "Sum is: " << sum << endl;
    int e;
    e = 10;
    e=50;
    cout << e;

    cout << endl << endl;
    /*
    Output:
    Please enter a number
    Enter a number
    Enter another number
    Sum is <value of sum>
    50
    */



    /*
    BASIC ARITHMETIC
    Arithmatic Operators:
    C++ supports these arithmetic operators
    Addition: + : x + y
    Subtraction : - : x - y
    Multiplication : * : x * y
    Division: / : x / y
    Modulus: % : x % y

    Addition: adds its operands together

    We can use multiple arithmetic operators in one line.
    
    Substraction: subtracts one operand from the other.

    Multiplication: multiplies its operands

    Division: divides the first operand by the second.
    Any remainder is dropeed in order to return an integer value here.

    If one or both of the operands are floating point values, the division operator performs floating point division.

    Dividing by 0 will crash our program.

    Modulus: % is informally known as the remainder operator because it returns the remainder after an integer division.

    Operator Precedence: Operator precedence determines the grouping of terms in an expression, which affects how an expression is evaluated.
    Certain operators take higher precedence over others; for example, the multiplication operator has higher precedence over the addition operator.

    The program evaluates 2*2 first, and then adds the result to 5.
    As in mathematics, using parenthesis alters operator precedence.

    Parentheses force the operations to have higher precedence.
    If there are parenthetical expressions nested within one another, the expression within the innermost parentheses is evaluated first.

    If none of the expressions are in parentheses, multiplicative
    [multiplication, division, modulus] operators will be evaluated befoer additive(addition, substraction) operators.
    */
    cout << "8. Basic Arithmetics." << endl;

    int x = 40 + 60;
    cout << x << endl;
    x = 100 - 60
    cout << x << endl;
    x = 5*6;
    cout << x << endl;
    x = 10/3
    cout << x << endl;
    x = 25 % 7;
    cout << x << endl;
    x = 5 + 2 * 2
    cout << x << endl;
    //outputs 14
    x = (5 + 2) * 2
    cout << x << endl;
    //outputs 14
    cout << endl << endl;
    /*
    Output:
    100
    40
    30
    3
    4
    9
    14
    */



    /*
    ASSIGNMENT AND INCREMENT OPERATORS
    Assignment Operators: The simple operator (=) assigns the right side to the left side.

    C++ provides shorthand operators that have the capability of performing an operation and an assignment at the same time.
    
    Assignment operator (=) assigns the right side to the left side.

    The same shorthand syntax applies to multiplication, division, and modulus operators.

    Increment Operator: the increment operator is used to increase an integer's value by one, and is a commonly used c++ operator.

    Increment Operator has two forms, prefix and postfix.

    Prefix increments the value, and then proceeds with the expression.
    Postfix evaluates the expression and then performs the incrementing.

    The prefix example increments the value of x, and then assigns it to y.
    The postfix example assigns the value of x to y, and then increments it.

    Decrement Operator: the decrement operator (-) works in much the same way as the increment operator, but instead of increasing the value, it decreases it by one.
    */
    cout << "9. Assignment and increment operators" << endl;

    x = 10;
    x += 4; // equivalent to x = x + 4
    x -= 5; // equivalent to x = x - 5
    x *= 3; // equivalent to x = x * 3
    x /= 2; // equivalent to x = x / 2
    x %= 4; // equivalent to x = x % 4
    x++; // equivalent to x = x + 1
    x = 11;
    x++;
    cout << x << endl;
    // outputs 12
    ++x; // prefix
    x++; // postfix
    x = 5;
    y = ++x;
    // x is 6, y is 6
    x = 5;
    y = x++;
    // x is 6, y is 5
    --x; // prefix
    x--; // postfix

    cout << endl << endl;
    /*
    Output:
    12
    */


    
    return 0;
    /*
    RETURN:
    - The last instruction in the program is the return statement.
    - The line return 0; terminates the main() function and causes it to return the value 0 to the calling process.
    - A non-zero value (usually of 1) signals abnormal termination.
    - If the return statement is left off, the C++ compiler implicitly inserts "return 0;" to end of the main() function.
    */

   /*
    COMPILE:
    g++ <file-name> -o <output-file>
    e.g. g++ helloWorld.cpp -o helloWorld.out

    RUN THE OUTPUT FILE:
    ./<output-file>
    e.g. ./helloWorld.out
   */
}