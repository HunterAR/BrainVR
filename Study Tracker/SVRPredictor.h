#ifndef SVR_PREDICTOR_H
#define SVR_PREDICTOR_H
#include "MachineLearning.h"
#include "RegressionPredictor.h"
#pragma once

using namespace MachineLearning;

namespace MachineLearningPrediction{
    class SVRPredictor : public RegressionPredictor{
    public:
        SVRPredictor();
        ~SVRPredictor();
        double getPercentageDifference(sample_type data);
    protected:
        double generatePredictionAugmented(sample_type data);
        double generatePredictionNonAugmented(sample_type data);
    };
}

#endif
