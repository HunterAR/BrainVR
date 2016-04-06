#include "KernelRidgeRegression.h"

using namespace std;
using namespace dlib;

namespace MachineLearningLibrary {
	void KernelRidgeRegression::setGamma(){
		// The radial_basis_kernel
		// has a parameter called gamma that we need to determine.  As a rule of thumb, a good 
		// gamma to try is 1.0/(mean squared distance between your sample points).  So 
		// below we are using a similar value computed from at most 2000 randomly selected
		// samples.
		double gamma = 3.0 / compute_mean_squared_distance(randomly_subsample(input_data, 2000));
		cout << "using gamma of " << gamma << endl << endl;
		trainer.set_kernel(kernel_type(gamma));
	}

	KernelRidgeRegression::KernelRidgeRegression(char* file_path) : RegressionTrainer(file_path) {

	}

	KernelRidgeRegression::~KernelRidgeRegression(){
	}

	int KernelRidgeRegression::trainAugmentedModel(){
		try{
			setInputData();
			setGamma();
			setAugmentedOutputs();
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			serialize("saved_krr_aug_function.dat") << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl;
			return -1;
		}
		return 0;
	}

	int KernelRidgeRegression::trainNonAugmentedModel(){
		try{
			setInputData();
			setGamma();
			setAugmentedOutputs();
			// Now do the training and save the results
			decision_function<kernel_type> df_aug = trainer.train(input_data, augmented_outputs);
			serialize("saved_krr_aug_function.dat") << df_aug;
		}
		catch (exception& ex){
			std::ofstream log_file(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			log_file << ex.what() << std::endl << std::endl;
			return -1;
		}
		return 0;
	}

	double KernelRidgeRegression::generatePredictionAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_aug;
		deserialize("saved_krr_aug_function.dat") >> df_aug;
		return df_aug(data);
	}

	double KernelRidgeRegression::generatePredictionNonAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_non_aug;
		deserialize("saved_krr_non_aug_function.dat") >> df_non_aug;
		return df_non_aug(data);
	}

	void KernelRidgeRegression::leaveOneOutValidation(bool aug){
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
