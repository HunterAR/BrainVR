#ifndef REGRESSION_TRAINER_H
#define REGRESSION_TRAINER_H
#include "MachineLearning.h"
#pragma once

#define MACHINE_LEARNING_API __declspec(dllexport)
using namespace MachineLearning;

namespace MachineLearningTraining{
	class MACHINE_LEARNING_API RegressionTrainer{
	public:
		RegressionTrainer();
		virtual ~RegressionTrainer();
		
		void setDataFolder(char* folder_name);
		void findDataFiles();
		void loadData();
		std::vector<sample_type> getInputData();
		std::vector<double> getAugmentedOutputs();
		std::vector<double> getNonAugmentedOutputs();
		virtual int trainAugmentedModel();
		virtual int trainNonAugmentedModel();
	protected:
		pugi::xml_parse_result setDataFile(pugi::xml_document &doc, char* file_path);
		char* setFullFilePath(std::string file_name);
		char* data_folder;
		std::vector<std::string> file_names;
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
	};
}

#endif