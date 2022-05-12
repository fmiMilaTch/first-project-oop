#include "book.h"

bool Book::onlyNumbers(const char* text){//da otdelia v otdelna f-ia
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
void Book::setFileName(const char* newText, char* textData, unsigned& textDataLenght){
    if(newText!=nullptr){
        unsigned newTextLen=strlen(newText);
        textData=new char[newTextLen+1];
        strcpy(textData,newText);
        textDataLenght=newTextLen;
        return;
    }
    else {
        textData=new char[8];//da napravia constanta=8;
        return setText("Unknown.txt",textData,newTextLenght);//malko zavisi ot povedeneieto na kompilatora za da prevurne unknown v const char...

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
void Book::changeText(const char* newText, char* textData, unsigned& textDataLenght){
    if((&newText)!=(&textData)){
        delete[] textData;
        setText(newText,textData,textDataLenght);
        return;
    }
    return;
}
void Book::changeFileName(const char* newFileName, char* textData, unsigned& textDataLenght){
    if((&newFileName)!=(&textData)){
        delete[] textData;
        setFileName(newFileName,textData,textDataLenght);
        return;
    }
    return;
}
void Book::changeISBN(const char* newISBN){
    if((&newISBN)!=(&ISBN)){
        delete[] ISBN;
        setISBN(newISBN);
    }
    return;
}
void Book::changeRating(const unsigned& newRating){//triabva li izobshto tazi funkcia:|
    setRating(newRating);
    return;
}

void Book::free(){
    delete author[];
    delete title[];
    delete fileName[];
    delete description[];
    delete ISBN[];
}

Book::Book(const char* newAuthor="Unknown", const char* newTitle="Unknown", const char* newFile="Unknown.txt", const char* newDesc="Unknown", const unsigned& newRating=0, const char* newISBN="0000000000000"){
    setText(newAuthor,author,authorLenght);
    setText(newTitle,title,titleLenght);
    setText(newFile,fileName,fileNameLenght);
    setText(newDesc,description,descLenght);
    setRating(newRating);
    setISBN(newISBN);
}
Book::Book(const Book& other){//principno ne triabva da moje da ima neviarna informacia, triabvat li proverkite..?//da, triabva da se zadeli pamet vse pak
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

const char* Book::getAuthor() const{
    return author;
}
const char* Book::getTitle() const{
    return title;
}
const char* Book::getDescription() const{
    return description;
}
const unsigned Book::getRating() const{
    return rating;
}
const char* Book::getISBN() const{
    return ISBN;
}
const char* Book::getFileName() const{
    return fileName;
}

Book::~Book(){
    free();
}

std::ostream& operator<<(std::ostream& outputStream, const Book&) const{//chetene
    outputStream<<Book.titleLenght<<" "<<(Book.title)*<<std::endl<<Book.authorLenght<<" "<<(Book.author)*<<std::endl<<Book.fileNameLenght<<" "<<(Book.fileName)*<<std::endl<<Book.rating<<std::endl<<(Book.ISBN)*<<std::endl<<Book.descLenght<<" "<<(Book.description)*<<std::endl;
    return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Book&){//vuvezgdane//e a sega de//losho mi stava ot tozi kod, moga li da go sukratia malko s niakoia obshta funcia@-@
    char spacing;
    unsigned dataSizes;
    char* textData;

    inputStream>>dataSizes>>spacing;//titlelengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//title
    Book.changeText(textData,Book.title,Book.titleLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//authorlengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//author
    Book.changeText(textData,Book.author,Book.authorLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//filenamelengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//filename
    Book.changeFileName(textData,Book.fileName,Book.fileNameLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//rating
    Book.changeRating(dataSizes);//zapis
    dataSizes=ISBN_LEN;//isbn lenght
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//isbn
    Book.changeISBN(textData);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//descr lenght
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//description
    Book.changeText(textData,Book.description,Book.descLenght);//zapis
    delete[] textData;//free

    return inputStream;
}
