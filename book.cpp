#include "book.h"
const unsigned DEFAULT_TEXT_LEN=8;
const unsigned DEFAULT_TEXTFILE_LEN=12;
bool Book::onlyNumbers(const char* text) const{//da otdelia v otdelna f-ia
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
        textData=new char[DEFAULT_TEXT_LEN];//da napravia constanta=8;
        return setText("Unknown",textData,textDataLenght);

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
        textData=new char[DEFAULT_TEXTFILE_LEN];//da napravia constanta=8;
        return setText("Unknown.txt",textData,textDataLenght);

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
    delete[] author;
    delete[] title;
    delete[] fileName;
    delete[] description;
    delete[] ISBN;
}

Book::Book(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN){
    setText(newAuthor,author,authorLenght);
    setText(newTitle,title,titleLenght);
    setFileName(newFile,fileName,fileNameLenght);
    setText(newDesc,description,descLenght);
    setRating(newRating);
    setISBN(newISBN);
}
Book::Book(const Book& other){//principno ne triabva da moje da ima neviarna informacia, triabvat li proverkite..?//da, triabva da se zadeli pamet vse pak
    setText(other.author,author,authorLenght);
    setText(other.title,title,titleLenght);
    setFileName(other.fileName,fileName,fileNameLenght);
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

std::ostream& operator<<(std::ostream& outputStream, const Book& object){//chetene
    outputStream<<object.titleLenght<<" "<<object.title<<std::endl<<object.authorLenght<<" "<<object.author<<std::endl<<object.fileNameLenght<<" "<<object.fileName<<std::endl<<object.rating<<std::endl<<object.ISBN<<std::endl<<object.descLenght<<" "<<object.description<<std::endl;
    return outputStream;
}

std::istream& operator>>(std::istream& inputStream, Book& object){//vuvezgdane//e a sega de//losho mi stava ot tozi kod, moga li da go sukratia malko s niakoia obshta funcia@-@
    char spacing;
    unsigned dataSizes;
    char* textData;

    inputStream>>dataSizes>>spacing;//titlelengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//title
    object.changeText(textData,object.title,object.titleLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//authorlengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//author
    object.changeText(textData,object.author,object.authorLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//filenamelengh
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//filename
    object.changeFileName(textData,object.fileName,object.fileNameLenght);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//rating
    object.changeRating(dataSizes);//zapis
    dataSizes=ISBN_LEN;//isbn lenght
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//isbn
    object.changeISBN(textData);//zapis
    delete[] textData;//free
    inputStream>>dataSizes>>spacing;//descr lenght
    textData=new char[dataSizes+1];
    inputStream>>textData>>spacing;//description
    object.changeText(textData,object.description,object.descLenght);//zapis
    delete[] textData;//free

    return inputStream;
}
