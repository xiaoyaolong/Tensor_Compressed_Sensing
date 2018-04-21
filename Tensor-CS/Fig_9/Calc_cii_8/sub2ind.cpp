/*
 * sub2ind.cpp
 *
 * Code generation for function 'sub2ind'
 *
 * C source code generated on: Wed Oct 17 00:45:12 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "sub2ind.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtBCInfo d_emlrtBCI = { -1, -1, 65, 10, "", "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m", 0 };
static emlrtBCInfo e_emlrtBCI = { -1, -1, 65, 24, "", "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m", 0 };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
boolean_T allinrange(const real_T x_data[64], const int32_T x_sizes[1], real_T lo, int32_T hi)
{
    boolean_T p;
    int32_T k;
    int32_T exitg1;
    boolean_T b0;
    k = 1;
    do {
        exitg1 = 0U;
        if (k <= x_sizes[0]) {
            if ((x_data[emlrtDynamicBoundsCheckR2011a(k, 1, x_sizes[0], &d_emlrtBCI, &emlrtContextGlobal) - 1] >= 1.0) && (x_data[emlrtDynamicBoundsCheckR2011a(k, 1, x_sizes[0], &e_emlrtBCI, &emlrtContextGlobal) - 1] <= 8.0)) {
                b0 = TRUE;
            } else {
                b0 = FALSE;
            }
            if (!b0) {
                p = FALSE;
                exitg1 = 1U;
            } else {
                k++;
            }
        } else {
            p = TRUE;
            exitg1 = 1U;
        }
    } while (exitg1 == 0U);
    return p;
}
/* End of code generation (sub2ind.cpp) */
