/*
 * Calc_cii_8.c
 *
 * Code generation for function 'Calc_cii_8'
 *
 * C source code generated on: Wed Oct 17 12:40:31 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 14, "Calc_cii_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_cii_8.m" };
static emlrtRSInfo d_emlrtRSI = { 14, "sqrt", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };
static emlrtRSInfo e_emlrtRSI = { 15, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtRSInfo f_emlrtRSI = { 19, "sub2ind", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" };
static emlrtMCInfo c_emlrtMCI = { 15, 19, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };
static emlrtMCInfo d_emlrtMCI = { 15, 5, "eml_error", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static void eml_error(void);
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const mxArray *b, emlrtMCInfo *location);

/* Function Definitions */

/*
 * 
 */
static void eml_error(void)
{
    const mxArray *y;
    static const int32_T iv0[2] = { 1, 30 };
    const mxArray *m0;
    static const char_T cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };
    EMLRTPUSHRTSTACK(&e_emlrtRSI);
    y = NULL;
    m0 = mxCreateCharArray(2, iv0);
    emlrtInitCharArray(30, m0, cv0);
    emlrtAssign(&y, m0);
    error(message(y, &c_emlrtMCI), &d_emlrtMCI);
    EMLRTPOPRTSTACK(&e_emlrtRSI);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    pArray = b;
    emlrtCallMATLAB(0, NULL, 1, &pArray, "error", TRUE, location);
}

static const mxArray *message(const mxArray *b, emlrtMCInfo *location)
{
    const mxArray *pArray;
    const mxArray *m2;
    pArray = b;
    return emlrtCallMATLAB(1, &m2, 1, &pArray, "message", TRUE, location);
}

/*
 * function [cii] = Calc_cii_8(D1,D2,Mask)
 */
void Calc_cii_8(const real_T D1[64], const real_T D2[64], const real_T Mask[64], real_T cii[64])
{
    int32_T j2;
    int32_T b_j1;
    real_T b[8];
    int32_T k;
    int32_T i0;
    real_T b_D1[64];
    real_T c_D1[64];
    real_T y;
    /* 'Calc_cii_8:3' I1 = size(D1,1); */
    /* 'Calc_cii_8:4' I2 = size(D2,1); */
    /* 'Calc_cii_8:5' cii = zeros(I1*I2,1); */
    memset((void *)&cii[0], 0, sizeof(real_T) << 6);
    /* mask = zeros(I1*I2,1); */
    /* mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1; */
    /* 'Calc_cii_8:10' for j2=1:I2 */
    for (j2 = 0; j2 < 8; j2++) {
        /* 'Calc_cii_8:11' for j1=1:I1 */
        for (b_j1 = 0; b_j1 < 8; b_j1++) {
            /* w = kron(D2(:,j2),D1(:,j1)).*mask; */
            /* 'Calc_cii_8:13' W = (D1(:,j1)*D2(:,j2)').*Mask; */
            memcpy((void *)&b[0], (void *)&D2[j2 << 3], sizeof(real_T) << 3);
            /* 'Calc_cii_8:14' cii(sub2ind([I1,I2], j1, j2)) = sqrt(sum(W(:).^2)); */
            EMLRTPUSHRTSTACK(&emlrtRSI);
            EMLRTPUSHRTSTACK(&f_emlrtRSI);
            EMLRTPOPRTSTACK(&f_emlrtRSI);
            for (k = 0; k < 8; k++) {
                for (i0 = 0; i0 < 8; i0++) {
                    b_D1[i0 + (k << 3)] = D1[i0 + (b_j1 << 3)] * b[k];
                    c_D1[i0 + (k << 3)] = b_D1[i0 + (k << 3)] * Mask[i0 + (k << 3)];
                }
            }
            for (k = 0; k < 64; k++) {
                b_D1[k] = muDoubleScalarPower(c_D1[k], 2.0);
            }
            y = b_D1[0];
            for (k = 0; k < 63; k++) {
                y += b_D1[k + 1];
            }
            if (y < 0.0) {
                EMLRTPUSHRTSTACK(&d_emlrtRSI);
                eml_error();
                EMLRTPOPRTSTACK(&d_emlrtRSI);
            }
            cii[b_j1 + (j2 << 3)] = muDoubleScalarSqrt(y);
            EMLRTPOPRTSTACK(&emlrtRSI);
            emlrtBreakCheck();
        }
        emlrtBreakCheck();
    }
}
/* End of code generation (Calc_cii_8.c) */
