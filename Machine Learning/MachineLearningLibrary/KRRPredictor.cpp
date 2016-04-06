#include "Stdafx.h"
#include "KRRPredictor.h"

using namespace dlib;

namespace MachineLearningPrediction{
	KRRPredictor::KRRPredictor(){

	}

	KRRPredictor::~KRRPredictor(){

	}

	double KRRPredictor::generatePredictionAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_aug;
		deserialize("saved_krr_aug_function.dat") >> df_aug;
		return df_aug(data);
	}

	double KRRPredictor::generatePredictionNonAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_non_aug;
		deserialize("saved_krr_non_aug_function.dat") >> df_non_aug;
		return df_non_aug(data);
	}
}