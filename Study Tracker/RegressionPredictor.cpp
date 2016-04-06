#include "RegressionPredictor.h"

namespace MachineLearningPrediction{
    RegressionPredictor::RegressionPredictor(){

    }

    RegressionPredictor::~RegressionPredictor(){

    }

    void RegressionPredictor::setDataFolder(char* folder){
        data_folder = folder;
    }

    char* RegressionPredictor::setFullFilePath(std::string file_name){
        char *tmp = new char[file_name.size() + 1];
        tmp[file_name.size()] = 0;
        memcpy(tmp, file_name.c_str(), file_name.size());
        int new_size = strlen(tmp) + strlen(data_folder) + 2;
        char* full_file_path = (char*)malloc(new_size);
        char* file_sep = new char[2];
        file_sep[0] = '/';
        file_sep[1] = '\0';
        strcpy(full_file_path, data_folder);
        strcat(full_file_path, file_sep);
        strcat(full_file_path, tmp);
        return full_file_path;
    }
}
