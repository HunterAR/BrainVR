#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <dlib/svm.h>
#include "pugixml.hpp"

namespace MachineLearningLibrary{
	// Here we declare that our samples will be 2 dimensional column vectors.  
	typedef dlib::matrix<double, 2, 1> sample_type;

	// Now we are making a typedef for the kind of kernel we want to use.  I picked the
	// radial basis kernel because it only has one parameter and generally gives good
	// results without much fiddling.
	typedef dlib::radial_basis_kernel<sample_type> kernel_type;
}
