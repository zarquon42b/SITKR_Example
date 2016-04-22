#include "SimpleITK.h"
#include "R.h"
#include "Rdefines.h"
namespace sitk = itk::simple;

extern "C" {  
  extern itk::simple::Image * convertSwigSimpleITKImage( SEXP obj );
  SEXP mytest(SEXP img) {
    try {
      int* p_myint;
      sitk::Image * image = convertSwigSimpleITKImage(img);
      int dim = image->GetDimension();
      SEXP myint;
      PROTECT(myint = NEW_INTEGER(1));
      p_myint = INTEGER_POINTER(myint);
      *p_myint = dim;

      UNPROTECT(1);
      return myint;
    } catch (std::exception& e) {
      ::Rf_error( e.what());
    } catch (...) {
      ::Rf_error("unknown exception");
    }
  }
}


