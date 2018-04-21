/*
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 * C source code generated on: Tue Oct 23 11:31:34 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "sqrt.h"
#include "Calc_cii3D_8_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = { 14, "sqrt", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };
static emlrtRSInfo f_emlrtRSI = { 15, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo c_emlrtMCI = { 15, 19, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo d_emlrtMCI = { 15, 5, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static void b_eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void b_eml_error(void)
{
    const mxArray *y;
    static const int32_T iv1[2] = { 1, 30 };
    const mxArray *m1;
    static const char_T cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    y = NULL;
    m1 = mxCreateCharArray(2, iv1);
    emlrtInitCharArray(30, m1, cv1);
    emlrtAssign(&y, m1);
    error(message(y, &c_emlrtMCI), &d_emlrtMCI);
    EMLRTPOPRTSTACK(&f_emlrtRSI);
}

/*
 * 
 */
void b_sqrt(real_T *x)
{
    if (*x < 0.0) {
        EMLRTPUSHRTSTACK(&e_emlrtRSI);
        b_eml_error();
        EMLRTPOPRTSTACK(&e_emlrtRSI);
    }
    *x = muDoubleScalarSqrt(*x);
}
/* End of code generation (sqrt.c) */
