#include <iostream> // allows output and input
#include <vector> // for use of book vectors
#include <string> // for string attributes

using namespace std; // efficiency, removes typing in std:: each time

// creating the book class
class Book {
// creating its attributes
    private: // attributes are set to private, preventing users from randomly changing them
    string title; // book title 
    string author; // author 
    int ISBN; // ISBN 
    bool isAvailable; // book's availability status

// creating the constructor - template for the book
    public: // others can access this information
    Book(string t, string a, int i) { // placenames for the book values to be passed through
        title = t; // assigning values
        author = a;
        ISBN = i;
        isAvailable = true; // books are available by default unless this is changed by another user
    }

// getting the private info to be displayed
    string getTitle() { return t; }


// creating the displaying of the books
    

// methods
// borrowing books

// returning books

};

// creating the user class
class User {
// creating its attributes
    protected: // attributes are set to protected, preventing users from outside the main superclass and subclasses from randomly changing them
    int UserID; // user ID
    string name; // user name
    string email; // user email
    string password; // user password

};

// creating the library member class
class LibraryMember {

};

// creating the librarian class
class Librarian {

};

// creating the administrator class
class Administrator {

};

// creating the library system class
class LibrarySystem {

};


int main() { // start of program

    return 0;

}