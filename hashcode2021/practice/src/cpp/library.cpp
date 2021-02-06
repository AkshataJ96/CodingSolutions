#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <list>

#include "library.h"

using namespace std;
static size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs.size();
}

InputReader::InputReader(string inp_path){
    filepath = inp_path;
}
  
InputReader::~InputReader() {
    // Empty
}

void InputReader::getMetaData(long unsigned int& numBooks, long unsigned int& numLibraries, long unsigned int& numDays, list<Book>& books, list<Library>& libs) {
    //  add a filepath assert here
    ifstream metaFile;
    metaFile.open(filepath);
    string metadata;

    string line;
    std::getline(metaFile, line);
    vector<string> data; 
    size_t opsize = split(line, data, ' ');
    std::cout << "First line of file is  " << opsize << endl;
    assert(opsize==3);
    numBooks = std::stoul(data[0]);
    numLibraries = std::stoul(data[1]);
    numDays = std::stoul(data[2]);

    std::getline(metaFile, line);
    vector<string> booksScore; 
    opsize = split(line, booksScore, ' ');
    std::cout << "Book line of file is  " << opsize << endl;
    assert(opsize==numBooks);

    for (int i = 0 ; i < booksScore.size(); i++) {
        Book book(i,std::stoul(booksScore[i]));
        cout << "Book id " << i << " Book score is " << booksScore[i] << endl;
        books.push_back(book);
    }

    vector<string> library; 
    vector<string> libraryBooks; 
    for (int i = 0; i < numLibraries; i++) {
        library.clear();
        libraryBooks.clear();
        std::getline(metaFile, line);
        opsize = split(line, library, ' ');
        Library lib(i, std::stoul(library[0]), std::stoul(library[1]), std::stoul(library[2]));
        cout << "library are  : " << i << library[0] << library[1] << library[2] << endl;

        std::getline(metaFile, line);
        opsize = split(line, libraryBooks, ' ');
        for (int j = 0; j < libraryBooks.size(); ++j) {
            lib.sortedBooks.push_back(std::stoul(libraryBooks[i]));
        }
        cout << "Library " << i << " Book ids are " << line << endl;
        libs.push_back(lib);
    }

    metaFile.close();

} 

Book::Book(long unsigned int id, long unsigned int score) {
    this->id = id;
    this->score = score;
}

Book::~Book() {
    // Empty
}

Library::Library(long unsigned int id ,long unsigned int numBooks, unsigned int signUpTime, unsigned int numBooksPerDay) {
    this->id = id;
    this->numBooks = numBooks;
    this->signUpTime - signUpTime;
    this->numBooksPerDay = numBooksPerDay;
}

Library::~Library() {
    // Empty
}