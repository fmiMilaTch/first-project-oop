#include "book.h"
class Library{
    Book** booksByTitle;//da se polzwa kato glavnia shablon za prenaregdane na ostanalite spisuci
    Book** booksByISBN;
    Book** booksByAuthor;
    Book** booksByRating;
    unsigned numberOfBooks;
    unsigned capacity;
    char* bookListFile;

    bool adminLogIn;
public:
    void resizeBooks();
    void sortBooksByTitle();
    void sortBooksByISBN();
    void sortBooksByAuthor();
    void sortBooksByRating();
    void updateBookListFile(const char*);//da se paziat po isbn
    bool doesTextMatch(const char*) const;
    void free();

    Library(const char* libraryFile);
    Library();

    void inputAdminPassword(const char*);

    void addBook(const Book&);
    void addBook(Book&&);//kak shte ima niakakva random instancia??
    void addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);
    void addBook(char* &&newAuthor, char* &&newTitle, char* &&newFile, char* &&newDesc, unsigned&& newRating, char* &&newISBN);//hmmm...

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
