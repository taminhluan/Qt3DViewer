#include "3d/tool/Converter.h"
#include "3d/io/PCLTextReader.h"
#include "3d/io/BinWriter.h"


void Converter::convert(std::string inputPath, std::string outputPath) {
    { //test
        PCLTextReader *textReader;
        textReader = new PCLTextReader();
        textReader->open(inputPath);

        BinWriter *binWriter;
        binWriter = new BinWriter();
        binWriter->open(outputPath);
        while(true) {
            unsigned int buck_size = 1000;
            unsigned int return_number_of_points = 0;
            float* points = textReader->next(buck_size, return_number_of_points);

            if (points == nullptr) { break; }
            binWriter->write(points, return_number_of_points);

        }
    }
}
