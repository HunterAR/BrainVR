#ifndef KRR_PREDICTOR_H
#define KRR_PREDICTOR_H
#include "RegressionPredictor.h"
#pragma once

#ifdef MACHINE_LEARNING_EXPORT
#define MACHINE_LEARNING_API __declspec(dllexport)
#endif

using namespace MachineLearning;

namespace MachineLearningPrediction{
	class MACHINE_LEARNING_API KRRPredictor : public RegressionPredictor{
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