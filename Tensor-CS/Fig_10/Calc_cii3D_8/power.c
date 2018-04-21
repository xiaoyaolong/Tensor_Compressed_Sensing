/*
 * power.c
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Tue Oct 23 11:31:34 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "power.h"
#include "sqrt.h"
#include "Calc_cii3D_8_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = { 40, "power", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/ops/power.m" };
static emlrtRSInfo d_emlrtRSI = { 15, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo emlrtMCI = { 15, 19, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo b_emlrtMCI = { 15, 5, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static void eml_error(void);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 31 };
    const mxArray *m0;
    static const char_T cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&d_emlrtRSI);
    y = NULL;
    m0 = mxCreateCharArray(2, iv0);
    emlrtInitCharArray(31, m0, cv0);
    emlrtAssign(&y, m0);
    error(message(y, &emlrtMCI), &b_emlrtMCI);
    EMLRTPOPRTSTACK(&d_emlrtRSI);
}

/*
 * 
 */
void power(const real_T a[512], real_T b, real_T y[512])
{
    int32_T k;
    for (k = 0; k < 512; k++) {
        if ((a[k] < 0.0) && (muDoubleScalarFloor(b) != b)) {
            EMLRTPUSHRTSTACK(&c_emlrtRSI);
            eml_error();
            EMLRTPOPRTSTACK(&c_emlrtRSI);
        }
        y[k] = muDoubleScalarPower(a[k], b);
    }
}
/* End of code generation (power.c) */
