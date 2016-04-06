#ifndef REGRESSION_H
#define REGRESSION_H
#include "MachineLearning.h"
#pragma once

namespace MachineLearningLibrary{
	class RegressionTrainer{
	public:
		RegressionTrainer(char* file_path);
		virtual ~RegressionTrainer();
	protected:
		std::vector<sample_type> input_data;
		/*
		sample_type m;
		m(0, 0) = 14.86;
		m(1, 0) = 0.24;
		*/
		std::vector<double> augmented_outputs;
		std::vector<double> non_augmented_outputs;
		pugi::xml_document doc;
		pugi::xml_parse_result result;

		void setInputData();
		void setAugmentedOutputs();
		void setNonAugmentedOutputs();
	};
}

#endif