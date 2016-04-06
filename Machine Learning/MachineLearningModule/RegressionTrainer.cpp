#include "stdafx.h"
#include "RegressionTrainer.h"
#include "dirent.h"

using namespace std;
using namespace dlib;
using namespace MachineLearning;

namespace MachineLearningTraining{
	RegressionTrainer::RegressionTrainer(){

	}

	RegressionTrainer::~RegressionTrainer(){

	}

	pugi::xml_parse_result RegressionTrainer::setDataFile(pugi::xml_document &doc, char *file_path){
		return doc.load_file(file_path);
	}

	void RegressionTrainer::setDataFolder(char *folder_name){
		data_folder = folder_name;
	}

	void RegressionTrainer::findDataFiles(){
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir(data_folder)) != NULL) {
			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {
				file_names.push_back(ent->d_name);
			}
			closedir(dir);
		}
		else {
			/* could not open directory */
			perror("Could not open directory");
		}
	}

	void RegressionTrainer::loadData(){
		setInputData();
		setAugmentedOutputs();
		setNonAugmentedOutputs();
	}

	std::vector<sample_type> RegressionTrainer::getInputData(){
		return input_data;
	}

	std::vector<double> RegressionTrainer::getAugmentedOutputs(){
		return augmented_outputs;
	}

	std::vector<double> RegressionTrainer::getNonAugmentedOutputs(){
		return non_augmented_outputs;
	}

	char* RegressionTrainer::setFullFilePath(std::string file_name){
		char *tmp = new char[file_name.size() + 1];
		tmp[file_name.size()] = 0;
		memcpy(tmp, file_name.c_str(), file_name.size());
		int new_size = strlen(tmp) + strlen(data_folder) + 2;
		char* full_file_path = (char*)malloc(new_size);
		char* file_sep = new char[2];
		file_sep[0] = '\\';
		file_sep[1] = '\0';
		strcpy(full_file_path, data_folder);
		strcat(full_file_path, file_sep);
		strcat(full_file_path, tmp);
		return full_file_path;
	}

	void RegressionTrainer::setInputData(){
		pugi::xml_document doc;

		for (unsigned i = 0; i < file_names.size(); i++){
			if (file_names[i] == "." || file_names[i] == "..")
				continue;
			char* full_file_path = setFullFilePath(file_names[i]);
			setDataFile(doc, full_file_path);
			std::cout << "Load result: " << result.description() << endl;

			pugi::xml_node measures = doc.child("case").child("measures");

			sample_type m;
			int count = 0;

			for (pugi::xml_node measure = measures.first_child(); measure; measure = measure.next_sibling()){
				m(count, 0) = measure.text().as_double();
				count++;
			}
			input_data.push_back(m);
		}
		
	}

	void RegressionTrainer::setAugmentedOutputs(){
		pugi::xml_document doc;
		for (unsigned i = 0; i < file_names.size(); i++){
			if (file_names[i] == "." || file_names[i] == "..")
				continue;
			char* full_file_path = setFullFilePath(file_names[i]);
			setDataFile(doc, full_file_path);
			std::cout << "Load result: " << result.description() << endl;

			pugi::xml_node output = doc.child("case").child("studyresults").child("averageangledeviationAR");
			augmented_outputs.push_back(output.text().as_double());
		}
	}

	void RegressionTrainer::setNonAugmentedOutputs(){
		pugi::xml_document doc;
		for (unsigned i = 0; i < file_names.size(); i++){
			if (file_names[i] == "." || file_names[i] == "..")
				continue;
			char* full_file_path = setFullFilePath(file_names[i]);
			setDataFile(doc, full_file_path);
			std::cout << "Load result: " << result.description() << endl;

			pugi::xml_node output = doc.child("case").child("studyresults").child("averageangledeviation");
			non_augmented_outputs.push_back(output.text().as_double());
		}
	}
	
	int RegressionTrainer::trainAugmentedModel(){
		return 0;
	}

	int RegressionTrainer::trainNonAugmentedModel(){
		return 0;
	}

	
}
