/*
 * kron.c
 *
 * Code generation for function 'kron'
 *
 * C source code generated on: Tue Oct 16 21:35:21 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_CrossCorr_8.h"
#include "kron.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo k_emlrtBCI = { 1, 64, 37, 17, "", "kron", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/ops/kron.m", 0 };
static emlrtBCInfo n_emlrtBCI = { 1, 64, 37, 17, "", "kron", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/ops/kron.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void b_kron(const real_T A[8], const real_T B[8], real_T K[64])
{
    int32_T kidx;
    int32_T b_j1;
    int32_T j2;
    kidx = 0;
    for (b_j1 = 0; b_j1 < 8; b_j1++) {
        for (j2 = 0; j2 < 8; j2++) {
            kidx++;
            K[emlrtBoundsCheckR2011a(kidx, &n_emlrtBCI, &emlrtContextGlobal) - 1] = A[b_j1] * B[j2];
        }
    }
}

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
            K[emlrtBoundsCheckR2011a(kidx, &k_emlrtBCI, &emlrtContextGlobal) - 1] = A[i1] * B[i2];
        }
    }
}
/* End of code generation (kron.c) */
