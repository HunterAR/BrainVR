#ifndef REGRESSION_PREDICTOR_H
#define REGRESSION_PREDICTOR_H
#include "MachineLearning.h"
#pragma once

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

using namespace MachineLearning;

namespace MachineLearningPrediction{
	public class RegressionPredictor{
	public:
		DLL_EXPORT RegressionPredictor();
		virtual DLL_EXPORT ~RegressionPredictor();
		virtual double DLL_EXPORT generatePredictionAugmented(sample_type data) = 0;
		virtual double DLL_EXPORT generatePredictionNonAugmented(sample_type data) = 0;
	};
}

#endif