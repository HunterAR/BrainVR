#ifndef REGRESSION_TRAINER_H
#define REGRESSION_TRAINER_H
#include "MachineLearning.h"
#pragma once

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

using namespace MachineLearning;

namespace MachineLearningTraining{
	class RegressionTrainer{
	public:
		RegressionTrainer();
		virtual ~RegressionTrainer();
		
		void setDataFolder(char* folder_name);
		std::vector<sample_type> getInputData();
		std::vector<double> getAugmentedOutputs();
		std::vector<double> getNonAugmentedOutputs();
	protected:
		pugi::xml_parse_result setDataFile(pugi::xml_document &doc, char* file_name);
		std::vector<char*> findDataFiles();
		char* data_folder;
		std::vector<char*> file_names;
		std::vector<sample_type> input_data;
		/*
		sample_type m;
		m(0, 0) = 14.86;
		m(1, 0) = 0.24;
		*/
		std::vector<double> augmented_outputs;
		std::vector<double> non_augmented_outputs;
		pugi::xml_parse_result result;

		void setInputData();
		void setAugmentedOutputs();
		void setNonAugmentedOutputs();
		virtual int trainAugmentedModel();
		virtual int trainNonAugmentedModel();
	};
}

#endif