#include "KernelRidgeRegression.h"
#include "SupportVectorRegression.h"

using namespace std;
using namespace MachineLearningLibrary;

void main(){
	char* file_path = "machinelearning.xml";
	KernelRidgeRegression *krr = new KernelRidgeRegression(file_path);
	krr->trainAugmentedModel();
	delete krr;

	SupportVectorRegression *svr = new SupportVectorRegression(file_path);
	svr->trainNonAugmentedModel();
	delete svr;
}