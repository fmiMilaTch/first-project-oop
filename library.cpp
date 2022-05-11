#include "library.h"

Library::Library(){
    numberOfBooks=0;
    capacity=50;
    bookListFile=new char[strlen("defaultBookListFile.txt")+1];
    strcpy(bookListFile,"defaultBookListFile.txt");
    booksByTitle=new Book* [capacity];
    booksByISBN=new Book* [capacity];
    booksByAuthor=new Book* [capacity];
    booksByRating=new Book* [capacity];
}
Library::Library(const char* libraryFile, const unsigned& BooksNumber){

}
