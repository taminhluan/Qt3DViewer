#include "3d/io/BinReader.h"
#include <iostream>
#include <QDebug>

BinReader::BinReader() {

}


void BinReader::open(std::string filePath)
{
    this->infile.open(filePath, std::ios::binary);
    { // test
//        float f1 = 1.23;
//        double d1 = 2.34;
//        this->infile.read((char*)&f1, sizeof(float));
//        this->infile.read( (char*)&d1, sizeof(double) );

//        qDebug() << f1;
//        qDebug() << d1;
    }
}

float *BinReader::next(unsigned int count, unsigned int &number_of_points)
{
    float *result;
    number_of_points = 0;
    result = new float[3 * count];
    for (int i = 0; i < 3 * count; i++)
    {
        if (! this->infile.eof()) {
            this->infile.read((char *) &result[i], sizeof(float));
            number_of_points ++;
        } else {
            break;
        }
    }
    return result;
}

void BinReader::close()
{

}
