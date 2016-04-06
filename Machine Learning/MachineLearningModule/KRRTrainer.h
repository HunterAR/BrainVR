/*KRRTrainer.h*/
#ifndef KERNEL_RIDGE_REGRESSION_H
#define KERNEL_RIDGE_REGRESSION_H
#include "RegressionTrainer.h"
#pragma once

#define MACHINE_LEARNING_API __declspec(dllexport)

namespace MachineLearningTraining{
	class MACHINE_LEARNING_API KRRTrainer : public RegressionTrainer {
	private:
		// Here we declare an instance of the krr_trainer object.  This is the
		// object that we will later use to do the training.
		dlib::krr_trainer<kernel_type> trainer;

		void setGamma();
	public:
		KRRTrainer();
		~KRRTrainer();
		int trainAugmentedModel();
		int trainNonAugmentedModel();
		void leaveOneOutValidation(bool aug);
	};
}


#endif