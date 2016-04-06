
#include "RegressionTrainer.h"
#include "dirent.h"

using namespace std;
using namespace dlib;
using namespace MachineLearning;

namespace MachineLearningTraining{
	RegressionTrainer::RegressionTrainer(){
		file_names = findDataFiles();
	}

	RegressionTrainer::~RegressionTrainer(){

	}

	pugi::xml_parse_result RegressionTrainer::setDataFile(pugi::xml_document &doc, char *file_name){
		return doc.load_file(file_name);
	}

	void RegressionTrainer::setDataFolder(char *folder_name){
		data_folder = folder_name;
	}

	std::vector<char*> RegressionTrainer::findDataFiles(){
		DIR *dir;
		struct dirent *ent;
		std::vector<char*> file_names;
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
		return file_names;
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

	void RegressionTrainer::setInputData(){
		pugi::xml_document doc;

		for (unsigned i = 0; i < file_names.size(); i++){
			setDataFile(doc, file_names[i]);
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
			setDataFile(doc, file_names[i]);
			std::cout << "Load result: " << result.description() << endl;

			pugi::xml_node output = doc.child("case").child("studyresults").child("averageangledeviation");
			augmented_outputs.push_back(output.text().as_double());
		}
	}

	void RegressionTrainer::setNonAugmentedOutputs(){
		pugi::xml_document doc;
		for (unsigned i = 0; i < file_names.size(); i++){
			setDataFile(doc, file_names[i]);
			std::cout << "Load result: " << result.description() << endl;

			pugi::xml_node output = doc.child("case").child("studyresults").child("averageangledeviationAR");
			augmented_outputs.push_back(output.text().as_double());
		}
	}
	
	int RegressionTrainer::trainAugmentedModel(){
		return 0;
	}

	int RegressionTrainer::trainNonAugmentedModel(){
		return 0;
	}

	
}
