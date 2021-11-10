#ifndef LASREADER_H
#define LASREADER_H
#include <string>
class LasReader {
public:
    LasReader();

    void open(std::string filePath);

    float* next(unsigned int count);

    void close();
};

#endif // LASREADER_H
