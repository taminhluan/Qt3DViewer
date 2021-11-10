#ifndef BINWRITER_H
#define BINWRITER_H
#include <string>

class BinWriter {
public:
    BinWriter();

    void open(std::string path);

    void write(float* data, unsigned int count);

    void close();
};

#endif // BINWRITER_H
