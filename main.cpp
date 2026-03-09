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
    int dueDate; // date
    bool isAvailable; // book's availability status

// creating the constructor - template for the book so we can have many different book objects
    public: // others can access this information
    Book(string t, string a, int i) { // placenames for the book values to be passed through
        title = t; // assigning values
        author = a;
        ISBN = i;
        isAvailable = true; // books are available by default unless this is changed by another user
    }

// getting the private info to be displayed
    string getTitle() { return title; } // gets the book title
    string getAuthor() { return author; } // gets the author
    int getISBN() { return ISBN; } // gets the ISBN
    bool getAvailability() { return isAvailable; } // gets the availability

// creating the displaying of the books
    void showBookInfo() { // method that display book information
        cout << "Book title: "<< title << " \n" // displays the title
        << "Book author: " << author << " \n" // displays the author
        << "ISBN: " << ISBN << " \n" // displays the ISBN
        << "Available?: " << isAvailable << " \n" // displays the availability (yes/no)
        << endl; // ends the display
    }

// methods

// borrowing books
    bool borrowBook() { // this method is a boolean because it can either succeed or fail
        if (isAvailable) {
            isAvailable = false; // availability turns to false because someone has borrowed the book
            return true; // means the borrowing succeeded
        } else {
            return false; // means the borrowing has not succeeded
        }
    }

// returning books
    bool returnBook() { // is going to look like the opposite of the borrow function
        if (!isAvailable) { // means if the book isn't available (borrowed)
            isAvailable = true; // availability is true because nobody is borrowing it anymore after the returning method
            return true; // means the returning has succeeded
        } else {
            return false; // means the returning has not succeeded
        }
    }

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
 private: // has private attributes
    int UserID; // user ID
    string name; // member's name

    vector<Book*> borrowedBooks; // a list of pointers to books the member has borrowed

// creating the constructor - template for the library member so we can have many different library members
    public: // others can access this information
    LibraryMember(int id, string n) {
        UserID = id;
        name = n;
}

// implementing the 5 book only policy
    bool canBorrow() { // boolean allows borrowing up to a certain number
        return borrowedBooks.size() < 5; // allows borrowing if a user has under 5 books, else doesn't allow more borrowing
    }

    void addBorrowedBook(Book* book) { // function that adds a borrowed book to the member's borrowedBooks list after they've borrowed a book; adds a pointer to that book into the borrowedBooks vector
        borrowedBooks.push_back(book); // adds that book to end of the vector list
    }

// borrowing books
    bool borrowBook(Book* book) { // allows the library member to access the borrowBook method in the Book class and borrow books

        if (!canBorrow()) { // if they don't pass the 5 book rule
            cout << "Unable to borrow more than 5 books at a time." << endl; // will show a message stating that the library member cannot borrow more than 5 books at a time
            return false; // if this is the case it won't run the borrowing
        }

        if (book->borrowBook()) { // asking the Book object to run its function, the -> is because the book object is a pointer
            addBorrowedBook(book); // adding the book to end of the member's list
            return true; // means it worked
        }

            return false;
    }

// returning books
    bool returnBook(Book* book) {

        if (book->returnBook()) { // getting the book to mark itself as returned, AKA available again
            for (int i = 0; i < borrowedBooks.size(); i++) { // looking through the library member's list of books
                if (borrowedBooks[i] == book) { // checking if the book in the list is the same as the current book being returned 
                    borrowedBooks.erase(borrowedBooks.begin() + i); // this will then remove it from the vector
                    break; // stop searching when we've found it
            }
        }

        return true; // means the return process has succeeded
    }

    return false; // means the return process has failed

};


// creating the librarian class
class Librarian {

};

// creating the administrator class
class Administrator {

};

// creating the library system class
class LibrarySystem {
// creating its attributes
    private: // can't be accessed by anyone else, prevents the system from breaking
        vector<Book*> books; // the library stores many books

    public: // can be accessed by other classes
        
        void addBook (Book* b) // adding the object for the Book - b - which the function receives, via a pointer
        {
            books.push_back(b); // adds a new book to the end of the vector list, AKA adds a new book to the library
        }

        void showAllBooks ()
        {
            for(int i = 0; i < books.size(); i++) // start at the first book then move one by one through them
            {
                books[i]->showBookInfo(); // asking the book at position i to show its information, so each book shows its information
            }
        }
};


int main() { // start of program

    return 0;

}
