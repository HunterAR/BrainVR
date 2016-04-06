#ifndef SVR_PREDICTOR_H
#define SVR_PREDICTOR_H
#include "RegressionPredictor.h"
#pragma once

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

using namespace MachineLearning;

namespace MachineLearningPrediction{
	public class SVRPredictor : public RegressionPredictor{
	public:
		DLL_EXPORT SVRPredictor();
		DLL_EXPORT ~SVRPredictor();
		double DLL_EXPORT generatePredictionAugmented(sample_type data);
		double DLL_EXPORT generatePredictionNonAugmented(sample_type data);
	};
}

#endif