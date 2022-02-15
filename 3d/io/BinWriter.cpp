#include "3d/io/BinWriter.h"
#include <QDebug>

BinWriter::BinWriter()
{

}

void BinWriter::open(std::string path)
{
    this->outputFile.open(path, std::ios::binary);
}

void BinWriter::write(float *data, unsigned int count)
{
    this->outputFile.write( (char*)data, count * 3 *  sizeof(float) );
    { // test
//        float f1 = 1.23;
//        double d1 = 2.34;
//        this->outputFile.write( (char*)&f1, sizeof(float) );
//        this->outputFile.write( (char*)&d1, sizeof(double) );
    }
}

void BinWriter::close()
{
    this->outputFile.close();
}
