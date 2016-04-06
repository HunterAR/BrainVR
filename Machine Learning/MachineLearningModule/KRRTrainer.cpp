#include "Stdafx.h"
#include "KRRTrainer.h"

using namespace std;
using namespace dlib;

namespace MachineLearningTraining {
	void KRRTrainer::setGamma(){
		// The radial_basis_kernel
		// has a parameter called gamma that we need to determine.  As a rule of thumb, a good 
		// gamma to try is 1.0/(mean squared distance between your sample points).  So 
		// below we are using a similar value computed from at most 2000 randomly selected
		// samples.
		double gamma = 3.0 / compute_mean_squared_distance(randomly_subsample(input_data, 2000));
		cout << "using gamma of " << gamma << endl << endl;
		trainer.set_kernel(kernel_type(gamma));
	}

	KRRTrainer::KRRTrainer(){

	}

	KRRTrainer::~KRRTrainer(){
	}

	int KRRTrainer::trainAugmentedModel(){
		try{
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			char* full_file_path = setFullFilePath("saved_krr_aug_function.dat");
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

	int KRRTrainer::trainNonAugmentedModel(){
		try{
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, non_augmented_outputs);
			char* full_file_path = setFullFilePath("saved_krr_non_aug_function.dat");
			serialize(full_file_path) << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl << std::endl;
			return -1;
		}
		return 0;
	}

	void KRRTrainer::leaveOneOutValidation(bool aug){
		// Note that the krr_trainer has the ability to tell us the leave-one-out predictions
		// for each sample.
		std::vector<double> labels;
		if (aug)
			labels = augmented_outputs;
		else
			labels = non_augmented_outputs;

		std::vector<double> loo_values;
		trainer.train(input_data, labels, loo_values);
		cout << "mean squared LOO error: " << mean_squared_error(labels, loo_values) << endl;
		cout << "R^2 LOO value:          " << r_squared(labels, loo_values) << endl;
	}
}
