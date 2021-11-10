#include "3d/io/PCLTextReader.h"
#include <iostream>

PCLTextReader::PCLTextReader()
{

}

void PCLTextReader::open(std::string filePath)
{
    this->infile.open(filePath);
}

float *PCLTextReader::next(unsigned int count)
{
    std::string line;

    float* vertices;

    bool no_data = true;
    for (int i = 0; i < count; i++) {
        if (std::getline(this->infile, line)) {
            if (no_data) {
                no_data = false;
                vertices = new float[3 * count];
            }

            std::istringstream iss(line);

            float x = 0.0f;
            float y = 0.0f;
            float z = 0.0f;

            iss >> x >> y >> z;

            *(vertices + (3 * i + 0)) = x;
            *(vertices + (3 * i + 1)) = y;
            *(vertices + (3 * i + 2)) = z;
        } else {
            break;
        }


    }
    if (no_data) {
        return nullptr;
    } else {
        return vertices;
    }
}

void PCLTextReader::close()
{
    this->infile.close();
}
