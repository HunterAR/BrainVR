#include "Stdafx.h"
#include "SVRTrainer.h"

using namespace std;
using namespace dlib;

namespace MachineLearningTraining{
	SVRTrainer::SVRTrainer() {

	}

	SVRTrainer::~SVRTrainer(){

	}

	int SVRTrainer::trainAugmentedModel(){
		try{
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			char* full_file_path = setFullFilePath("saved_svr_aug_function.dat");
			serialize(full_file_path) << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl;
			return -1;
		}
		return 0;
	}

	int SVRTrainer::trainNonAugmentedModel(){
		try{
			// Now do the training and save the results
			decision_function<kernel_type> df_non_aug = trainer.train(input_data, non_augmented_outputs);
			char* full_file_path = setFullFilePath("saved_svr_non_aug_function.dat");
			serialize(full_file_path) << df_non_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl;
			return -1;
		}
		return 0;
	}

	void SVRTrainer::leaveOneOutValidation(bool aug){
		if (aug){
			randomize_samples(input_data, augmented_outputs);
			cout << "MSE and R-Squared: " << cross_validate_regression_trainer(trainer, input_data, augmented_outputs, 5) << endl;
		}
		else{
			randomize_samples(input_data, non_augmented_outputs);
			cout << "MSE and R-Squared: " << cross_validate_regression_trainer(trainer, input_data, non_augmented_outputs, 5) << endl;
		}
	}

	//private functions follow

	void SVRTrainer::setTrainingParameters(){
		trainer.set_kernel(kernel_type(0.1));

		// This parameter is the usual regularization parameter.  It determines the trade-off 
		// between trying to reduce the training error or allowing more errors but hopefully 
		// improving the generalization of the resulting function.  Larger values encourage exact 
		// fitting while smaller values of C may encourage better generalization.
		trainer.set_c(10);

		// Epsilon-insensitive regression means we do regression but stop trying to fit a data 
		// point once it is "close enough" to its target value.  This parameter is the value that 
		// controls what we mean by "close enough".  In this case, I'm saying I'm happy if the
		// resulting regression function gets within 0.001 of the target value.
		trainer.set_epsilon_insensitivity(0.001);
	}
}