#include<iostream>
using namespace std;

class Mother {
    public:
        Mother(){
            cout << "Mother Constructor" << endl;
        };
        ~Mother(){
            cout << "Mother Destructor" << endl;
        }
        void sayHi(){
            cout << "Hi" << endl;
        }
    
    private: 
        int var = 0;
    
    protected:
        int someVar;
};
// The Mother class has a public method called sayHi()
// someVar can be accessed by any class that is derived from the Mother Class.

// The syntax derives the Daughter class from the Mother class.
class Daughter : public Mother {
    public:
        Daughter() {
            cout << "Daughter Constructor" << endl;
        };
        ~Daughter(){
            cout << "Daughter Destructor" << endl;
        }
};
// The Base class is specified using a colon and an access specifier: public means, that all public
// members of the base class are public in the derived class.
// In other words, all public members of Mother class become public members of the Daughter class.
// As all public members of the Mohter class become public members for the Daughter class,
// we can create an object of type Daughter and call the sayHi() function of the Mother class
// for that object.


class Enemy{
    public:
        void setAttackPower(int a){
            attackPower = a;
        }
        virtual void attack(){
            cout << "Enemy!" << endl;
        }
        // A virtual function is a base class function that is declared using the keyword virtual
    protected:
        int attackPower;
};
// Enemy class has a public method called setAttackPower, which sets the protected attackPower member variable.


class Ninja: public Enemy{
    public:
        void attack(){
            cout << "Ninja - " << attackPower << endl;
        }
};

class Monster: public Enemy{
    public:
        void attack(){
            cout << "Monster - " << attackPower << endl;
        }
};
// Inididual attack() function of both Ninja and Monster differ.
// If we create our Ninja and Monster objects in main.


int main(){
    /*
    INHERITANCE:
    Inheritance is one of the most important concepts of object-oriented programming.
    Inheritance allows us to define a class based on another class.
    This facilitates greater ease in creating and maintaining an application.

    The class whose properties are inherited by another class is called the Base class.
    The class which inherits the properties is called the Derived class.
    For example, the Daughter class (derived) can be inherited from the Mother class (base).
    The derived class inherits all feature from the base class, and can have its own additional features.

    Base Class : base class features
    Derived Class: base class features + derived class features
    [Inherited from base class]

    The idea of inheritance implements the is a relationship.
    For example, mammal is an animal, dog is an mammal, hence dog is an animal as well.

    Let's create a Mother class and a Daughter class:

    A class can be derived from multiple classes by specifying the base classes in a comma-separated list.
    For example: class Daughter: public Mother, public Father.

    Access Specifiers:
    Up to this point, we have worked exclusively with public and private access specifiers.
    Public members may be accessed from anywhere outside of the class, while access to private 
    members is limited to their class and friend functions.

    As we have seen previously, it's a good practice to use public methods to access private class variables.

    Protected:
    There is one more access specifier: protected.
    A protected member variable or function is very similar to a private member, with on difference - 
    it can be accessed in the derived classes.

    Type of Inheritance:
    Access specifiers are also used to specify the type of inheritance.
    We used public to inherit the Daughter class.
    private and protected access specifiers can also be used here.

    Public Inheritance:
    public members of the base class become public members of the derived class and protected members of the base 
    class become protected members of the derived class.
    A base class's private members are never accessible directly from a derived class, but can be accessed through 
    calls to the public and protected members of the base class.

    Protected Inheritance:
    public and protected members othe base class become protected members of the derived class.

    Private Inheritance:
    public and protected members of the base class become private members of the derived class.

    Public Inheritance is the most commonly used inheritance type.
    If no access specifier is used when inheriting classes, the type becomes private by default.

    When inheriting classes, the base class's constructor and destructor are not inherited.
    However, they are being called when an object of the derived class is created or deleted.


    Summary:
    Constructors:
    The base class constructor is called first.

    Destructors:
    The derived class destructor is called first, and then the base class destructor gets called.

    This sequence makes it possible to specify initialization and de-initialization scenarios for
    our derived classes.
    */
    cout << "43. Inheritance" << endl;

    Daughter daughter;
    daughter.sayHi();
    // A derived class inherits all base class methods with the following exceptions.
    // Constructors, Destructors,
    // Overloaded operators
    // The friend functions
    Mother mother;
    // The object is created and then deleted when the program exits.
    Daughter daughter2;
    /*
    Output:
    Mother Constructor
    Daughter Constructor
    Daughter Destructor
    Mother Destructor
    */
    /*
    Note that the base class' constructor is called first, and the derived class' constructor
    is called next.
    When the object is destroyed, the derived class's destructor is called, and then the base class'
    destructor is called.
    
    The derived clas needs its base class in order to work - that is why the base class is set up first.
    */

    cout << endl << endl;
    /*
    Output:
    Mother Contructor
    Mother Destructor
    Mother Constructor
    Daughter Constructor
    Daughter Destructor
    Mother Destructor
    */

    /*
    POLYMORPHISM:
    The word polymorphism means "having many forms".
    Typically, polymorphism occurs when there is a hierarchy of classes and they are related
    by inheritance.

    C++ polymorphism means that a call to a member function will cause a different implementation to be
    executed depending on the type of the object that invokes the function.

    Simply, polymorphism means that a single function can have a number of different implementations.

    Polymorphism can be demonstrated more clearly using an example:
    Suppose we want to make a simple game, which in cludes all different enemies: monsters, ninjas, etc.
    All enemies have one function in common: an attack function.
    However, they each attack in a different way.
    In this situation, polymorphism allows for calling the same attack function on different objects, but resulting
    in different behaviors.

    Now, creating two different types of enemies, Ninjas and Monsters.
    Both of these new classes inherit from the Enemy class, so each has an attack power.
    At the same time, each has a specific attack function.
    */
    cout << "44. Polymorphism" << endl;

    Ninja ninja;
    Monster monster;
    // Ninja and monster inherit from Enemy, so all Ninja and Monster objects are Enemy objects.
    // Now this allows us to do this
    Enemy *e1 = &ninja;
    Enemy *e2 = &monster;
    // We have created two pointers of type Enermy.
    // pointing them to the Ninja and Monster objects.
    // Now, if we call the correspoinding functoins.
    e1->setAttackPower(20);
    e2->setAttackPower(80);
    ninja.attack();
    monster.attack();
    // We would have achieved the same result by calling the functions directly on the objects.
    // However, it's fater and more efficient to use pointers.
    // Also, the pointer demonstrates, that we can use the Enemy pointer without actually knowing that
    // it contains an object of the subclass.
    e1->attack();
    e2->attack();
    // We can use Enemy pointers to call attack() functions.
    // As the attack() function is declared virtual, it works like a template, telling that the
    // derived class might have an attack() function of its own

    cout << endl << endl;
    /*
    Output:
    Ninja - 20
    Monster - 80
    */


    /*
    VIRTUAL FUNCTIONS:
    In the previous example, we demonstrated the use of base class pointers to the derived classes.
    Now, we want every Enemy to have an attack() function.
    To be able to call the corresponding attack() function for each of the derived classes using Enemy pointers,
    we need to declare the base class function as virtual.
    Defining a virtual function in the base class, with a corresponding version in a derived class, allows
    polymorphism to use Enemy pointers to call the derived classes' functions.
    Every derived class will override the attack() function and have a separate implementation.
    
    Our game example serves to demonstrate the concept of polymorphism; we are using Enemy pointers to call the same
    attack() function, and generating different results.

    If a function in the base class is virtual, the functions implementation in the derived class is called
    according to the actual type of the object referred to, regardless of the declared type of the pointer.

    A class that declares or inherits a virtual function is called a polymorphic class.
    */
    cout << "45. Virtual Functions" << endl;


    cout << endl << endl;



    /*
    ABSTRACT CLASS:
    Virtual functions can also have their own implementation in the base class:

    Now, when we create an Enemy pointer, and call the attack() function, the compiler will
    call the function , which corresponds to the object's type, to which the pointer points.

    This is how polymorphism is generally used.
    We have different classes with a function of the same name, and even the same parameters, 
    but with different implementations.

    Pure Virtual Function:
    In some situations we'd ant to include a virtual function in a base class so that it may be 
    redefined in a derived class to suit the objects of that class, but that there is no meaningful
    definition we could give for the function in the base class.
    The virtual member functions without definition are known as pure virtual functions.
    They basically specify that the derived classes define that function on their own.

    The syntax is to replace their definition by =0
    class Enemy {
        public:
            virtual void attack() = 0
    }
    The =0 tells the compiler that the function has no body.

    A pure virtual function basically defines, that the derived classes will have that function defined
    on theri own.
    Every derived class inheriting from a class with a pure virtual function must override that function.
    If the pure virtual function is not overridden in the derived class, the code fails to compile and results in 
    an error when we try to instantiate an object of the derived class.

    A pure virtual function in the Enemy class must be overridden in its derived class.


    Abstract Class:
    We cannot create objects of the base class iwth a pure virtual function.
    Running the following code will run an error:
    Enemy e; //Error

    Thes classes are called abstract. 
    They are classes that can only be used as base classes, and thus are allowed to have pure virtual functions.

    We might think that an abstract base class is useless, but it isn't.
    It can be used to create pointers and take advantage of all it's polymorphic abilities.

    Ojbects of different but related types are referred to using a unique type of pointer (Enermy*), and the proper
    member function is called every time, just because they are virtual.
    */
    cout << "46.Abstract Class" << endl;

    Enemy enemy;
    Enemy *e3 = &enemy;
    e1 -> attack();
    e2 -> attack();
    e3 -> attack();

    cout << endl << endl;
    /*
    Outputs:
    Ninja - 20
    Monster - 80
    Enemy!
    */


    return 0;
}