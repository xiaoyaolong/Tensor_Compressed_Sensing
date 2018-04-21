/*
 * Calc_CrossCorr_8_terminate.cpp
 *
 * Code generation for function 'Calc_CrossCorr_8_terminate'
 *
 * C source code generated on: Wed Oct 17 12:43:16 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_CrossCorr_8.h"
#include "Calc_CrossCorr_8_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void Calc_CrossCorr_8_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Calc_CrossCorr_8_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (Calc_CrossCorr_8_terminate.cpp) */
