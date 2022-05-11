#include "book.h"

bool Book::onlyNumbers(const char* text){
    for(int i=0; i<ISBN_LEN; i++){
        if(!((text[i]>='0')&&(text[i]<='9'))){
            return false;
        }
    }
    return true;
}

void Book::setText(const char* newText, char* textData, unsigned& textDataLenght){
    if(newText!=nullptr){
        unsigned newTextLen=strlen(newText);
        textData=new char[newTextLen+1];
        strcpy(textData,newText);
        textDataLenght=newTextLen;
        return;
    }
    else {
        textData=new char[8];//da napravia constanta=8;
        return setText("Unknown",textData,newTextLenght);//malko zavisi ot povedeneieto na kompilatora za da prevurne unknown v const char...

    }
}
void Book::setRating(const unsigned& newRating){
    if((newRating<=MAX_RATING)&&(newRating>=MIN_RATING)){
        rating=newRating;
        return;
    }
    else{
        rating=0;
        return;
    }
}
void Book::setISBN(const char* newISBN){
    if((newISBN!=nullptr)&&(strlen(newISBN)==ISBN_LEN)&&(onlyNumbers(newISBN))){
        ISBN=new char[ISBN_LEN+1];
        strcpy(ISBN,newISBN);
        return;
    }
    else{
        return setISBN("0000000000000");

    }
}
void Book::free(){
    delete author[];
    delete title[];
    delete fileName[];
    delete description[];
    delete ISBN[];
}

Book::Book(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN){
    setText(newAuthor,author,authorLenght);
    setText(newTitle,title,titleLenght);
    setText(newFile,fileName,fileNameLenght);
    setText(newDesc,description,descLenght);
    setRating(newRating);
    setISBN(newISBN);
}
Book::Book(const Book& other){//principno ne triabva da moje da ima neviarna informacia, triabvat li proverkite..?
    setText(other.author,author,authorLenght);
    setText(other.title,title,titleLenght);
    setText(other.fileName,fileName,fileNameLenght);
    setText(other.description,description,descLenght);
    setRating(other.rating);
    setISBN(other.ISBN);
}
Book::Book(Book&& other){//presumcia, che ne triabvat proverki
    author=other.author;
    authorLenght=other.authorLenght;
    other.author=nullptr;
    title=other.title;
    titleLenght=other.titleLenght;
    other.title=nullptr;
    fileName=other.fileName;
    fileNameLenght=other.fileNameLenght;
    other.fileName=nullptr;
    description=other.description;
    descLenght=other.descLenght;
    other.description=nullptr;
    ISBN=other.ISBN;
    other.ISBN=nullptr;
    rating=other.rating;
}

const char* Book::getAuthor() const;
const char* Book::getTitle() const;
const char* Book::get() const;

Book::~Book(){
    free();
}
