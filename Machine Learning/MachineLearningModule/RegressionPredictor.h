#ifndef REGRESSION_PREDICTOR_H
#define REGRESSION_PREDICTOR_H
#pragma once

#define MACHINE_LEARNING_API __declspec(dllexport)

using namespace MachineLearning;

namespace MachineLearningPrediction{
	class MACHINE_LEARNING_API RegressionPredictor{
	public:
		RegressionPredictor();
		virtual ~RegressionPredictor();
		virtual double getPercentageDifference(sample_type data) = 0;
	protected:
		virtual double generatePredictionAugmented(sample_type data) = 0;
		virtual double generatePredictionNonAugmented(sample_type data) = 0;
	};
}

#endif