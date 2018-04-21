/*
 * power.cpp
 *
 * Code generation for function 'power'
 *
 * C source code generated on: Tue Oct 16 21:34:00 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "power.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void power(const real_T a[64], real_T b, real_T y[64])
{
    int32_T k;
    for (k = 0; k < 64; k++) {
        y[k] = muDoubleScalarPower(a[k], 2.0);
    }
}
/* End of code generation (power.cpp) */
