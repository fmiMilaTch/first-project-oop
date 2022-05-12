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
    bool adminLogIn;

    void resizeBooks();
    void sortBooksByTitle();
    void sortBooksByISBN();
    void sortBooksByAuthor();
    void sortBooksByRating();
    unsigned findNewBookISBNPosition(const char*);
    void moveDownByOneFromPosition(const unsigned&);//neka da e prosto sus swapove ot kraia do position
    void moveUpByOneFromPosition(const unsigned&);//same thing no ot position do bottom
    bool doesISNBExist(const char*);
    bool isBoolListFileUpdated=false;
    void updateBookListFile();//da se paziat po isbn
    bool doesTextMatch(const char*, const char*) const;// po dobre da e friend//triabva li mi nakraia?, abstrakcia e ig, no triabva da napravia oshte 2 takiva togava, koeto si e prosto strcmp:/
    void free();
public:


    Library(const char* libraryFile, const unsigned& BooksNumber);
    Library();

    void inputAdminPassword(const char*);

    void addBook(const Book&);
    void addBook(Book&&);//kak shte ima niakakva random instancia??
    void addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);

    void removeBook(const char*);//po ISBN, da nqma dublirane

    void sortByTitle() const;
    void sortByAuthor() const;
    void sortByRaiting() const;

    void searchAuthor(const char*) const;
    void searchTitle(const char*) const;
    void searchISBN(const char*) const;
    void searchDescription(const char*) const;//!!!
    void readBook(const char*) const;//da razdelia li na 3 otdelni?



    ~Library();
};
