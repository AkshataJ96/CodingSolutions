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

void InputReader::getMetaData(long unsigned int& numBooks, long unsigned int& numLibraries, long unsigned int& numDays) {
    //  add a filepath assert here
    ifstream metaFile;
    metaFile.open(filepath);
    string metadata;

    // vector<string> data; 
    // size_t opsize = split(metadata, data, ' ');
    // std::cout << "First line of file is  " << opsize << endl;
    // assert(opsize==3);
    metaFile >> metadata;
    numBooks = std::stoul(metadata);
    metaFile >> metadata;
    numLibraries = std::stoul(metadata);
    metaFile >> metadata;
    numDays = std::stoul(metadata);
    metaFile.close();

} 