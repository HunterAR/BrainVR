#include <vector>
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <dlib/svm.h>
#include "pugixml-1.7/src/pugixml.hpp"

namespace MachineLearning{
    // Here we declare that our samples will be 2 dimensional column vectors.
    typedef dlib::matrix<double, 3, 1> sample_type;

    // Now we are making a typedef for the kind of kernel we want to use.  I picked the
    // radial basis kernel because it only has one parameter and generally gives good
    // results without much fiddling.
    typedef dlib::radial_basis_kernel<sample_type> kernel_type;
}
