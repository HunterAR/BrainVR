#include "SupportVectorRegression.h"

using namespace std;
using namespace dlib;

namespace MachineLearningLibrary{
	SupportVectorRegression::SupportVectorRegression(char* file_path) : RegressionTrainer(file_path) {

	}

	SupportVectorRegression::~SupportVectorRegression(){

	}

	int SupportVectorRegression::trainAugmentedModel(){
		try{
			setInputData();
			setTrainingParameters();
			setAugmentedOutputs();
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			serialize("saved_svr_aug_function.dat") << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl;
			return -1;
		}
		return 0;
	}

	int SupportVectorRegression::trainNonAugmentedModel(){
		try{
			setInputData();
			setTrainingParameters();
			setAugmentedOutputs();
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			serialize("saved_svr_non_aug_function.dat") << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl;
			return -1;
		}
		return 0;
	}

	double SupportVectorRegression::generatePredictionAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_non_aug;
		deserialize("saved_svr_aug_function.dat") >> df_non_aug;
		return df_non_aug(data);
	}

	double SupportVectorRegression::generatePredictionNonAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_non_aug;
		deserialize("saved_svr_non_aug_function.dat") >> df_non_aug;
		return df_non_aug(data);
	}

	void SupportVectorRegression::leaveOneOutValidation(bool aug){
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

	void SupportVectorRegression::setTrainingParameters(){
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