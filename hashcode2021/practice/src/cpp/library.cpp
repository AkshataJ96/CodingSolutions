#include <iostream>
#include <vector>

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
        std::vector<unsigned int> totalBooks;

};
