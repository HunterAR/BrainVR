#include "Stdafx.h"
#include "SVRPredictor.h"

using namespace dlib;

namespace MachineLearningPrediction{
	SVRPredictor::SVRPredictor(){

	}

	SVRPredictor::~SVRPredictor(){

	}

	double SVRPredictor::generatePredictionAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_aug;
		deserialize("saved_svr_aug_function.dat") >> df_aug;
		return df_aug(data);
	}

	double SVRPredictor::generatePredictionNonAugmented(sample_type data){
		dlib::decision_function<kernel_type> df_non_aug;
		deserialize("saved_svr_non_aug_function.dat") >> df_non_aug;
		return df_non_aug(data);
	}
}