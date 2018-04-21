/*
 * Calc_CrossCorr_8.c
 *
 * Code generation for function 'Calc_CrossCorr_8'
 *
 * C source code generated on: Wed Oct 17 12:42:59 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_CrossCorr_8.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = { 13, 11, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo emlrtBCI = { 1, 8, 13, 11, "D1", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 13, 23, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo b_emlrtBCI = { 1, 8, 13, 23, "D2", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 17, 17, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo c_emlrtBCI = { 1, 8, 17, 17, "D1", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 17, 33, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo d_emlrtBCI = { 1, 8, 17, 33, "D2", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 20, 5, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo e_emlrtBCI = { 1, 64, 20, 5, "b", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtBCInfo f_emlrtBCI = { 1, 64, 13, 11, "i1", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo f_emlrtDCI = { 13, 11, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo g_emlrtBCI = { 1, 64, 13, 23, "i2", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtDCInfo g_emlrtDCI = { 13, 23, "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 1 };
static emlrtBCInfo h_emlrtBCI = { 1, 64, 17, 17, "i1", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtBCInfo i_emlrtBCI = { 1, 64, 17, 33, "i2", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };
static emlrtBCInfo j_emlrtBCI = { 1, 64, 17, 4, "b", "Calc_CrossCorr_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/2Dcase/Calc_CrossCorr_8.m", 0 };

/* Function Declarations */
static real_T ceval_xdot(int32_T n, const real_T x[8], int32_T ix0, int32_T incx, const real_T y[8], int32_T iy0, int32_T incy);

/* Function Definitions */

/*
 * 
 */
static real_T ceval_xdot(int32_T n, const real_T x[8], int32_T ix0, int32_T incx, const real_T y[8], int32_T iy0, int32_T incy)
{
    return ddot32(&n, &x[0], &incx, &y[0], &incy);
}

/*
 * function [b] = Calc_CrossCorr_8(D1,D2,i1,i2,p,Mask)
 */
void Calc_CrossCorr_8(const real_T D1[64], const real_T D2[64], const real_T i1[64], const real_T i2[64], real_T p, const real_T Mask[64], real_T b_data[64], int32_T b_sizes[1])
{
    real_T b[64];
    int32_T b_i2;
    int32_T b_i1;
    int32_T i0;
    real_T b_b[8];
    int32_T c_i1;
    real_T b_D1[64];
    real_T W[64];
    real_T loop_ub;
    real_T c_b[8];
    /* p = length(i1); */
    /* b = zeros(p-1,1); */
    /* 'Calc_CrossCorr_8:5' b = zeros(64,1); */
    memset((void *)&b[0], 0, sizeof(real_T) << 6);
    /* I1 = size(D1,1); */
    /* I2 = size(D2,2); */
    /* mask = zeros(I1*I2,1); */
    /* mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1; */
    /* w = kron(D2(:,i2(p)),D1(:,i1(p))).*mask; */
    /* 'Calc_CrossCorr_8:13' W = (D1(:,i1(p))*D2(:,i2(p))').*Mask; */
    emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i1[emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(p, &f_emlrtDCI, &emlrtContextGlobal), &f_emlrtBCI, &emlrtContextGlobal) - 1], &emlrtDCI, &emlrtContextGlobal), &emlrtBCI, &emlrtContextGlobal);
    b_i2 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i2[emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(p, &g_emlrtDCI, &emlrtContextGlobal), &g_emlrtBCI, &emlrtContextGlobal) - 1], &b_emlrtDCI, &emlrtContextGlobal), &b_emlrtBCI, &emlrtContextGlobal);
    b_i1 = (int32_T)i1[(int32_T)p - 1];
    for (i0 = 0; i0 < 8; i0++) {
        b_b[i0] = D2[i0 + ((b_i2 - 1) << 3)];
        for (c_i1 = 0; c_i1 < 8; c_i1++) {
            b_D1[c_i1 + (i0 << 3)] = D1[c_i1 + ((b_i1 - 1) << 3)] * b_b[i0];
            W[c_i1 + (i0 << 3)] = b_D1[c_i1 + (i0 << 3)] * Mask[c_i1 + (i0 << 3)];
        }
    }
    /* 'Calc_CrossCorr_8:15' for p1=1:p-1 */
    loop_ub = p - 1.0;
    b_i2 = 1;
    while ((real_T)b_i2 <= loop_ub) {
        /* b(p1) = kron(D2(:,i2(p1))',D1(:,i1(p1))')*w; */
        /* 'Calc_CrossCorr_8:17' b(p1) = D1(:,i1(p1))'*W*D2(:,i2(p1)); */
        b_i1 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i1[emlrtBoundsCheckR2011a(b_i2, &h_emlrtBCI, &emlrtContextGlobal) - 1], &c_emlrtDCI, &emlrtContextGlobal), &c_emlrtBCI, &emlrtContextGlobal);
        memcpy((void *)&b_b[0], (void *)&D1[(b_i1 - 1) << 3], sizeof(real_T) << 3);
        emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i2[emlrtBoundsCheckR2011a(b_i2, &i_emlrtBCI, &emlrtContextGlobal) - 1], &d_emlrtDCI, &emlrtContextGlobal), &d_emlrtBCI, &emlrtContextGlobal);
        for (i0 = 0; i0 < 8; i0++) {
            c_b[i0] = 0.0;
            for (c_i1 = 0; c_i1 < 8; c_i1++) {
                c_b[i0] += b_b[c_i1] * W[c_i1 + (i0 << 3)];
            }
        }
        b[emlrtBoundsCheckR2011a(b_i2, &j_emlrtBCI, &emlrtContextGlobal) - 1] = ceval_xdot(8, c_b, 1, 1, *(real_T (*)[8])&D2[((int32_T)i2[b_i2 - 1] - 1) << 3], 1, 1);
        b_i2++;
        emlrtBreakCheck();
    }
    /* 'Calc_CrossCorr_8:20' b = b(1:p-1); */
    loop_ub = p - 1.0;
    if (1.0 > loop_ub) {
        i0 = 0;
    } else {
        i0 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(loop_ub, &e_emlrtDCI, &emlrtContextGlobal), &e_emlrtBCI, &emlrtContextGlobal);
    }
    b_sizes[0] = i0;
    b_i2 = i0 - 1;
    for (i0 = 0; i0 <= b_i2; i0++) {
        b_data[i0] = b[i0];
    }
}
/* End of code generation (Calc_CrossCorr_8.c) */
