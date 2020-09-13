#include<iostream>

using namespace std;

class BankAccount{
        public:
            void sayHi(){
                cout << "Hi" << endl;
            }    
};

class MyClass {
        public:
            string name;
}; 

class MyClass2 {
    private:
        string name;
    public:
        MyClass2(string nm){
            setName(nm);
        }
        MyClass2();
        void setName(string x){
            name = x;
        }
        string getName(){
            return name;
        }
        // The getName() method returns the value of the privaet name attribute.
};

int main(){
    /*
    WHAT IS AN OBJECT?
    Object Oriented Programming is a programming style that is intended to make thinking about programming 
    closer to thinking about the real world.
    In programming, objects are independent units, and each has its own identity, just as objects in the real world do.
    An apple is an object, so is a mug. Each has its unique identity.
    It's possible to have two mugs that look identical, but they are still separate, unique objects.

    Object:
    An object might contain other objects buth they're still different objects.
    Objects alos have characteristics that are used to describe them.
    For example, a car can be red or blue, a mug can be full or empty, and so on.
    These characterestics are also called attributes.
    An attribute describes the current state of an object.
    Objects can have multiple atributes (the mug can be empty, red and large).
    An object's state is independent of its type; a cup might be full of water, another might be empty.

    In real world, each object behaves in its own way. The car moves, the phone rings, and so on.
    The same applies to objects - behavior is specific to the object's type.

    So, the following three dimensions describe any object in object oriented programming: identity, attributes, behavior.

    In programming, an ojbect is self-contained, with its own identity.
    It is separate from other objects.
    Each object has its own attributes, which describe its current state.
    Each exhibits its own behavior, which demonstrates what they can do.

    In computing, objects aren't always representative of physical items.
    For example, a programming ojbect can represent a date, a time, a bank account.
    A bank account is not tangible, we can't see it or touch it, but it's still a well-defined object - it has its own identity, 
    attributes, and behavior.
    */

    /*
    WHAT IS A CLASS?
    Objects are created using classes, which are actually the focal point of OOP.
    The class describes what the object will be, but is separate from the object itself.
    In other words, a class can be described as an object's blueprint, description, or definition.
    We can use the same class as a blueprint for creating multiple different objects.
    For e.g., in preparation to creating a new building, the architect creates a blueprint, 
    which is used as a basis for actually the building structure.
    That same blueprint can be used to create multiple buildings.

    Programming works the same fashion.
    We first define a class, which becomes the blueprint for creating objects.

    Each class has a name, and describes attributes and behavior.

    In programming, the term type is used to refer to a class name: We're creating an object of 
    a particular type.
    
    Attributes are also referred to as properties or data.

    Methods:
    Method is another term for a class's behavior.
    A method is basically a function that belongs to a class.
    Methods are similar to funtions - they are blocks are code that are called, and they can 
    also perform actions and return values.

    For e.g.
    If we are creating a banking program, we can give our class the following characteristics.
    name: BankAccount
    attributes: accoutNumber, balance, dataOpened
    behavior: open(), close(), deposit()

    The class specifies that each object should have the defined attributes and behavior.
    However, it doesn't specify what the actual data is; it only provides a definition.

    Once we've written the class, we can move on to create objects that are based on that class.
    Each object is called an instance of a class.
    The process of creating objects is called instantiation.
    Each object has its own identity, data, and behavior.

    Declaring a Class.
    Begin our class definition with the keyword class.
    Follow the keyword with the class name and the class body, enclosed in a set of curly braces.
    Define all attributes and behavior (or members) in a body of the class, within curly braces.
    We can also define an access specifier for members of the class.
    A member that has been defined using the public keyword can be accessed from outside the class, as long
    as it's anywhere within the scope of the class object.

    We can also designate a class' members as private or protected.

    */
    cout << "31. Declaring a class" << endl;
    
    // The code above declares a class called BankAccount
    // Now, the next step is to instantiate an object of our BankAccount class, in the same way
    // we define variables of a type the difference being that our obeject's type will be BankAccount.
    BankAccount test;
    test.sayHi();
    // Out object named test has all the members of the class defined.
    // Notice the dot separator (.) that is used to access and call the method of the object.
    // We must declare a class before using it, as we do with functions.
    
    cout << endl << endl;
    /*
    Output:
    Hi
    */


    /*
    ABSTRACTION:
    Data abstraction is the concept of providing only essential information to the outside world.
    It's a process of representing essential features without including implementation details.

    A good real-world example is a book: When we hear a term book, we don't know the exact 
    specifics, i.e. the page count, the color, the size, but we understand the idea of a book - 
    the abastraction of the book.

    The concept of abstraction is that we focus on essentials qualities, rather than the specific 
    characteristics of one particular example.

    Abstraction means, that we can have an idea or a concept that is completely separate from any specific instance.
    It is one of the fundamental building blocks of object oriented programming.

    For e.g., when we use cout, we're actually using cout object of the class ostream.
    This stream data to result in standard output.

    Abstraction allows us to write a single bank account class, and then create different objects based on the class, for individual
    bank accounts, rather than creating a separate class for each bank account.

    Abstraction acts as a foundation for the other object orientation fundamentals, such as inheritance and polymorphism.
    */
    cout << "32. Abstraction" << endl;

    cout << endl << endl;

    /*
    ENCAPSULATION:
    Part of the meaning of the word encapsulation is the idea of "surrounding" an entity, not just to keep what's inside together
    but also to protect it.
    In obejct orientation, encapsulation means more than simply combining attributes and behavior
    together within a class; it also means restricting access to the inner workings of that class.
    The key principle here is that an object only reveals what the other application components require to 
    effectively run the application.
    All else are kept out of view.
    This is called data hiding.

    For e.g., if we take our BankAccount class, we do not want some other part of our program to reach in and change the balance
    of any object, without going through the deposit() and withdraw() behaviors.

    We should hide that attribute, control access to it, so it is accessible only by the object itself.

    This way, the balance cannot be directly changed from the outside of the object and is accessible only using its methods.

    This is also known as "black boxing", which refers to closing the inner working zones of the object, except of the pieces
    that we want to make public.

    This allows us to change attributes and implementations of methods without aletring the overall program.
    For e.g. we can come back later and change the data dype of the balance attribute.

    In summary, the benefits of encapsulation are:
        - Control the way data is accessed or modified.
        - Code is more flexible and easy to change with new requirements.
        - Change one part of code without affecting other part of the code.
    
    Access Specifiers:
    Access Specifiers are used to set access levels to particular members of the class.
    The three levels of access specifiers are public, protected and private.

    A public member is accessible from outside the class, and anywhere within the scope of the class object.

    Access modifiers only need to be declared once; multiple members can follow a single access modifier.
    Notice the colon(:) that follows public keyword.

    Private:
    A private member cannot be accessed, or even viewed, from outside the class; it can be accessed only
    from within the class.
    A public member function may be used to access the private members.

    We need encapsulation to hide the name attribute from the outside code.
    Then we provided access to it using public methods.
    Our class data can be read and modified only through those methods.

    This allows for changes to the implementation of the methods and attributes, without affecting 
    the outside code.
    */
    cout << "33. Encapsulation and Access Specifiers" << endl;

    MyClass myObj;
    myObj.name = "Prashik";
    cout << myObj.name << endl;
    // The name attribute is public; it can be accessed and modified from the outside the code.
    MyClass2 myObj2;
    myObj2.setName("Prashik");
    // In MyClass2, the name attribute is private and not accessible from the outside.
    // The public setName() method is used to set the name attribute.
    // If no access specifier is defined, all members of a class are set to private by default.
    // We can add another public method in order to get the value of the attribute.

    cout << endl << endl;
    /*
    Output:
    Prashik
    */



    /*
    CONSTRUCTORS:
    Class constructors are special member functions of a class.
    They are executed whenever new objects are created within that class.
    The constructor's name is identical to that of the class.
    It has no return type, not even void.

    Upon the creation of an object of type MyClass2, the constructor is automatically called.

    Constructors can be very useful for setting initial values for certain member variables.
    A default constructor has no parameters.
    However, when needed, parameters can be added to a constructor.
    This makes it possible to assign an initial value to an object when it's created.

    We defined a constructor, that takes one parameter and assigns it to the name attribute
    using the setName() method.

    When creating an object, we now need to pass the constructor's parameter.
    */
    cout << "34. Constructor" << endl;

    MyClass2 ob1("Prashik");
    MyClass2 ob2("Raut");
    // We have defined two objects, and used contructor to pass the initial value for the
    // name attribute for each object.
    // It's possible to have multiple constructors that take different numbers of parameters.
    cout << ob1.getName() << endl;
    cout << ob2.getName() << endl;

    cout << endl << endl;
    /*
    Prashik
    Raut
    */

    return 0;
}