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
void Library::sortAnewBooks(){
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
}
int Library::internalFindISBN(const char* newISBN, unsigned& left, unsigned& right, unsigned& mid)const{
    if(strcmp(newISBN,booksByISBN[mid].ISBN)==0){
        return mid;
    }
    if(left==right){
        return -1;
    }
    if(strcmp(newISBN,booksByISBN[mid].ISBN)>0){
        return internalFindISBN(newISBN,left,mid-1,(left+mid-1)/2);
    }
    if(strcmp(newISBN,booksByISBN[mid].ISBN)<0){
        return internalFindISBN(newISBN,mid+1,right,(right+mid+1)/2);
    }

}
int Library::findISBN(const char* newISBN)const{
    if(strcmp(booksByISBN[0].ISBN,newISBN)==0){
        return 0;
    }
    if(strcmp(booksByISBN[0].ISBN,newISBN)<0){
        return -1;
    }
    if(strcmp(booksByISBN[numberOfBooks-1].ISBN,newISBN)==0){
        return numberOfBooks-1;
    }
    if(strcmp(booksByISBN[numberOfBooks-1].ISBN,newISBN)>0){
        return -1;
    }
    unsigned left=0;
    unsigned right=numberOfBooks-1;
    unsigned mid=(left+right)/2;
    return internalDoesISBNExist(newISBN,left,right,mid);
}
int Library::internalFindTitle(const char* searchedTitle, unsigned& left, unsigned& right, unsigned& mid) const{
    if(strcmp(searchedTitle,booksByTitle[mid].title)==0){
        unsigned i=mid+1;
        while(strcmp(searchedTitle,booksByTitle[i].title)==0){
            i++;
        }
        return i-1;
    }
    if(left==right){
        return -1;
    }
    if(strcmp(searchedTitle,booksByTitle[mid].title)<0){
        return internalFindTitle(searchedTitle,left,mid-1,(left+mid-1)/2);
    }
    if(strcmp(searchedTitle,booksByTitle[mid].title)>0){
        return internalFindTitle(searchedTitle,mid+1,right,(right+mid+1)/2);
    }
}
int Library::findTitle(const char* searchedTitle) const{
    if(strcmp(booksByTitle[0].title,searchedTitle)==0){
        return 0;
    }
    if(strcmp(booksByTitle[0].title,searchedTitle)>0){
        return -1;
    }
    if(strcmp(booksByTitle[numberOfBooks-1].title,searchedTitle)==0){
        return numberOfBooks-1;
    }
    if(strcmp(booksByTitle[numberOfBooks-1].title,searchedTitle)<0){
        return -1;
    }
    unsigned left=0;
    unsigned right=numberOfBooks-1;
    unsigned mid=(left+right)/2;
    return internalFindTitle(searchedTitle,left,right,mid);
}
int Library::internalFindAuthor(const char* searchedAuthor, unsigned& left, unsigned& right, unsigned& mid)const{
    if(strcmp(searchedAuthor,booksByAuthor[mid].author)==0){
        unsigned i=mid+1;
        while(strcmp(searchedAuthor,booksByAuthor[i].author)==0){
            i++;
        }
        return i-1;
    }
    if(left==right){
        return -1;
    }
    if(strcmp(searchedAuthor,booksByAuthor[mid].author)<0){
        return internalFindAuthor(searchedAuthor,left,mid-1,(left+mid-1)/2);
    }
    if(strcmp(searchedAuthor,booksByAuthor[mid].author)>0){
        return internalFindAuthor(searchedAuthor,mid+1,right,(right+mid+1)/2);
    }
}
int Library::findAuthor(const char* searchedAuthor) const{
    if(strcmp(booksByAuthor[0].author,searchedAuthor)==0){
        return 0;
    }
    if(strcmp(booksByAuthor[0].author,searchedAuthor)>0){
        return -1;
    }
    if(strcmp(booksByAuthor[numberOfBooks-1].author,searchedAuthor)==0){
        return numberOfBooks-1;
    }
    if(strcmp(booksByAuthor[numberOfBooks-1].author,searchedAuthor)<0){
        return -1;
    }
    unsigned left=0;
    unsigned right=numberOfBooks-1;
    unsigned mid=(left+right)/2;
    return internalFindAuthor(searchedAuthor,left,right,mid);
}
unsigned Library::internalBinarySearchISBN(const char* newBookISBN, unsigned& left, unsigned& right, unsigned& mid) const{
    if(strcmp(newBookISBN,booksByISBN[mid].ISBN)>0){
        if(strcmp(newBookISBN,booksByISBN[mid-1].ISBN)<0){
           return mid;
        }
        if(strcmp(newBookISBN,booksByISBN[mid-1].ISBN)>0){
            return internalBinarySearchISBN(newBookISBN,left,mid-1,(left+mid)/2);
        }
    }
    if(strcmp(newBookISBN,booksByISBN[mid].ISBN)<0){
        if(strcmp(newBookISBN,booksByISBN[mid+1].ISBN)>0){
            return mid+1;
        }
        if(strcmp(newBookISBN,booksByISBN[mid+1].ISBN)<0){
            return internalBinarySearchISBN(newBookISBN,mid+1,right,(mid+1+right)/2);
        }
    }
}

void Library::swapUpByOneFromPosition(const unsigned& position, Book** booksList){
    Book* Swap;
    for(int i=numberOfBooks-1;i>position;i--){
        Swap=bookList[i];
        bookList[i]=bookList[i-1];
        bookList[i-1]=Swap;
    }
}
void Library::swapDownByOneFromPosition(const unsigned& position, Book** booksList){
    Book* Swap;
    for(int i=position;i>numberOfBooks-1;i++){
        Swap=bookList[i];
        bookList[i]=bookList[i+1];
        bookList[i+1]=Swap;
    }
}
unsigned Library::findNewBookISBNPosition(const char* newBookISBN) const{
    if(strcmp(newBookISBN,booksByISBN[0].ISBN)>0){
        return 0;
    }
    if(strcmp(newBookISBN,booksByISBN[numberOfBooks-1].ISBN)<=0){
        return numberOfBooks;
    }
    unsigned left=0;
    unsigned right=numberOfBooks-1;
    unsigned mid=(left+right+1)/2;
    return internalBinarySearchISBN(newBookISBN,left,right,mid);
}

void Library::resizeBooks(){
    unsigned newCapacity=capacity*2;
    Book** newBooksByISBN, newBooksByTitle, newBooksByAuthor, newBooksByRating;
    newBooksByISBN=new Book* [newCapacity];
    newBooksByTitle=new Book* [newCapacity];
    newBooksByAuthor=new Book* [newCapacity];
    newBooksByRating=new Book* [newCapacity];
    for(unsigned i=0; i<numberOfBooks; i++){
        newBooksByISBN[i]=booksByISBN[i];
        newBooksByTitle[i]=booksByTitle[i];
        newBooksByAuthor[i]=booksByAuthor[i];
        newBooksByRating[i]=booksByRating[i];
    }
    delete[] booksByISBN;
    delete[] booksByTitle;
    delete[] booksByAuthor;
    delete[] booksByRating;
    booksByISBN=newBooksByISBN;
    booksByTitle=newBooksByTitle;
    booksByAuthor=newBooksByAuthor;
    booksByRating=newBooksByRating;
    capacity=newCapacity;
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
    areBookListsSorted=false;
}
Library::Library(const char* libraryFile, const unsigned& BooksNumber){
    std::ifstream inputStream(libraryFile);
    if(inputStream.is_open()){
        numberOfBooks=BooksNumber;
        capacity=((numberOfBooks>DEFAULT_CAPACITY)?((numberOfBooks/DEFAULT_CAPACITY+1)*DEFAULT_CAPACITY):DEFAULT_CAPACITY);///moge tova pak da go pogledna da sym sigurna
        booksByTitle=new Book* [capacity];
        booksByISBN=new Book* [capacity];
        booksByAuthor=new Book* [capacity];
        booksByRating=new Book* [capacity];
        for(int i=0;i<numberOfBooks;i++){
            booksByISBN[i]=new Book;
            inputStream>>*(booksByISBN[i]);
        }
        inputStream.close();
        sortBooksByISBN();
        sortAnewBooks();
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
void Library::logInAsAdmin(const char* password){
    if(strcmp(password,adminPassword)==0){
        std::cout<<"Admin log-in successful!"<<std::endl;
        adminLogIn=true;
        return;
    }
    std::cout<<"Password incorrect."<<std::endl;
}
void Library::sortedByTitleDescending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=0; i<numberOfBooks; i++){
        std::cout<<booksByTitle[i].title<<",  "<<booksByTitle[i].author<<",  "<<booksByTitle[i].ISBN<<std::endl;
    }
}
void Library::sortedByAuthorDescending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=0; i<numberOfBooks; i++){
        std::cout<<booksByAuthor[i].title<<",  "<<booksByAuthor[i].author<<",  "<<booksByAuthor[i].ISBN<<std::endl;
    }
}
void Library::sortedByRaitingDescending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=0; i<numberOfBooks; i++){
        std::cout<<booksByRating[i].title<<",  "<<booksByRating[i].author<<",  "<<booksByRating[i].ISBN<<std::endl;
    }
}
void Library::sortedByTitleAscending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=numberOfBooks-1; i>=0; i--){
        std::cout<<booksByTitle[i].title<<",  "<<booksByTitle[i].author<<",  "<<booksByTitle[i].ISBN<<std::endl;
    }
}
void Library::sortedByAuthorAscending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=numberOfBooks-1; i>=0; i--){
        std::cout<<booksByAuthor[i].title<<",  "<<booksByAuthor[i].author<<",  "<<booksByAuthor[i].ISBN<<std::endl;
    }
}

void Library::sortedByRaitingAscending() const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    for(unsigned i=numberOfBooks-1; i>=0; i--){
        std::cout<<booksByRating[i].title<<",  "<<booksByRating[i].author<<",  "<<booksByRating[i].ISBN<<std::endl;
    }
}
void Library::searchTitle(const char* searchedTitle) const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    int position=findTitle(searchedTitle);
    if(position==(-1)){
        std::cout<<"No matching results found."<<std::endl;
        return;
    }
    while((position<numberOfBooks)&&(strcmp(booksByTitle[position].title,searchedTitle)==0)){
        std::cout<<booksByTitle[position].title<<",  "<<booksByTitle[position].author<<", "<<booksByTitle[position].ISBN<<std::endl;
        position++;
    }
    return;
}
void Library::searchAuthor(const char* searchedAuthor) const{
    if(!areBookListsSorted){
        sortAnewBooks();
    }
    int position=findAuthor(searchedAuthor);
    if(position==(-1)){
        std::cout<<"No matching results found."<<std::endl;
        return;
    }
    while((position<numberOfBooks)&&(strcmp(booksByAuthor[position].author,searchedAuthor)==0)){
        std::cout<<booksByAuthor[position].title<<",  "<<booksByAuthor[position].author<<", "<<booksByAuthor[position].ISBN<<std::endl;
        position++;
    }
    return;
}
void Library::searchISBN(const char* searchedISBN) const{
    int position=findISBN(searchedISBN);
    if(position==(-1)){
        std::cout<<"Book does not exist in the Library."<<std::endl;
        return;
    }
    std::cout<<booksByISBN[position].title<<",  "<<booksByISBN[position].author<<",  "<<booksByISBN[position].ISBN<<std::endl;
    return;
}
void Library::addBook(const Book& other){///edin if i ako e purva kniga v masiva, togawa prosto se dobavia
    if(adminLogIn){

        if(strcmp(other.ISBN,"0000000000000")==0){
            std::cout<<"This book has no ISBN. Some operations may not work properly, including its removal from the Library."<<std::endl;
        }
        if((numberOfBooks==0){
            numberOfBooks++;
            booksByRating[0]=booksByAuthor[0]=booksByTitle[0]=booksByISBN[0]=new Book(other);
            isBookListFileUpdated=false;
            areBookListsSorted=true;
            return;
        }
        if(numberOfBooks==capacity-1){
            resizeBooks();
        }
        if(numberOfBooks<capacity-1){
            if((strcmp(other.ISBN,"0000000000000")==0)||(findISBN(other.ISBN)==(-1))){
                booksByISBN[numberOfBooks]=new Book(other);
                unsigned ISBNPosition=findNewBookISBNPosition(booksByISBN[numberOfBooks].ISBN);
                numberOfBooks++;
                swapUpByOneFromPosition(ISBNPosition,booksByISBN);
                isBookListFileUpdated=false;
                areBookListsSorted=false;
                return;
            }
            else{
                std::cout<<"This book already exists in the Library."<<std::endl;
                return;
            }
        }

    }
    else{
        std::cout<<"Admin-only operation! Please first log-in as admin to do this operation!"<<std::endl;
        return;
    }
}
void Library::addBook(Book&& other){
    if(adminLogIn){

        if(strcmp(other.ISBN,"0000000000000")==0){
            std::cout<<"This book has no ISBN. Some operations may not work properly, including its removal from the Library."<<std::endl;
        }
        if((numberOfBooks==0){
            numberOfBooks++;
            booksByRating[0]=booksByAuthor[0]=booksByTitle[0]=booksByISBN[0]=new Book(other);
            isBookListFileUpdated=false;
            areBookListsSorted=true;
            return;
        }
        if(numberOfBooks==capacity-1){
            resizeBooks();
        }
        if(numberOfBooks<capacity-1){
            if((strcmp(other.ISBN,"0000000000000")==0)||(findISBN(other.ISBN)==(-1))){
                booksByISBN[numberOfBooks]=new Book(other);
                unsigned ISBNPosition=findNewBookISBNPosition(booksByISBN[numberOfBooks].ISBN);
                numberOfBooks++;
                swapUpByOneFromPosition(ISBNPosition,booksByISBN);
                isBookListFileUpdated=false;
                areBookListsSorted=false;
                return;
            }
            else{
                std::cout<<"This book already exists in the Library."<<std::endl;
                return;
            }
        }

    }
    else{
        std::cout<<"Admin-only operation! Please first log-in as admin to do this operation!"<<std::endl;
        return;
    }
}
void Library::addBook(const char* newAuthor, const char* newTitle, const char* newFile, const char* newDesc, const unsigned& newRating, const char* newISBN){
    if(adminLogIn){

        if(strcmp(newISBN,"0000000000000")==0){
            std::cout<<"This book has no ISBN. Some operations may not work properly, including its removal from the Library."<<std::endl;
        }
        if((numberOfBooks==0){
            numberOfBooks++;
            booksByRating[0]=booksByAuthor[0]=booksByTitle[0]=booksByISBN[0]=new Book(newAuthor,newTitle,newFile,newDesc,newRating,newISBN);
            isBookListFileUpdated=false;
            areBookListsSorted=true;
            return;
        }
        if(numberOfBooks==capacity-1){
            resizeBooks();
        }
        if(numberOfBooks<capacity-1){
            if((strcmp(newISBN,"0000000000000")==0)||((findISBN(newISBN))==(-1))){
                booksByISBN[numberOfBooks]=new Book(newAuthor,newTitle,newFile,newDesc,newRating,newISBN);
                unsigned ISBNPosition=findNewBookISBNPosition(booksByISBN[numberOfBooks].ISBN);
                numberOfBooks++;
                swapUpByOneFromPosition(ISBNPosition,booksByISBN);
                isBookListFileUpdated=false;
                areBookListsSorted=false;
                return;
            }
            else{
                std::cout<<"This book already exists in the Library."<<std::endl;
                return;
            }
        }

    }
    else{
        std::cout<<"Admin-only operation! Please first log-in as admin to do this operation!"<<std::endl;
        return;
    }
}
void Library::removeBook(const char* ISBNtoDelete, bool deleteBookFileContents){
    if(adminLogIn){
        int position=findISBN(ISBNtoDelete);
        if(position==(-1)){
            std::cout<<"This book is not in the Library."<<std::endl;
            return;
        }
        if(deleteBookFileContents){
            std::ofstream fileToDelete(booksByISBN[position].fileName,std::ios::trunk);
            if(!fileToDelete.is_open()){
                std::cout<<"File could not be opened."<<std::endl;
            }
            fileToDelete.close();

        }
        swapDownByOneFromPosition(position,booksByISBN);
        delete[] booksByISBN[numberOfBooks-1];
        numberOfBooks--;
        areBookListsSorted=false;
        std::cout<<"Book has been deleted from the library!"<<std::endl;
        return;
    }
    std::cout<<"Admin-only operation! Please first log-in as admin to do this operation!"<<std::endl;
    return;
}
void Library::free(){
    for(unsigned i=0;i<numberOfBooks;i++){
        delete booksByISBN[i];
    }
    delete[] booksByISBN;
    delete[] booksByTitle;
    delete[] booksByAuthor;
    delete[] booksByRating;
    delete[] bookListFile;
    delete[] adminPassword;
}
Library::~Library(){
    free();
}
