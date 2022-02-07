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

    float* next(unsigned int buck_size, unsigned int &number_of_points);

    void close();
};

#endif // PCLTEXTREADER_H
