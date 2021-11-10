#ifndef BINREADER_H
#define BINREADER_H
#include <string>

class BinReader {
public:
    BinReader();

    void open(std::string filePath);

    float* next(unsigned int count);

    void close();
};

#endif // BINREADER_H
