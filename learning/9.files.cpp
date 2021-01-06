#include<iostream>
#include<fstream>

using namespace std;

int main(){
    /*
       FILES:
       Working with files:
       Another useful C++ feature is the ability to read and write to files.
       That required the standard C++ library called fstream.
       Three new data types are defined in fstream.
       ofstream: Output file stream that creates and writes information to files.
       ifstream: Input file stream that reads information from files.
       fstream: General file stream, with both ofstream and ifstram capabilities that allows it
       to create, read and write information to files.

       To perform file processing in C++, header files <iostream> and <fstream> must be included
       in the C++ source file.

       These classes are derived directly or indirectly from the classes istream and ostream.
       We have already used objects whose types were these classes: cin is an object of class istream
       and cout is an object of class ostream.

       Opening a file:
       A file must be opened before we can read from it or write to it.
       Either the ofstream or fstream object may be used to open a file for writing.

       Closing a file:
       When we've finished working with a file, close it using the member function close().

       We can also provide the path to our file using ofstream object constructor, instead
       of calling the open function.

       Under certain circumstances, such as when we don't have file permissions, open function can fail
       The is_open() member function checks whether the file is open and ready to be accessed.

       File opening Modes:
       An optional second parameter of the open function defines the mode in which the
       file is opened.
       This list shows the supported modes.

       Mode Parameter               Meaning
       ios::app                     append to the end of the file
       ios::ate                     go to the end of the file on opening
       ios::binary                  file open in binary mode
       ios::in                      open file for reading only
       ios::out                     open file for writing only
       ios::trunc                   delete the contents of the file if it exists

       All these flags can be combined using the bitwise operator Or (|).


       Reading from a File:
       We can read information from a file using an ifstream or fstream object.

    */
    cout << "50. Files" << endl;

    ofstream myFile;
    myFile.open("test.txt");
    myFile << "Some text. \n";
    // The above code creates an ofstream object called myFile and uses the open() function
    // to open the "test.txt" file on the file system.
    // As we can see, the same stream output operator is used to write into the file.
    // If the specified file does not exist, the open function will create it automatically.
    myFile.close();
    // Running the code will cause a "test.txt" file to be created in the directory of our project
    // with "Some text!" written in it.
    // We also have the option of specifying a path for our file in the open function, since it
    // can be in a location other than that of our project.

    ofstream file("test2.txt");
    if(file.is_open()){
        file << "This is awesome" << endl;
    }
    else{
        cout << "Something went wrong" << endl;
    }
    file.close();
    // As with the open function, we can provide a full path to our file located in
    // a different directory.
    // The is_open() member function checks wheter the file is open and ready to be accessed.

    // For example, to open a file in wirte mode and truncate it, in case if it already exists, use the follwong syntax.
    ofstream outfile;
    outfile.open("file.dat", ios::out | ios::trunc);

    string line;
    ifstream readfile("test3.txt");
    while(getline(readfile, line)){
        cout << line << endl;
    }
    readfile.close();
    // The getline function reads characters from an input stream and places them into a string.
    // The example above reads a text file and prints the contents to the screen.
    // Out while loop uses the getline function to read the file line by line.

    cout << endl << endl;

    return 0;
}