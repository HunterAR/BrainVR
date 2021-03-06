/*SupportVectorRegression.h*/
#ifndef SUPPORT_VECTOR_REGRESSION_H
#define SUPPORT_VECTOR_REGRESSION_H

#include "RegressionTrainer.h"
#pragma once

namespace MachineLearningLibrary{
	class SupportVectorRegression : public RegressionTrainer {
	private:
		// Here we declare an instance of the krr_trainer object.  This is the
		// object that we will later use to do the training.
		dlib::svr_trainer<kernel_type> trainer;

		void setTrainingParameters();
	public:
		SupportVectorRegression(char* file_path);
		~SupportVectorRegression();
		/**
		Generates a new decision function for data points where augmented reality
		tools were used. Saves decision function to a .dat file for later
		use.
		@param none
		@return 0 for successful completion, -1 otherwise
		*/
		int trainAugmentedModel();
		int trainNonAugmentedModel();
		double generatePredictionAugmented(sample_type data);
		double generatePredictionNonAugmented(sample_type data);
		void leaveOneOutValidation(bool aug);
	};
}


#endif