#include "library.cpp"
#include <string>
#include <list>

using namespace std;

int main() {
	string input_path = "/mnt/d/code/hashcode/CodingSolutions/hashcode2021/practice/sampleInput/a_example.txt";

	long unsigned int numBooks, numLibraries, numDays;

	InputReader inputReader(input_path);
	inputReader.getMetaData(numBooks, numLibraries, numDays);
    std::cout << "Details received are " <<numBooks << numLibraries << numDays << endl;

	// list<Library> libraries = inputReader.getLibraries();

	// list<Book> books = inputReader.getBooks();

    for (int i = 0; i < numDays; ++i) {
        //
    }
    return 0;
}