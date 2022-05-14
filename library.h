#include "book.h"
const unsigned DEFAULT_CAPACITY=50;
class Library{
    Book** booksByTitle;//byisbn
    Book** booksByISBN;//da se polzwa kato glavnia shablon za prenaregdane na ostanalite spisuci
    Book** booksByAuthor;//bytitle
    Book** booksByRating;//bytitle
    unsigned numberOfBooks;
    unsigned capacity;
    char* bookListFile;

    char* adminPassword=new char[strlen("adminpassword23")+1];//izglezgdza mi tromavo :/
    strcpy(adminPassword,"adminpassword23");
    bool adminLogIn=false;

    void resizeBooks();
    void sortBooksByTitle();
    void sortBooksByISBN();
    void sortBooksByAuthor();
    void sortBooksByRating();
    void sortAnewBooks();
    unsigned findNewBookISBNPosition(const char*) const;
    unsigned internalBinarySearchISBN(const char*, unsigned&, unsigned&, unsigned&) const;
    void swapDownByOneFromPosition(const unsigned&, Book**);
    void swapUpByOneFromPosition(const unsigned&, Book**);
    int internalFindISBN(const char*, unsigned&, unsigned&, unsigned&) const;
    int findISBN(const char*) const;
    int internalFindTitle(const char*, unsigned&, unsigned&, unsigned&) const;
    int findTitle(const char*) const;
    int internalFindAuthor(const char*, unsigned&, unsigned&, unsigned&) const;
    int findAuthor(const char*) const;
    bool isBookListFileUpdated=false;
    bool areBookListsSorted;
    void updateBookListFile();//da se paziat po isbn
    void free();
public:


    Library(const char* libraryFile, const unsigned& BooksNumber);
    Library();

    void logInAsAdmin(const char*);

    void addBook(const Book&);
    void addBook(Book&&);
    void addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);

    void removeBook(const char*, bool&);

    void sortedByTitleDescending() const;
    void sortedByAuthorDescending() const;
    void sortedByRaitingDescending() const;
    void sortedByTitleAscending() const;
    void sortedByAuthorAscending() const;
    void sortedByRaitingAscending() const;

    void searchAuthor(const char*) const;
    void searchTitle(const char*) const;
    void searchISBN(const char*) const;

    ~Library();
};
