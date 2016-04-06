#ifndef KRR_PREDICTOR_H
#define KRR_PREDICTOR_H
#include "MachineLearning.h"
#include "RegressionPredictor.h"
#pragma once

using namespace MachineLearning;

namespace MachineLearningPrediction{
    class KRRPredictor : public RegressionPredictor{
    public:
        KRRPredictor();
        ~KRRPredictor();
        double getPercentageDifference(sample_type data);
    protected:
        double generatePredictionAugmented(sample_type data);
        double generatePredictionNonAugmented(sample_type data);
    };
}

#endif
