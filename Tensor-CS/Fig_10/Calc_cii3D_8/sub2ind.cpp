/*
 * sub2ind.cpp
 *
 * Code generation for function 'sub2ind'
 *
 * C source code generated on: Mon Oct 22 16:04:05 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "sub2ind.h"
#include "sqrt.h"
#include "Calc_cii3D_8_mexutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = { 19, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtRSInfo g_emlrtRSI = { 44, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtRSInfo h_emlrtRSI = { 44, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtRSInfo i_emlrtRSI = { 44, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo e_emlrtMCI = { 45, 9, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo f_emlrtMCI = { 44, 19, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo g_emlrtMCI = { 45, 9, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo h_emlrtMCI = { 44, 19, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo i_emlrtMCI = { 45, 9, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo j_emlrtMCI = { 44, 19, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * 
 */
real_T sub2ind(real_T varargin_1, real_T varargin_2, real_T varargin_3)
{
    real_T ndx;
    boolean_T p;
    const mxArray *y;
    static const int32_T iv2[2] = { 1, 30 };
    const mxArray *m2;
    static const char_T cv2[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'u', 'b', '2', 'i', 'n', 'd', ':', 'I', 'n', 'd', 'e', 'x', 'O', 'u', 't', 'O', 'f', 'R', 'a', 'n', 'g', 'e' };
    const mxArray *b_y;
    static const int32_T iv3[2] = { 1, 30 };
    const mxArray *c_y;
    static const int32_T iv4[2] = { 1, 30 };
    real_T d0;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    EMLRTPUSHRTSTACK(&f_emlrtRSI);
    if ((varargin_1 >= 1.0) && (varargin_1 <= 8.0)) {
        p = TRUE;
    } else {
        p = FALSE;
    }
    if (!p) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&g_emlrtRSI);
        y = NULL;
        m2 = mxCreateCharArray(2, iv2);
        emlrtInitCharArray(30, m2, cv2);
        emlrtAssign(&y, m2);
        error(message(y, &e_emlrtMCI), &f_emlrtMCI);
        EMLRTPOPRTSTACK(&g_emlrtRSI);
    }
    if ((varargin_2 >= 1.0) && (varargin_2 <= 8.0)) {
        p = TRUE;
    } else {
        p = FALSE;
    }
    if (!p) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&h_emlrtRSI);
        b_y = NULL;
        m2 = mxCreateCharArray(2, iv3);
        emlrtInitCharArray(30, m2, cv2);
        emlrtAssign(&b_y, m2);
        error(message(b_y, &g_emlrtMCI), &h_emlrtMCI);
        EMLRTPOPRTSTACK(&h_emlrtRSI);
    }
    if ((varargin_3 >= 1.0) && (varargin_3 <= 8.0)) {
        p = TRUE;
    } else {
        p = FALSE;
    }
    if (!p) {
        p = FALSE;
    } else {
        p = TRUE;
    }
    if (p) {
    } else {
        EMLRTPUSHRTSTACK(&i_emlrtRSI);
        c_y = NULL;
        m2 = mxCreateCharArray(2, iv4);
        emlrtInitCharArray(30, m2, cv2);
        emlrtAssign(&c_y, m2);
        error(message(c_y, &i_emlrtMCI), &j_emlrtMCI);
        EMLRTPOPRTSTACK(&i_emlrtRSI);
    }
    d0 = varargin_3;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 2.147483648E+9) {
        if (d0 >= -2.147483648E+9) {
            i2 = (int32_T)d0;
        } else {
            i2 = MIN_int32_T;
        }
    } else if (d0 >= 2.147483648E+9) {
        i2 = MAX_int32_T;
    } else {
        i2 = 0;
    }
    d0 = varargin_2;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 2.147483648E+9) {
        if (d0 >= -2.147483648E+9) {
            i3 = (int32_T)d0;
        } else {
            i3 = MIN_int32_T;
        }
    } else if (d0 >= 2.147483648E+9) {
        i3 = MAX_int32_T;
    } else {
        i3 = 0;
    }
    d0 = varargin_1;
    d0 = d0 < 0.0 ? muDoubleScalarCeil(d0 - 0.5) : muDoubleScalarFloor(d0 + 0.5);
    if (d0 < 2.147483648E+9) {
        if (d0 >= -2.147483648E+9) {
            i4 = (int32_T)d0;
        } else {
            i4 = MIN_int32_T;
        }
    } else if (d0 >= 2.147483648E+9) {
        i4 = MAX_int32_T;
    } else {
        i4 = 0;
    }
    ndx = (real_T)((i4 + ((i3 - 1) << 3)) + ((i2 - 1) << 6));
    EMLRTPOPRTSTACK(&f_emlrtRSI);
    return ndx;
}
/* End of code generation (sub2ind.cpp) */
