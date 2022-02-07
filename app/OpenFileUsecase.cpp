#include "app/OpenFileUsecase.h"

#include <3d/io/PCLTextReader.h>

#include <QDebug>
#include <limits>

OpenFileUsecase::OpenFileUsecase()
{

}

void OpenFileUsecase::write_point_to_sample_data(float x, float y, float z)
{
    if(! this->of_sampleData.is_open()) {
        this->of_sampleData.open("C:\\Users\\luantm\\Downloads\\sample.pts");
    }

    this->of_sampleData << x << " " << y << " " << z << "\n";
}

void OpenFileUsecase::run(std::string filepath, bool should_calculate_bounding_box, bool should_write_sample_data, bool should_visualize_sample_data, bool should_make_LOD, bool should_visualize_LOD)
{
    qDebug() << "OpenFileUsecase::run";

    float bb_min_x = std::numeric_limits<float>::max();
    float bb_min_y = std::numeric_limits<float>::max();
    float bb_min_z = std::numeric_limits<float>::max();
    float bb_max_x = std::numeric_limits<float>::min();
    float bb_max_y = std::numeric_limits<float>::min();
    float bb_max_z = std::numeric_limits<float>::min();

    PCLTextReader* textReader = new PCLTextReader();
    textReader->open(filepath);

    qDebug() << "Opened text file";

    int count = 0;
    while(true) {
        unsigned int buck_size = 1000;

        unsigned int return_number_of_points = 0;
        float* points = textReader->next(buck_size, return_number_of_points);

        if (return_number_of_points == 0) {
            break;
        }

        count += return_number_of_points;

        qDebug() << "Processed " << count << "points";

        for (int i = 0; i < return_number_of_points; i++) {
            float x = points[ i * 3 + 0];
            float y = points[ i * 3 + 1];
            float z = points[ i * 3 + 2];

            if (bb_min_x > x) { bb_min_x = x; }
            if (bb_min_y > y) { bb_min_y = y; }
            if (bb_min_z > z) { bb_min_z = z; }

            if (bb_max_x < x) { bb_max_x = x; }
            if (bb_max_y < y) { bb_max_y = y; }
            if (bb_max_z < z) { bb_max_z = z; }

            if (should_write_sample_data) {
                if (i%100 == 0) {
                    this->write_point_to_sample_data(x, y, z);
                }
            }
        }
    }

    if(! this->of_sampleData.is_open()) {
        this->of_sampleData.close();
    }

    qDebug() << "Wrote sample data: " << QString::fromStdString(this->sample_file_path);

    textReader->close();
}
