#ifndef BINREADER_H
#define BINREADER_H
#include <string>
#include <sstream>
#include <fstream>

class BinReader {
private:
    std::ifstream infile;
public:
    BinReader();

    void open(std::string filePath);

    float* next(unsigned int count, unsigned int &number_of_points);

    void close();
};

#endif // BINREADER_H
