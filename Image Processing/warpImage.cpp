#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkHistogramMatchingImageFilter.h"
#include "itkFEMRegistrationFilter.h"
#include "itkImage.h"
//#include "QuickView.h" IMPLEMENT IF I HAVE TIME

typedef itk::Image<unsigned char, 3>                    fileImageType;
typedef itk::Image<int, 3>                              Image3DType;
typedef itk::fem::Element3DC0LinearHexahedronMembrane   Element3DType;
typedef itk::fem::FEMObject<3>                          FEMObject3DType;
typedef itk::fem::FEMRegistrationFilter<Image3DType,Image3DType,FEMObject3DType>RegistrationType;

int main(int argc, char *argv[])
{
    
    const char *fixedImageName, *movingImageName;
    if ( argc < 2 )
    {//iff less than 2 files names are found, return error
        std::cout << "Image file names missing" << std::endl;
        std::cout << "Usage: " << argv[0] << " fixedImageFile movingImageFile"<< std::endl;
        return EXIT_FAILURE;
    }
    else
    {//if 2 or more file names, set fixed and moving from input values
        fixedImageName = argv[1];
        movingImageName = argv[2];
    }
    
    //Read in the image files
    typedef itk::ImageFileReader< Image3DType > FileSourceType;
    FileSourceType::Pointer movingfilter = FileSourceType::New();
    movingfilter->SetFileName( movingImageName );
    FileSourceType::Pointer fixedfilter = FileSourceType::New();
    fixedfilter->SetFileName( fixedImageName );
    std::cout << " reading moving " << movingImageName << std::endl;
    std::cout << " reading fixed " << fixedImageName << std::endl;
    try
    {//test to see if filter applied
        movingfilter->UpdateLargestPossibleRegion();
    }
    catch( itk::ExceptionObject & e )
    {
        std::cerr << "Exception caught during reference file reading " << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
    }
    try
    {//test to see if filter applied
        fixedfilter->UpdateLargestPossibleRegion();
    }
    catch( itk::ExceptionObject & e )
    {
        std::cerr << "Exception caught during target file reading " << std::endl;
        std::cerr << e << std::endl;
        return EXIT_FAILURE;
    }

    /* IMPLEMENT LATER IS POSSIBLE TO VIEW IMAGES
    QuickView viewer;
    viewer.AddImage<ImageType>(reader->GetOutput());
    viewer.Visualize();
    */
    
    //Declare registration filter
    RegistrationType::Pointer registrationFilter = RegistrationType::New();
    registrationFilter->SetMaxLevel(1);
    registrationFilter->SetUseNormalizedGradient(true);
    registrationFilter->ChooseMetric(0);
    
    //TODO: LOOP THROUGH LANDMARK FILES TO ADD THEM TO IMAGES
    
    //Set deform parameters
    unsigned int maxiters = 100;//Max iterations
    float E = 1000;//Elasticity parameter
    float p = 2;//sets Rho for deformable registration
    
    //Set registration filter paramters
    registrationFilter->SetElasticity(E,0);
    registrationFilter->SetRho(p,0);
    registrationFilter->SetGamma(1.,0);
    registrationFilter->SetAlpha(1.);
    registrationFilter->SetMaximumIterations(maxiters,0);
    registrationFilter->SetMeshPixelsPerElementAtEachResolution(4);
    registrationFilter->SetWidthOfMetricRegion(1);
    registrationFilter->SetNumberOfIntegrationPoints(2);
    registrationFilter->SetDoLineSearchOnImageEnergy(0);
    registrationFilter->SetTimeStep(1.);
    registrationFilter->SetEmployRegridding(true);
    registrationFilter->SetUseLandmarks(false);
    std::cerr<<"Registration Filter Initialized"<<std::endl;//feedback for testing
    
    
    // Rescale the image intensities so that they are between 0 and 255
    typedef itk::RescaleIntensityImageFilter<Image3DType,Image3DType> FilterType;
    FilterType::Pointer movingrescalefilter = FilterType::New();
    FilterType::Pointer fixedrescalefilter = FilterType::New();
    movingrescalefilter->SetInput(movingfilter->GetOutput());
    fixedrescalefilter->SetInput(fixedfilter->GetOutput());
    const double desiredMinimum =  0.0;
    const double desiredMaximum =  255.0;
    movingrescalefilter->SetOutputMinimum( desiredMinimum );
    movingrescalefilter->SetOutputMaximum( desiredMaximum );
    movingrescalefilter->UpdateLargestPossibleRegion();
    fixedrescalefilter->SetOutputMinimum( desiredMinimum );
    fixedrescalefilter->SetOutputMaximum( desiredMaximum );
    fixedrescalefilter->UpdateLargestPossibleRegion();
    std::cerr<<"Rescaled Intensities"<<std::endl;
    
    // Histogram match the images
    typedef itk::HistogramMatchingImageFilter<Image3DType,Image3DType> HEFilterType;
    HEFilterType::Pointer IntensityEqualizeFilter = HEFilterType::New();
    IntensityEqualizeFilter->SetReferenceImage( fixedrescalefilter->GetOutput() );
    IntensityEqualizeFilter->SetInput( movingrescalefilter->GetOutput() );
    IntensityEqualizeFilter->SetNumberOfHistogramLevels( 100);
    IntensityEqualizeFilter->SetNumberOfMatchPoints( 15);
    IntensityEqualizeFilter->ThresholdAtMeanIntensityOn();
    IntensityEqualizeFilter->UpdateLargestPossibleRegion();
    
    // Set the images for registration filter
    registrationFilter->SetFixedImage(fixedfilter->GetOutput());
    registrationFilter->SetMovingImage(movingfilter->GetOutput());
    std::cerr<<"Set Imaged to Rescaled Values"<<std::endl;
    
    //Create Material Properties
    itk::fem::MaterialLinearElasticity::Pointer m;
    m = itk::fem::MaterialLinearElasticity::New();
    m->SetGlobalNumber(0);
    
    //Young's modulus of membrane
    m->SetYoungsModulus(registrationFilter->GetElasticity());
    m->SetCrossSectionalArea(1.0);//Cros-Sectional area
    m->SetThickness(512.0);//Thickness//just changed this
    m->SetMomentOfInertia(1.0);//Moment of Intertia
    m->SetPoissonsRatio(0.);//Poisson's ratio -- DO NOT CHOOSE 1.0
    m->SetDensityHeatProduct(1.0);//Density-Heat capacity product
    std::cerr<<"Set 'M'"<<std::endl;
    
    //Create Element Type
    Element3DType::Pointer e1 = Element3DType::New();
    e1->SetMaterial(m.GetPointer());
    registrationFilter->SetElement(e1.GetPointer());
    registrationFilter->SetMaterial(m);
    std::cerr<<"Created Material"<<std::endl;
    
    //Run Registration
    std::cerr<<"Beginning Registration"<<std::endl;
    registrationFilter->RunRegistration();
    std::cerr<<"Registration Complete"<<std::endl;
    
    //Get displacement field
    itk::ImageFileWriter<Image3DType>::Pointer warpedImageWriter;
    warpedImageWriter = itk::ImageFileWriter<Image3DType>::New();
    warpedImageWriter->SetInput(registrationFilter->GetWarpedImage());
    warpedImageWriter->SetFileName("warped.nii");
    try{
        warpedImageWriter->UpdateLargestPossibleRegion();
        std::cerr<<"Made it"<<std::endl;
    }
    catch(itk::ExceptionObject &excp)
    {
        std::cerr<<excp<<std::endl;
        return EXIT_FAILURE;
    }
}