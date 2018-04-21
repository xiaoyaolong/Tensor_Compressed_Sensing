/*
 * Calc_cii3D_8_terminate.c
 *
 * Code generation for function 'Calc_cii3D_8_terminate'
 *
 * C source code generated on: Tue Oct 23 11:31:34 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "Calc_cii3D_8_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */

void Calc_cii3D_8_atexit(void)
{
    emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Calc_cii3D_8_terminate(void)
{
    emlrtLeaveRtStack(&emlrtContextGlobal);
}
/* End of code generation (Calc_cii3D_8_terminate.c) */
