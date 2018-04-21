/*
 * Calc_cii_8_terminate.c
 *
 * Code generation for function 'Calc_cii_8_terminate'
 *
 * C source code generated on: Wed Oct 17 12:40:31 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "Calc_cii_8_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void Calc_cii_8_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Calc_cii_8_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (Calc_cii_8_terminate.c) */
