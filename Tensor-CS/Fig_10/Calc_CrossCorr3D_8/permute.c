/*
 * permute.c
 *
 * Code generation for function 'permute'
 *
 * C source code generated on: Mon Oct 22 16:04:55 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_CrossCorr3D_8.h"
#include "permute.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
void permute(const real_T a[64], real_T b[64])
{
    memcpy((void *)&b[0], (void *)&a[0], sizeof(real_T) << 6);
}
/* End of code generation (permute.c) */
