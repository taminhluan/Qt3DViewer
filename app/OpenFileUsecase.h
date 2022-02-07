#ifndef OPENFILEUSECASE_H
#define OPENFILEUSECASE_H
#include <string>
#include <fstream>
class OpenFileUsecase {
private:
    std::string sample_file_path;
    std::ofstream of_sampleData;

    float bb_min_x = 0;
    float bb_min_y = 0;
    float bb_min_z = 0;

    float bb_max_x = 0;
    float bb_max_y = 0;
    float bb_max_z = 0;
public:
    OpenFileUsecase();

    void run(std::string filepath,
             bool should_calculate_bounding_box,
             bool should_write_sample_data,
             bool should_visualize_sample_data,
             bool should_make_LOD,
             bool should_visualize_LOD);
    void write_point_to_sample_data(float x, float y, float z);

};

#endif // OPENFILEUSECASE_H
