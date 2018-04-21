/*
 * Calc_cii3D_8_mex.cpp
 *
 * Code generation for function 'Calc_cii3D_8'
 *
 * C source code generated on: Tue Oct 23 11:31:45 2012
 *
 */

/* Include files */
#include "mex.h"
#include "Calc_cii3D_8_api.h"
#include "Calc_cii3D_8_initialize.h"
#include "Calc_cii3D_8_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void Calc_cii3D_8_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "Calc_cii3D_8", NULL, false, NULL };

/* Function Definitions */
static void Calc_cii3D_8_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Temporary copy for mex outputs. */
  mxArray *outputs[1];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  /* Check for proper number of arguments. */
  if(nrhs != 4) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","4 inputs required for entry-point 'Calc_cii3D_8'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'Calc_cii3D_8'.");
  }
  /* Module initialization. */
  Calc_cii3D_8_initialize(&emlrtContextGlobal);
  /* Call the function. */
  Calc_cii3D_8_api(prhs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  Calc_cii3D_8_terminate();
}
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(Calc_cii3D_8_atexit);
  emlrtClearAllocCount(&emlrtContextGlobal, 0, 0, NULL);
  /* Dispatch the entry-point. */
  Calc_cii3D_8_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (Calc_cii3D_8_mex.cpp) */
