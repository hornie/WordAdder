// WordAdder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "WordAdder.h"
#include <filesystem>
#include <fstream>
#include <vector>

std::vector<std::string> firstFile();
std::vector<std::string> secondFile();
std::string addFileContents(std::vector<std::string> contentsFF, std::vector<std::string> contentsFS);
int main()
{
    addFileContents(firstFile(), secondFile());
}

std::fstream& GotoLine(std::fstream& file, unsigned int num) {
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

std::vector<std::string> firstFile() {

    std::string userSetFirstFile;
    std::ifstream openFirstFile;

    std::cout << "Please input first file path: ";
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
    std::vector<std::string> contentsFF;
    for (std::string line; std::getline(usrData, line); /**/)
        contentsFF.push_back(line);

    for (std::vector<std::string>::const_iterator c = contentsFF.begin(); c != contentsFF.end(); ++c)
        std::cout << *c << ' ';
    std::cout << "\n";
    openFirstFile.close();
    return contentsFF;
    }

}

std::vector<std::string> secondFile() {

    std::string userSetSecondFile;
    std::ifstream openSecondFile;

    std::cout << "Please input second file path: ";
    std::cin >> userSetSecondFile;

    openSecondFile.open(userSetSecondFile.c_str());

    openSecondFile.unsetf(std::ios_base::skipws);

    unsigned line_count = std::count(
        std::istream_iterator<char>(openSecondFile),
        std::istream_iterator<char>(),
        '\n');

    std::fstream usrData(userSetSecondFile);
    for (int i = 1; i < line_count; i++) {
        GotoLine(usrData, i);
        std::vector<std::string> contentsFS;
        for (std::string line; std::getline(usrData, line);)
            contentsFS.push_back(line);

        for (std::vector<std::string>::const_iterator c = contentsFS.begin(); c != contentsFS.end(); ++c)
            std::cout << *c << ' ';
        std::cout << "\n";
        openSecondFile.close();
        return contentsFS;
    }
    
}

std::string addFileContents(std::vector<std::string> contentsFF, std::vector<std::string> contentsFS) {
    std::cout << "\n" << "Combined output" << "\n";
    for (int a = 1; a < contentsFF.size(); a++) {
        for (int i = 1; i < contentsFS.size(); i++) {
            std::string combined = contentsFF[a] + contentsFS[i] + " ";
            std::cout << combined;
        }
    }
    return NULL;
}