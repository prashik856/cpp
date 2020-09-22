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
};

#endif // MYCLASS_H

// The implementation of the class and its methods go into the source file (.cpp).
// Currently it includes just an empty constructor.

