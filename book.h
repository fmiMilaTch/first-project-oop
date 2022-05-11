#include <iostream>
#include<cstring>
#include<fstream>
const unsigned ISBN_LEN=13;
const unsigned MIN_RATING=1;
const unsigned MAX_RATING=5;

class Library;
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
    void setFileName(const char*, char*, unsigned&);//pochti identichno na setText, mozge da napravia edna funkcia s default stoinost;;
    void setISBN(const char*);
    void setRating(const unsigned&);
    void changeText(const char*, char*, unsigned&);
    void changeFileName(const char*, char*, unsigned&);
    void changeISBN(const char*);
    void changeRating(const unsigned&);
    void free();

public:
    friend class Library;


    bool onlyNumbers(const char*) const;//uh toia const...i char*...// obikn funkcia
    //bool appropLenght(const char*)const;//dali da ne gi napravia friend?//a ne shto ne prosto strlen^^;
    //bool validFileName(const char*) const//triabva li mi takova neshto?


    const char* getAuthor() const;
    const char* getTitle() const;
    const char* getFileName() const;
    const char* getDescription() const;
    const unsigned getRating() const;
    const char* getISBN() const;

    Book(const char* newAuthor="Unknown", const char* newTitle="Unknown", const char* newFile="Unknown.txt", const char* newDesc="Unknown", const unsigned& newRating=0, const char* newISBN="0000000000000");
    Book(const Book& other);
    Book(Book&& other);

    friend std::ostream& operator<<(std::ostream&, const Book&) const;
    friend std::istream& operator>>(std::istream&, Book&);//sega stana slozgnichko...

    ~Book();
};
