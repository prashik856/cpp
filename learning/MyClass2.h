/*
The header file (.h) holds the function declarations (prototypes) and variable declarations.
It currently includes a template for our new MyClass class, with one default constructor.
*/

#ifndef MYCLASS2_H
#define MYCLASS2_H

class MyClass2 {
    public:
        MyClass2();
        MyClass2(int a, int b);
        ~MyClass2();
        void myPrint();
        void myPrint() const;
    protected:
    private:
        int regVar;
        const int constVar;
};

#endif // MYCLASS2_H

// The implementation of the class and its methods go into the source file (.cpp).
// Currently it includes just an empty constructor.

