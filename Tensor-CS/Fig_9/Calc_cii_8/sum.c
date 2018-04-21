/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Tue Oct 16 21:33:36 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "sum.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T sum(const real_T x[64])
{
    real_T y;
    int32_T k;
    y = x[0];
    for (k = 0; k < 63; k++) {
        y += x[k + 1];
    }
    return y;
}
/* End of code generation (sum.c) */
