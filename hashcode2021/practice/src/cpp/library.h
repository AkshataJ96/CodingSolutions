#ifndef LIBRARY_H
#define LIBRARY_H
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
        void getMetaData(long unsigned int& numBooks, long unsigned int& numLibraries, long unsigned int& numDays, list<Book>& books, list<Library>& libs);
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
        Book(long unsigned int id, long unsigned int score);
        ~Book();
        void getScore();
        void getID();
    
    private:
        long unsigned int id;
        long unsigned int score;

};

class Library {
    public:
        Library(long unsigned int id ,long unsigned int numBooks, unsigned int signUpTime, unsigned int numBooksPerDay);
        ~Library();
        void isSigned();
        void getBooks();
        void signUp();
        void getCurrentDaysBooks();
        vector<int> sortedBooks;
    
    private:
        long unsigned int id;
        long unsigned int numBooks;
        unsigned int signUpTime;
        unsigned int numBooksPerDay;

};

#endif // LIBRARY_H
