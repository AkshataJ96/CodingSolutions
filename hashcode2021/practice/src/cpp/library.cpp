#include <iostream>
#include <cassert>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class Library;
class Book;

class InputReader {
    public:
        InputReader(string inp_path);
        ~InputReader();
        void getMetaData(long unsigned int& numBooks, long unsigned int& numLibraries, long unsigned int& numDays);
		list<Library> getLibraries();
		list<Book> getBooks();

    private:
        string filepath;

};

class OutputWriter {
    public:
        OutputWriter(string op_path);
        ~OutputWriter();
        void write();

    private:
        string filepath;

};

class Book {
    public:
        Book();
        ~Book();
        void getScore();
        void getID();
    
    private:
        long unsigned int id;
        long unsigned int score;

};

class Library {
    public:
        Library();
        ~Library();
        void isSigned();
        void getBooks();
        void signUp();
        void getCurrentDaysBooks();
    
    private:
        long unsigned int id;
        unsigned int signUpTime;
        unsigned int numBooksPerDay;
        list<Book> sortedBooks;

};

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

void InputReader::getMetaData(long unsigned int& numBooks, long unsigned int& numLibraries, long unsigned int& numDays) {
    //  add a filepath assert here
    ifstream metaFile;
    metaFile.open(filepath);
    string metadata;
    metaFile >> metadata;
    vector<string> data; 
    size_t opsize = split(metadata, data, ' ');
    assert(opsize==3);
    numBooks = std::stoul(data[0]);
    numLibraries = std::stoul(data[1]);
    numDays = std::stoul(data[2]);
    metaFile.close();

} 