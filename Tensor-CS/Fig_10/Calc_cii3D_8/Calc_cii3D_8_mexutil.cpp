/*
 * Calc_cii3D_8_mexutil.cpp
 *
 * Code generation for function 'Calc_cii3D_8_mexutil'
 *
 * C source code generated on: Tue Oct 23 11:31:45 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "Calc_cii3D_8_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m3;
    pArray = b;
    return emlrtCallMATLAB(1, &m3, 1, &pArray, "message", TRUE, location);
}
/* End of code generation (Calc_cii3D_8_mexutil.cpp) */
