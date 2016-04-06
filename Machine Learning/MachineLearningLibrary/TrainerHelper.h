#ifndef TRAINER_HELPER_H
#define TRAINER_HELPER_H

#include "KRRTrainer.h"
#include "SVRTrainer.h"
#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

namespace MachineLearningTraining{

	class DLL_EXPORT TrainerHelper{
	public:
		KRRTrainer* krr;
		SVRTrainer* svr;
	};
}

#endif


