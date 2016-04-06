#include "stdafx.h"
#include "CppUnitTest.h"
#include "KRRPredictor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace MachineLearningPrediction;

namespace MachineLearningLibrary
{
	TEST_CLASS(KRRPredictorTest)
	{
	public:

		KRRPredictor krr;
		
		TEST_METHOD(GeneratePredictionAugmentedTest){
			dlib::decision_function<kernel_type> test_aug;
			dlib::deserialize("test_aug_function.dat") >> test_aug;
			std::vector<sample_type> data;
			sample_type sample;
			//ADD DATA POINTS AFTER EVERYTHING IS SETTLED
			for (sample_type x : data){
				Assert::AreEqual(test_aug(x), krr.generatePredictionAugmented(x), 0.01,
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
				Assert::AreEqual(test(x), krr.generatePredictionNonAugmented(x), 0.01,
					L"SVR GeneratePredictionNonAugmented Test failed", LINE_INFO());
			}
		}
	};
}