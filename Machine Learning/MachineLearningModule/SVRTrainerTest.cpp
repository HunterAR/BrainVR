#include "stdafx.h"
#include "CppUnitTest.h"
#include "SVRTrainer.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dlib;

namespace MachineLearningTraining
{
	TEST_CLASS(SupportVectorRegressionTest)
	{
	public:
		
		char* file_path = "machinelearning.xml";
		SVRTrainer svr;

		TEST_METHOD_INITIALIZE(InitializeSVRTest){
			//svr.setDataFile(file_path);
			svr.trainAugmentedModel();
			svr.trainNonAugmentedModel();
		}

		TEST_METHOD(TrainAugmentedModelTest)
		{
			dlib::decision_function<kernel_type> df_aug;
			dlib::decision_function<kernel_type> test_aug;
			deserialize("saved_svr_aug_function.dat") >> df_aug;
			deserialize("test_svr_aug_function.dat") >> test_aug;
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			for (sample_type x : data){
				Assert::AreEqual(test_aug(x), df_aug(x), 0.01,
					L"SVR TrainAugmentedModel Test failed", LINE_INFO());
			}
		}

		TEST_METHOD(TrainNonAugmentedModelTest){
			dlib::decision_function<kernel_type> df_aug;
			dlib::decision_function<kernel_type> test_aug;
			deserialize("saved_svr_non_aug_function.dat") >> df_aug;
			deserialize("test_svr_non_aug_function.dat") >> test_aug;
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			for (sample_type x : data){
				Assert::AreEqual(test_aug(x), df_aug(x), 0.01,
					L"SVR TrainNonAugmentedModel Test failed", LINE_INFO());
			}
		}


	};
}