#include <iostream> // allows output and input
#include <vector> // for use of book vectors
#include <string> // for string attributes

using namespace std; // efficiency, removes typing in std:: each time

// creating the book class
class Book {
// creating its attributes
    private: // attributes are set to private, preventing users from randomly changing them
    string title; // book title attribute
    string author; // author attribute
    int ISBN; // ISBN attribute
    bool isAvailable; // book's availability status

// creating the constructor - template for the book
    public:
    Book(string t, string a, int i) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = true; // books are available by default unless this is changed by another user
    }

};

// creating the user class
class User {

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