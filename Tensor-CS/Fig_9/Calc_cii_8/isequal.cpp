/*
 * isequal.cpp
 *
 * Code generation for function 'isequal'
 *
 * C source code generated on: Tue Oct 16 21:34:00 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "isequal.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
boolean_T isequal(const real_T varargin_1[2], const real_T varargin_2[2])
{
    boolean_T p;
    boolean_T b_p;
    int32_T k;
    boolean_T exitg1;
    p = FALSE;
    b_p = TRUE;
    k = 0;
    exitg1 = 0U;
    while ((exitg1 == 0U) && (k + 1 <= 2)) {
        if (!(varargin_1[k] == varargin_2[k])) {
            b_p = FALSE;
            exitg1 = 1U;
        } else {
            k++;
        }
    }
    if (!b_p) {
    } else {
        p = TRUE;
    }
    return p;
}
/* End of code generation (isequal.cpp) */
