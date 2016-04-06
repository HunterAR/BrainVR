#include "stdafx.h"
#include "CppUnitTest.h"
#include "SVRPredictor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MachineLearningPrediction
{
	TEST_CLASS(SVRPredictorTest)
	{
	public:

		char* file_path = "machinelearning.xml";
		

		TEST_METHOD_INITIALIZE(InitializeSVRTest){
			//svr.setDataFile(file_path);
		}

		TEST_METHOD(GeneratePredictionAugmentedTest){
			SVRPredictor svr;
			dlib::decision_function<kernel_type> test_aug;
			dlib::deserialize("test_aug_function.dat") >> test_aug;
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			for (sample_type x : data){
				Assert::AreEqual(test_aug(x), svr.generatePredictionAugmented(x), 0.01,
					L"SVR GeneratePredictionAugmented Test failed", LINE_INFO());
			}
		}

		TEST_METHOD(GeneratePredictionNonAugmentedTest){
			dlib::decision_function<kernel_type> test;
			dlib::deserialize("test_non_aug_function.dat") >> test;
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			for (sample_type x : data){
				//Assert::AreEqual(test(x), svr.generatePredictionAugmented(x), 0.01,
				//	L"SVR GeneratePredictionNonAugmented Test failed", LINE_INFO());
			}
		}

	};
}