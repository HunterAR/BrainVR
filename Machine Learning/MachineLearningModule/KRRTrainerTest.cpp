#include "stdafx.h"
#include "CppUnitTest.h"
#include "KRRTrainer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MachineLearningTraining;

namespace MachineLearningLibrary
{
	TEST_CLASS(KRRTrainerTest)
	{
	public:
		

		char* folder_path = "C:\\Users\Ishan\\Documents\\5th Year\\Capstone\\MachineLearningPrototype2\\MachineLearningLibrary\\data";
		KRRTrainer krr;

		TEST_METHOD_INITIALIZE(InitializeRegressionTest){
			krr.setDataFolder(folder_path);
			krr.trainAugmentedModel();
			krr.trainNonAugmentedModel();
		}

		TEST_METHOD(SetInputDataTest){
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			std::vector<sample_type> object_data = krr.getInputData();
			int count = 0;
			for (sample_type x : data){
				Assert::AreEqual(x(0, 0), object_data.at(count)(0, 0), 0.01,
					L"Regression Input Data Test failed", LINE_INFO());
				Assert::AreEqual(x(1, 0), object_data.at(count)(1, 0), 0.01,
					L"Regression Input Data Test failed", LINE_INFO());
			}
		}

		TEST_METHOD(SetAugmentedOutputsTest){
			std::vector<double> data;
			double sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			std::vector<double> object_data = krr.getAugmentedOutputs();
			int count = 0;
			for (double x : data){
				Assert::AreEqual(x, object_data.at(count), 0.01,
					L"Regression Input Data Test failed", LINE_INFO());
			}
		}

		TEST_METHOD(SetNonAugmentedOutputsTest){
			std::vector<double> data;
			double sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			std::vector<double> object_data = krr.getNonAugmentedOutputs();
			int count = 0;
			for (double x : data){
				Assert::AreEqual(x, object_data.at(count), 0.01,
					L"Regression Input Data Test failed", LINE_INFO());
			}
		}

	};
}