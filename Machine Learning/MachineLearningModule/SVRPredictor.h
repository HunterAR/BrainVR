#ifndef SVR_PREDICTOR_H
#define SVR_PREDICTOR_H
#include "RegressionPredictor.h"
#pragma once

#define MACHINE_LEARNING_API __declspec(dllexport)

using namespace MachineLearning;

namespace MachineLearningPrediction{
	class MACHINE_LEARNING_API SVRPredictor : public RegressionPredictor{
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