/*
 * kron.cpp
 *
 * Code generation for function 'kron'
 *
 * C source code generated on: Tue Oct 16 21:34:00 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "kron.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo c_emlrtBCI = { 1, 64, 37, 17, "", "kron", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/ops/kron.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void kron(const real_T A[8], const real_T B[8], real_T K[64])
{
    int32_T kidx;
    int32_T i1;
    int32_T i2;
    kidx = 0;
    for (i1 = 0; i1 < 8; i1++) {
        for (i2 = 0; i2 < 8; i2++) {
            kidx++;
            K[emlrtBoundsCheckR2011a(kidx, &c_emlrtBCI, &emlrtContextGlobal) - 1] = A[i1] * B[i2];
        }
    }
}
/* End of code generation (kron.cpp) */
