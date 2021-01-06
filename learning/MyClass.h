/*
The header file (.h) holds the function declarations (prototypes) and variable declarations.
It currently includes a template for our new MyClass class, with one default constructor.
*/

#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
    public:
        MyClass();
        MyClass(int a, int b);
        ~MyClass();
        void myPrint();
        void myPrint() const;
    protected:
    private:
        int regVar;
        int constVar;
    
    friend void someFunc(MyClass &obj);
    // Friend function
    // Note that when passing an object to the function, we need to pass it by reference, using the & operator.
};

void someFunc(MyClass &obj){
    obj.regVar = 42;
    obj.constVar = 100;
    cout << obj.regVar << " " << obj.constVar << endl;
}
// Some function changes the private members of the object and print its value.
// To make its members accessible, the class has to declare the function a friend in its definition.
// We cannot make a function a friend to a class without the class giving away its friendship to that function.

#endif // MYCLASS_H

// The implementation of the class and its methods go into the source file (.cpp).
// Currently it includes just an empty constructor.

