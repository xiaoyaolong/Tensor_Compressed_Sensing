/*
 * Calc_CrossCorr3D_8.h
 *
 * Code generation for function 'Calc_CrossCorr3D_8'
 *
 * C source code generated on: Mon Oct 22 16:05:11 2012
 *
 */

#ifndef __CALC_CROSSCORR3D_8_H__
#define __CALC_CROSSCORR3D_8_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "Calc_CrossCorr3D_8_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void Calc_CrossCorr3D_8(const real_T D1[64], const real_T D2[64], const real_T D3[64], const real_T i1[512], const real_T i2[512], const real_T i3[512], real_T p, const real_T Mask[512], real_T b_data[512], int32_T b_sizes[1]);
#endif
/* End of code generation (Calc_CrossCorr3D_8.h) */
