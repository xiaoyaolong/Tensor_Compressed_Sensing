/*
 * kron.h
 *
 * Code generation for function 'kron'
 *
 * C source code generated on: Tue Oct 16 21:35:38 2012
 *
 */

#ifndef __KRON_H__
#define __KRON_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "Calc_CrossCorr_8_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void b_kron(const real_T A[8], const real_T B[8], real_T K[64]);
extern void kron(const real_T A[8], const real_T B[8], real_T K[64]);
#endif
/* End of code generation (kron.h) */
