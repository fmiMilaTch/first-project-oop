#include "library.h"

void Library::sortBooksByISBN(){
    Book* biggestISBN=booksByISBN[i];
    Book* Swap;
    for(int i=0;i<numberOfBooks;i++){
        biggestISBN=booksByISBN[i];
        for(int k=i;k<numberOfBooks;k++){
            if(strcmp(biggestISBN.ISBN,booksByISBN[k].ISBN)<0){
                Swap=biggestISBN;
                biggestISBN=booksByISBN[k];
                booksByISBN[k]=Swap;
            }
            /*if((strcmp(biggestISBN.ISBN,booksByISBN[k].ISBN)==0)&&(strcmp(biggestISBN.title,booksByISBN[k].title)>0)){
               Swap=biggestISBN;
                biggestISBN=booksByISBN[k];
                booksByISBN[k]=Swap;
            }*///niama da poddurzham neizvestni isbn,pisna mi
        }
        booksByISBN[i]=biggestISBN;
    }
}
void Library::sortBooksByTitle(){
    Book* biggestTitle=booksByTitle[i];
    Book* Swap;
    for(int i=0;i<numberOfBooks;i++){
        biggestTitle=booksByTitle[i];
        for(int k=i;k<numberOfBooks;k++){
            if(strcmp(biggestTitle.title,booksByTitle[k].title)>0){
                Swap=biggestTitle;
                biggestTitle=booksByTitle[k];
                booksByTitle[k]=Swap;
            }

        }
        booksByTitle[i]=biggestTitle;
    }
}
void Library::sortBooksByAuthor(){
    Book* biggestAuthor=booksByAuthor[i];
    Book* Swap;
    for(int i=0;i<numberOfBooks;i++){
        biggestAuthor=booksByAuthor[i];
        for(int k=i;k<numberOfBooks;k++){
            if(strcmp(biggestAuthor.author,booksByAuthor[k].author)>0){
                Swap=biggestAuthor;
                biggestAuthor=booksByAuthor[k];
                booksByAuthor[k]=Swap;
            }
        }
        booksByAuthor[i]=biggestAuthor;
    }
}
void Library::sortBooksByRating(){
    Book* biggestRating=booksByRating[i];
    Book* Swap;
    for(int i=0;i<numberOfBooks;i++){
        biggestRating=booksByRating[i];
        for(int k=i;k<numberOfBooks;k++){
            if(biggestRating.rating<booksByRating[k].rating){
                Swap=biggestRating;
                biggestRating=booksByRating[k];
                booksByRating[k]=Swap;
            }
        }
        booksByRating[i]=biggestRating;
    }
}
unsigned Library::findNewBookISBNPosition(const char* newBookISBN){
    if(strcmp(newBookISBN,booksByISBN[0].ISBN)>0){
        return 0;
    }
    if(strcmp(newBookISBN,booksByISBN[numberOfBooks-1])<)////
}
Library::Library(){
    numberOfBooks=0;
    capacity=50;//50 mogze pak da constanta?
    bookListFile=new char[strlen("defaultBookListFile.txt")+1];
    strcpy(bookListFile,"defaultBookListFile.txt");
    booksByTitle=new Book* [capacity];
    booksByISBN=new Book* [capacity];
    booksByAuthor=new Book* [capacity];
    booksByRating=new Book* [capacity];
}
Library::Library(const char* libraryFile, const unsigned& BooksNumber){
    std::ifstream inputStream(*(libraryFile));
    if(inputStream.is_open()){
        numberOfBooks=BooksNumber;
        capacity=((numberOfBooks>DEFAULT_CAPACITY)?((numberOfBooks/DEFAULT_CAPACITY+1)*DEFAULT_CAPACITY):DEFAULT_CAPACITY);
        booksByTitle=new Book* [capacity];
        booksByISBN=new Book* [capacity];
        booksByAuthor=new Book* [capacity];
        booksByRating=new Book* [capacity];
        for(int i=0;i<numberOfBooks;i++){
            booksByISBN[i]=new Book;
            inputStream>>*(booksByISBN[i]);
        }
        sortBooksByISBN();
        for(int i=0;i<numberOfBooks;i++){
            booksByTitle[i]=booksByISBN[i];
        }
        sortBooksByTitle();
        for(int i=0;i<numberOfBooks;i++){
            booksByAuthor[i]=booksByTitle[i];
            booksByRating[i]=booksByTitle[i];
        }
        sortBooksByAuthor();
        sortBooksByRating();
        bookListFile=new char[strlen(libraryFile)+1];
        strcpy(bookListFile,libraryFile);
    }
    else{
        numberOfBooks=0;
        capacity=DEFAULT_CAPACITY;
        bookListFile=new char[strlen("defaultBookListFile.txt")+1];
        strcpy(bookListFile,"defaultBookListFile.txt");
        booksByTitle=new Book* [capacity];
        booksByISBN=new Book* [capacity];
        booksByAuthor=new Book* [capacity];
        booksByRating=new Book* [capacity];
    }
}
void Library::addBook(const Book& other){
    if(numberOfBooks<capacity-1){
        booksByISBN[numberOfBooks]=new Book(other);
        if((strcmp(booksByISBN[numberOfBooks].ISBN,"0000000000000")!=0)&&(doesISNBExist(booksByISBN[numberOfBooks].ISBN))){
            Book* Swap=booksByISBN[numberOfBooks];
            unsigned position=findNewBookISBNPosition(booksByISBN[numberOfBooks].ISBN);
            moveDownByOneFromPosition(position);
            booksByISBN[position]=Swap;//dali da ne e prosto sus swap-ove do position
        }
    }
}
void Library::addBook(Book&&);//kak shte ima niakakva random instancia??
void Library::addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN);
