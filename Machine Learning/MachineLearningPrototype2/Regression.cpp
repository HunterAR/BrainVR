#include 

using namespace std;
using namespace dlib;

namespace MachineLearningLibrary{
	RegressionTrainer::RegressionTrainer(char* file_name){
		result = doc.load_file(file_name);
	}

	RegressionTrainer::~RegressionTrainer(){

	}

	void RegressionTrainer::setInputData(){
		std::cout << "Load result: " << result.description() << endl;

		pugi::xml_node ind_data = doc.child("data").child("independent");

		sample_type m;

		for (pugi::xml_node patient = ind_data.first_child(); patient; patient = patient.next_sibling()){
			m(0, 0) = patient.attribute("total-volume").as_double();
			m(1, 0) = patient.attribute("evan-ratio").as_double();
			input_data.push_back(m);
		}
	}

	void RegressionTrainer::setAugmentedOutputs(){
		pugi::xml_node dep_data_aug = doc.child("data").child("dependent").child("augmented");
		for (pugi::xml_node score = dep_data_aug.first_child(); score; score = score.next_sibling()){
			augmented_outputs.push_back(score.text().as_double());
		}
	}

	void RegressionTrainer::setNonAugmentedOutputs(){
		pugi::xml_node dep_data_nonaug = doc.child("data").child("dependent").child("non-augmented");
		for (pugi::xml_node score = dep_data_nonaug.first_child(); score; score = score.next_sibling()){
			non_augmented_outputs.push_back(score.text().as_double());
		}
	}
}
