#ifndef REGRESSION_PREDICTOR_H
#define REGRESSION_PREDICTOR_H
#include "MachineLearning.h"
#pragma once

using namespace MachineLearning;

namespace MachineLearningPrediction{
    class RegressionPredictor{
    public:
        RegressionPredictor();
        virtual ~RegressionPredictor();
        virtual double getPercentageDifference(sample_type data) = 0;
        void setDataFolder(char* folder);
        char* setFullFilePath(std::string file_path);
    protected:
        virtual double generatePredictionAugmented(sample_type data) = 0;
        virtual double generatePredictionNonAugmented(sample_type data) = 0;
        char* data_folder;
    };
}

#endif
