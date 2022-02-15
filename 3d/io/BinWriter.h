#ifndef BINWRITER_H
#define BINWRITER_H
#include <string>
#include <sstream>
#include <fstream>

class BinWriter {
private:
    std::ofstream outputFile;

public:
    BinWriter();

    void open(std::string path);

    void write(float* data, unsigned int count);

    void close();
};

#endif // BINWRITER_H
