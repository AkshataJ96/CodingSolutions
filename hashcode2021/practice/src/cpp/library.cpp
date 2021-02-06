#include <iostream>
#include <vector>

using namespace std;

class InputReader {
    public:
        InputReader(string inp_path);
        ~InputReader();
        void read();

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
        std::vector<Book> totalBooks;

};
