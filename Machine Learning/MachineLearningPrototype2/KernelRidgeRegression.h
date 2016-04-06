/*KernelRidgeRegression.h*/
#ifndef KERNEL_RIDGE_REGRESSION_H
#define KERNEL_RIDGE_REGRESSION_H
#include "RegressionTrainer.h"
#pragma once

namespace MachineLearningLibrary{
	class KernelRidgeRegression : public RegressionTrainer {
	private:
		// Here we declare an instance of the krr_trainer object.  This is the
		// object that we will later use to do the training.
		dlib::krr_trainer<kernel_type> trainer;

		void setGamma();
	public:
		KernelRidgeRegression(char* file_path);
		~KernelRidgeRegression();
		int trainAugmentedModel();
		int trainNonAugmentedModel();
		double generatePredictionAugmented(sample_type data);
		double generatePredictionNonAugmented(sample_type data);
		void leaveOneOutValidation(bool aug);
	};
}


#endif