// WordAdder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "WordAdder.h"
#include <filesystem>
#include <fstream>

std::string firstFile();
std::string secondFile();
int main()
{
    firstFile();
}

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

std::string firstFile() {

    std::string userSetFirstFile;
    std::ifstream openFirstFile;

    std::cout << "Please input first file path:";
    std::cin >> userSetFirstFile;

    openFirstFile.open(userSetFirstFile.c_str());

    openFirstFile.unsetf(std::ios_base::skipws);
    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count(
        std::istream_iterator<char>(openFirstFile),
        std::istream_iterator<char>(),
        '\n');

    std::fstream usrData(userSetFirstFile);
    for (int i = 1; i < line_count; i++) {
    GotoLine(usrData, i);
    std::string usrFF;
    usrData >> usrFF;
    std::cout << usrFF << std::endl;
    }
    secondFile();
    openFirstFile.close();

    return 0;
}

std::string secondFile() {

    std::string userSetSecondFile;
    std::ifstream openSecondFile;

    std::cout << "Please input second file path:";
    std::cin >> userSetSecondFile;

    openSecondFile.open(userSetSecondFile.c_str());

    openSecondFile.unsetf(std::ios_base::skipws);
    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count(
        std::istream_iterator<char>(openSecondFile),
        std::istream_iterator<char>(),
        '\n');

    std::fstream usrData(userSetSecondFile);
    for (int i = 1; i < line_count; i++) {
        GotoLine(usrData, i);
        std::string usrFS;
        usrData >> usrFS;
        std::cout << usrFS << std::endl;
    }
    openSecondFile.close();

    return 0;

}
