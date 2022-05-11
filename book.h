#include <iostream>
#include<cstring>
#include<fstream>
const unsigned ISBN_LEN=13;
const unsigned MIN_RATING=1;
const unsigned MAX_RATING=5;
class Book{
    char* author;
    unsigned authorLenght;
    char* title;
    unsigned titleLenght;
    char* fileName;
    unsigned fileNameLenght;
    char* description;
    unsigned descLenght;
    unsigned rating;
    char* ISBN;

    void setText(const char*, char*, unsigned&);
    void setISBN(const char*);
    void setRating(const unsigned&);
    void free();

public:



    bool onlyNumbers(const char*) const;//uh toia const...i char*...
    //bool appropLenght(const char*)const;//dali da ne gi napravia friend?//a ne shto ne prosto strlen^^;
    //bool validFileName(const char*) const//triabva li mi takova neshto?


    const char* getAuthor() const;
    const char* getTitle() const;
    const char* getFileName() const;
    const char* getDescription() const;
    const unsigned getRating() const;
    const char* getISBN() const;

    Book(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);
    //does it need a move constructor??
    Book(char* &&newAuthor, char* &&newTitle, char* &&newFile, char* &&newDesc, unsigned&& newRating, char* &&newISBN);
    Book(const Book& other);
    Book(Book&& other);

    ~Book();
};
