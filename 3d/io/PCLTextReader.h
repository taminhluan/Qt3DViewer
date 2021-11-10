#ifndef PCLTEXTREADER_H
#define PCLTEXTREADER_H

#include <string>
#include <sstream>
#include <fstream>

class PCLTextReader {
private:
    std::ifstream infile;
public:
    PCLTextReader();

    void open(std::string filePath);

    float* next(unsigned int count);

    void close();
};

#endif // PCLTEXTREADER_H
