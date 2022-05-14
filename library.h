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
    unsigned findNewBookISBNPosition(const char*);
    /*
    unsigned findNewBookTitlePosition(const Book*);
    unsigned findNewBookAuthorPositon(const Book*);
    unsigned findNewBookRatingPosition(const Book*);
    */
    unsigned internalBinarySearchISBN(const char*, unsigned&, unsigned&, unsigned&);
    /*
    unsigned internalBinarySearchTitle(const Book*, unsigned&, unsigned&, unsigned&);
    unsigned internalBinarySearchAuthor(const Book*, unsigned&, unsigned&, unsigned&);
    unsigned internalBinarySearchRating(const Book*, unsigned&, unsigned&, unsigned&);
    */
    void swapDownByOneFromPosition(const unsigned&, Book**);//neka da e prosto sus swapove ot kraia do position
    void swapUpByOneFromPosition(const unsigned&, Book**);//same thing no ot position do bottom
    bool internalDoesISBNExist(const char*, unsigned&, unsigned&, unsigned&);
    bool doesISBNExist(const char*);
    bool isBookListFileUpdated=false;
    bool areBookListsSorted;
    void updateBookListFile();//da se paziat po isbn
    void free();
public:


    Library(const char* libraryFile, const unsigned& BooksNumber);
    Library();

    void logInAsAdmin(const char*);

    void addBook(const Book&);
    void addBook(Book&&);//kak shte ima niakakva random instancia??
    void addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);

    void removeBook(const char*);//po ISBN, da nqma dublirane
    void removeBookWithoutISBN(const char* title, const char* author);

    void sortedByTitleDescending() const;
    void sortedByAuthorDescending() const;
    void sortedByRaitingDescending() const;
    void sortedByTitleAscending() const;
    void sortedByAuthorAscending() const;
    void sortedByRaitingAscending() const;

    void searchAuthor(const char*) const;
    void searchTitle(const char*) const;
    void searchISBN(const char*) const;
    void searchDescription(const char*) const;//!!!//niama da mi stigne vremeto :(
    //void readBook(const char*) const;//da razdelia li na 3 otdelni?



    ~Library();
};
