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
    x = 100 - 60;
    cout << x << endl;
    x = 5*6;
    cout << x << endl;
    x = 10/3;
    cout << x << endl;
    x = 25 % 7;
    cout << x << endl;
    x = 5 + 2 * 2;
    cout << x << endl;
    //outputs 14
    x = (5 + 2) * 2;
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
    int y = ++x;
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


    /*
    THE if STATEMENT:
    The if statement is used to execute some code if a condition is true
    Syntax:
    if (condition){
        statements
    }
    The condition specifies which expression is be be evaluated.
    If the condition is true, the satements in the curly brackets are executed.

    If the condition is false, the statements are simply ignored, and the program continues to run after the if statement body.

    We use rational operators to evaluate conditions.

    The if statement evaluates the condition (7>4), finds it to be true, and then executes the cout statement.
    If we change the greater operator to a less than operator (7<4), the statement will not be executed and nothing will be 
    printed out.
    
    A condition specified in an if statement does not require a semicolon.

    Rational Operators: Additional rational operators
    >=  :   Greater than or equal to    : 7 >= 4    True
    <=  :   Less than or equal to       : 7 <= 4    False
    ==  :   Equal to                    : 7 == 4    False
    !=  :   Not equal to                : 7 != 4    True
    The not equal to operator evaluates the operand, determines whether or not they are equal.
    If the operands are not equal, the condition is evaluated to be true.
    The example of not equal to operator, the condition in if statement evaluates to false and the block
    of code is not executed.

    We can use the rational operators to compare variables in the if statement.
    */
    
    cout << "10. The if Statement." << endl;

    if (7 > 4){
        cout << "Yes" << endl;
    }
    //Outputs "Yes"
    if (10 == 10){
        cout << "Yes" << endl;
    }
    //Outputs "Yes"
    if (10 != 10){
        cout << "Yes" << endl;
    }
    a = 55;
    b = 33;
    if(a > b){
        cout << "a is greater than b" << endl;
    }
    //Outputs "a is greater than b"

    cout << endl << endl;
    /*
    Output:
    Yes
    Yes
    a is greater than b
    */



    /*
    THE else STATEMENT
    An if statement can be followed by an optional else statement, which executes when the condition is false.
    Syntax:
    if (condition){
        //statements
    }
    else{
        //statements
    }
    The code above will test the condition:
        - if it evaluates to true, then the code inside the if statement will be executed.
        - if it evaluates to false, then the code inside the else statement will be executed.
    
    When only one statement is used inside the if/else, then curly braces can be omitted.

    We may include many statements inside if/else statement.

    Nested if Statements: We can also include, or nest, if statements within another if statement.

    Nested if else Statements: C++ provides an option of nesting an unlimited number of if/else statements.

    Remember that all else statements must have corresponding if statements.

    In if/else statements, a single statement can be included without enclosing it into curly braces
    */
    cout << "11. The else Statement" << endl;

    int mark = 90;
    if(mark < 50){
        cout << "You failed." << endl;
    } else{
        cout << "You passed." << endl;
    }
    //Outputs "You passed."
    if(mark < 50){
        cout << "You failed." << endl;
        cout << "Sorry" << endl;
    } else{
        cout << "Congratulations!" << endl;
        cout << "You passed." << endl;
        cout << "You are awesome!" << endl;
    }
    mark = 100;
    if (mark >= 50){
        cout << "You passed." << endl;
        if (mark == 100){
            cout << "Perfect!" << endl;
        }
    } else {
        cout << "You failed." << endl;
    }
    int age = 18;
    if (age > 14) {
        if (age >= 18) {
            cout << "Adult" << endl;
        } else {
            cout << "Teenager" << endl;
        }
    } else {
        if (age > 0) {
            cout << "Child" << endl;
        } else {
            cout << "Something's wrong" << endl;
        }
    }
    a = 10;
    if (a > 4)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << endl << endl;
    /*
    Output:
    You passed.
    Congratulations!
    You passed.
    You are awesome!
    You passed.
    Perfect!
    "Yes"
    */



    /*
    THE WHILE LOOP
    Loops: A loop repeatedly executed a set of statements until a particular condition is satisfied.

    A while loop statement repeatedly executes a target statement as long as given condition remains true.
    Syntax:
    while(condition){
        statements(s);
    }
    The loop iterates while the condition is true.

    At the point when the condition becomes false, program control is shifted to the line that immediately 
    follows the loop.

    The loop's body is the block of statements within curly braces.

    The example below declares a variable equal to 1 (num = 1).
    The while loop checks the condition (num<6), and executes the statements in its body, which increment the value
    of num by one each time the loop runs.
    
    After the 5th iteration, num becomes 6, and the condition is evaluated to false, and the loop stops running.

    The increment value can be changed.
    If changed, the number of times the loop is running will change, as well.
    
    Without a statement that eventually evaluates the loop condition to false, the loop will continue indefinitely.

    Using Increment or Decrement: the increment or decrement orperators can be used to change values in the loop.
    num++ is equivalent to num = num + 1

    A loop can be used to obtain multiple inputs from the user.

    We can modity our code to calculate the sum of the numbers the user has entered.
    The code below will add the number entered by the user to the total variable with each loop iteration.
    Once the loop stops executing, the value of total is printed.
    The value is the sum of all the numbers the user entered.
    The total variable has the initial value 0.
    */

    cout << "12. The While Loop" << endl;

    num = 1;
    while(num < 6) {
        cout << "Number: " << num << endl;
        num++;
    }
    /*
    Outputs
    Number: 1
    Number: 2
    Number: 3
    Number: 4
    Number: 5
    */
    num = 1;
    while (num < 6) {
        cout << "Number: " << num << endl;
        num = num + 3;
    }
    /*
    Outputs
    Number: 1
    Number: 4
    */
    num = 1;
    int number;
    while (num <= 5){
        //cin >> number;
        num++;
    }
    // When uncommented, this code will asks for user input 5 times, and each time saves the input
    // in the number variable.
    num = 1;
    number;
    int total = 0;
    while (num <= 5) {
        //cin >> number;
        total += number;
        num++;
    }
    // cout << total << endl;
    // If the above statement is uncommented, it Outputs the total sum of the numbers entered.

    cout << endl << endl;
    /*
    Output:
    Number: 1
    Number: 2
    Number: 3
    Number: 4
    Number: 5
    Number: 1
    Number: 4
    */



    /*
    THE FOR LOOP
    A for loop is a repetition control structure that allows us to efficiently write a loop that executes a 
    specific number of times.
    Syntax:
    for (init; condition; increment) {
        statement(s);
    }

    The init step is executed first, and does not repeat.
    The condition is evaluated, and the body of the loop is executed if the condition is true.
    In the next step, the increment statement updates the loop control variable.
    Then, the loop's body repeats itself, only stopping when the condition becomes false.

    The init and increment statements may be left out, if not needed, but remember that the
    semicolons are mandatory.

    In the init step, we declared a variable a and set it to equal 0.
    a < 10, is the condition.
    After each iteration, the a++ increment statement is executed.
    
    When a increments to 10, the condition evaluates to false, and the loop stops.

    It's possible to change the increment statement.
    We can also use the decrement in the statement.
    */
    cout << "13. The For Loop" << endl;

    for(int x = 1; x < 10; x++) {
        //some code
    }
    for(int a = 0; a < 10; a++) {
        cout << a << endl;
    }
    /*
    Outputs
    0
    1
    2
    3
    4
    5
    6
    7
    8
    9
    */
    for (int a = 0; a < 50; a+=10) {
        cout << a << endl;
    }
    /*
    Outputs
    0
    10
    20
    30
    40
    */
    for ( int a = 10; a >= 0; a -= 3){
        cout << a << endl;
    }
    /*
    Ouputs
    10
    7
    4
    1
    */

    cout << endl << endl;
    /*
    Output:
    0
    1
    2
    3
    4
    5
    6
    7
    8
    9
    0
    10
    20
    30
    40
    10
    7
    4
    1
    */




    /*
    THE DO...WHILE LOOP
    Unlike for and while loops, which test the loop condition at the top of the loop, the do...wihle loop
    checks its condition at the bottom of the loop.
    A do...while loop is similar to while loop.
    The one difference is that the do...while loop is guaranteed to execute at least one time.
    Syntax:
    do {
        statements(s)
    } while (condition);

    For example, we can take input from the user, then check it.
    If the input is wrong, we can take it again.

    Don't forget the semicolon after the while statement.

    while vs. do...while loop: If the condition evaluated to false, the statements in the 
    do would still run once.

    The do...while loop executes the statements at least once, and then tests the condition.
    The while loop executes the statement after testing confition.

    As with other loops, if the condition in the loop never evaluates to false, the loop will run forever.

    Always test our loops, so we know that they operate in the manner we expect.
    */
    cout << "14. The do...while loop" << endl;

    a = 0;
    do {
        cout << a << endl;
        a++;
    } while (a < 5);
    /*
    Outputs
    0
    1
    2
    3
    4
    */
    a = 45;
    do {
        cout << a << endl;
        a++;
    } while(a < 5);
    // Outputs 42
    a = 42;
    // do {
    //     cout << a << endl;
    // } while (a>0);
    //If we uncomment the above three lines, the do..while loop will run forever.

    cout << endl << endl;
    /*
    Output:
    0
    1
    2
    3
    4
    42
    */



    /*
    THE SWITCH STATEMENT:
    Multiple Conditions: Sometimes there is a need to test a variable for equality against multiple values.
    That can be achieved using multiple if statements

    The switch statement is a more elegant solution to this scenario.

    The switch statement tests a variable against a list of values, which are called cases, 
    to determine whether it is equal to any of them.
    Syntax:
    switch(expression){
        case value1:
            statement(s);
            break;
        case value2:
            statement(s);
            break;
        ...
        case valueN:
            statement(s);
            break;
    }
    Switch evaluates the expression to determine whether it is equal to the value in the case statement.
    If a match is found, it executes the statements in that case.

    A switch can contain any number of case statements, which are followed by the value in question and a colon.

    Notice the keyword break; that follows each case.

    The default Case: In a switch statement, the optional default case can be used to perform a task when none
    of the cases is determined to be true.
    The default statement's code executes when none of the cases matches the switch expression.
    The default case must appear at the end of the switch.

    The break statement: The break statement's role is to terminate the switch statement.
    In instances in which the variable is equal to a case, the statements that come after the case continue
    to execute until they encounter a break statement.
    In other words, leaving out a break statement results in the execution of all of the statements
    in the following cases, even those that don't match the expression.

    As we can see, the program executed the matching case statement, printing "Adult" to the screen.
    With no specified break statements, the statements continued to run after the matching case.
    Thus, all the other case statement printed.
    This type of behavior is called fall-through.

    As the switch statement's final case, the default case requires no break statement.
    The break statement can also be used to break out of a loop.
    */
    cout << "15. The switch Statement" << endl;

    age = 42;
    if (age == 16) {
        cout << "Too young" << endl;
    }
    if (age == 42) {
        cout << "Adult" << endl;
    }
    if (age == 72) {
        cout << "Senior" << endl;
    }
    //Outputs Adult
    age = 42;
    switch (age) {
        case 16:
            cout << "Too young" << endl;
            break;
        case 42:
            cout << "Adult" << endl;
            break;
        case 70:
            cout << "Senior" << endl;
            break;
    }
    // The code above is equivalent to three if statements.
    age = 25;
    switch (age) {
        case 16:
            cout << "Too young" << endl;
            break;
        case 42:
            cout << "Adult" << endl;
            break;
        case 70:
            cout << "Senior" << endl;
            break;
        default:
            cout << "This is the default case" << endl;
    }
    //Outputs "This is the default case"
    age = 42;
    switch (age) {
        case 16:
            cout << "Too young" << endl;
        case 42:
            cout << "Adult" << endl;
        case 70:
            cout << "Senior" << endl;
        default:
            cout << "This is the default case" << endl;
    }
    /*
    Outputs
    Adult
    Senior
    This is the default case
    */

    cout << endl << endl;
    /*
    Output:
    Adult
    Adult
    This is the default case.
    Adult
    Senior
    This is the default case
    */


    /*
    LOGICAL OPERATORS
    Use logical operators to combine conditional statements and return true or false.
    Operator        Name of Operator        Form
    &&              AND Operator            y && y
    ||              OR Operator             x || y
    !               NOT Operator            !x

    The AND Operator works the following way
    Left Operand           Right Operand        Result
    false                   false               false
    false                   true                false
    true                    false               false
    true                    true                true
    In AND Operator, both operands must be true for the entire expression to be true.
    Within a single if statement, logical operators can be used to combine multiple conditions.
    The entire expression evaluates to true only if all of the conditions are true.

    The OR Operator: The OR (||) operator returns true if any one of its operands is true.
    Left Operand            Right Operand       Result
    false                   false               false
    false                   true                true
    true                    false               true
    true                    true                true
    We can combine any number of logical OR statements we want.
    In addition, multiple OR and AND statements may be chained together.

    The NOT Operator: 
    The logical NOT (!) Operator works with just a single operand, reversing its logical state.
    Thus, if a condition is true, the NOT operator makes it false, and vice versa.
    Right Operand           Result
    true                    false  
    false                   true
    We need to be very careful using this, since !false is true.
    */
    cout << "16. Logical Operators" << endl;
    
    age = 20;
    if (age > 16 && age < 60) {
        cout << "Accepted!" << endl;
    }
    // Outputs "Accepted!"
    // In the above example, the logical AND operator was used to combine both expressions.
    // The expression in the if statement evaluates to true only if both expressions are true.
    age = 20;
    int grade = 80;
    if (age > 16 && age < 60 && grade > 50) {
        cout << "Accepted!" << endl;
    }
    // Outputs Accepted!
    age = 16;
    int score = 90;
    if (age > 20 || score > 50) {
        cout << "Accepted!" << endl; 
    }
    // Outputs Accepted!
    age = 10;
    if (!(age > 16)) {
        cout << "Your age is less than 16" << endl;
    }
    // Output Your age is less than 16

    cout << endl << endl;
    /*
    Output:
    Accepted!
    Accepted!
    Accepted!
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