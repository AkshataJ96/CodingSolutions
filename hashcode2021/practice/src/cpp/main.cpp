#include "library.cpp"
#include <string>
#include <list>

int main() {
	string input_path = "";

	long unsigned int numBooks, numLibraries, numDays;

	InputReader inputReader(input_path);
	inputReader.getMetaData(numBooks, numLibraries, numDays);

	list<Library> libraries = inputReader.getLibraries();

	list<Book> books = inputReader.getBooks();

	std::cout << "Hello World";
    return 0;
}