/*
 * Calc_CrossCorr3D_8.c
 *
 * Code generation for function 'Calc_CrossCorr3D_8'
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
static emlrtRSInfo emlrtRSI = { 28, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m" };
static emlrtRSInfo b_emlrtRSI = { 55, "mtimes", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/ops/mtimes.m" };
static emlrtRSInfo c_emlrtRSI = { 53, "eml_xgemm", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };
static emlrtRSInfo d_emlrtRSI = { 26, "eml_blas_xgemm", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtRSInfo e_emlrtRSI = { 76, "eml_blas_xgemm", "/Applications/MATLAB_R2011a.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m" };
static emlrtDCInfo emlrtDCI = { 17, 10, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo emlrtBCI = { 1, 8, 17, 10, "D1", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo b_emlrtDCI = { 17, 22, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo b_emlrtBCI = { 1, 8, 17, 22, "D2", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo c_emlrtDCI = { 18, 15, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo c_emlrtBCI = { 1, 8, 18, 15, "D3", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo d_emlrtDCI = { 28, 13, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo d_emlrtBCI = { 1, 8, 28, 13, "D1", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo e_emlrtDCI = { 30, 13, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo e_emlrtBCI = { 1, 8, 30, 13, "D2", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo f_emlrtDCI = { 33, 17, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo f_emlrtBCI = { 1, 8, 33, 17, "D3", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo g_emlrtDCI = { 44, 5, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo g_emlrtBCI = { 1, 512, 44, 5, "b", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtBCInfo h_emlrtBCI = { 1, 512, 17, 10, "i1", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo h_emlrtDCI = { 17, 10, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo i_emlrtBCI = { 1, 512, 17, 22, "i2", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo i_emlrtDCI = { 17, 22, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo j_emlrtBCI = { 1, 512, 18, 15, "i3", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtDCInfo j_emlrtDCI = { 18, 15, "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 1 };
static emlrtBCInfo k_emlrtBCI = { 1, 512, 28, 13, "i1", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtBCInfo l_emlrtBCI = { 1, 512, 30, 13, "i2", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtBCInfo m_emlrtBCI = { 1, 512, 33, 17, "i3", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };
static emlrtBCInfo n_emlrtBCI = { 1, 512, 33, 4, "b", "Calc_CrossCorr3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_CrossCorr3D_8.m", 0 };

/* Function Declarations */
static real_T ceval_xdot(int32_T n, const real_T x[8], int32_T ix0, int32_T incx, const real_T y[8], int32_T iy0, int32_T incy);
static void ceval_xgemm(int32_T m, int32_T n, int32_T k, real_T alpha1, const real_T A[8], int32_T ia0, int32_T lda, const real_T B[512], int32_T ib0, int32_T ldb, real_T beta1, real_T C[64], int32_T ic0, int32_T ldc);

/* Function Definitions */

/*
 * 
 */
static real_T ceval_xdot(int32_T n, const real_T x[8], int32_T ix0, int32_T incx, const real_T y[8], int32_T iy0, int32_T incy)
{
    return ddot32(&n, &x[0], &incx, &y[0], &incy);
}

/*
 * 
 */
static void ceval_xgemm(int32_T m, int32_T n, int32_T k, real_T alpha1, const real_T A[8], int32_T ia0, int32_T lda, const real_T B[512], int32_T ib0, int32_T ldb, real_T beta1, real_T C[64], int32_T ic0, int32_T ldc)
{
    char_T TRANSA;
    char_T TRANSB;
    TRANSA = 'N';
    TRANSB = 'N';
    EMLRTPUSHRTSTACK(&e_emlrtRSI);
    dgemm32(&TRANSA, &TRANSB, &m, &n, &k, &alpha1, &A[0], &lda, &B[0], &ldb, &beta1, &C[0], &ldc);
    EMLRTPOPRTSTACK(&e_emlrtRSI);
}

/*
 * function [b] = Calc_CrossCorr3D_8(D1,D2,D3,i1,i2,i3,p,Mask)
 */
void Calc_CrossCorr3D_8(const real_T D1[64], const real_T D2[64], const real_T D3[64], const real_T i1[512], const real_T i2[512], const real_T i3[512], real_T p, const real_T Mask[512], real_T b_data[512], int32_T b_sizes[1])
{
    real_T b[512];
    int32_T b_i2;
    real_T b_b[8];
    int32_T b_i1;
    int32_T i0;
    real_T c_b[8];
    int32_T c_i1;
    real_T b_D1[64];
    real_T c_D1[512];
    real_T w[512];
    real_T loop_ub;
    int32_T p1;
    real_T y[512];
    real_T u[64];
    real_T b_u[64];
    real_T x[64];
    real_T b_y[64];
    real_T d_b[8];
    real_T e_b[8];
    /* p = length(i1); */
    /* b = zeros(p-1,1); */
    /* 'Calc_CrossCorr3D_8:5' b = zeros(512,1); */
    memset((void *)&b[0], 0, sizeof(real_T) << 9);
    /* bn = zeros(512,1); */
    /* 'Calc_CrossCorr3D_8:9' I1 = size(D1,1); */
    /* 'Calc_CrossCorr3D_8:10' I2 = size(D2,2); */
    /* 'Calc_CrossCorr3D_8:11' I3 = size(D3,2); */
    /* mask = zeros(I1*I2,1); */
    /* mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1; */
    /* w = kron(D2(:,i2(p)),D1(:,i1(p))).*mask; */
    /* W = (D1(:,i1(p))*D2(:,i2(p))').*Mask; */
    /* 'Calc_CrossCorr3D_8:17' w = D1(:,i1(p))*D2(:,i2(p))'; */
    emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i1[emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(p, &h_emlrtDCI, &emlrtContextGlobal), &h_emlrtBCI, &emlrtContextGlobal) - 1], &emlrtDCI, &emlrtContextGlobal), &emlrtBCI, &emlrtContextGlobal);
    b_i2 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i2[emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(p, &i_emlrtDCI, &emlrtContextGlobal), &i_emlrtBCI, &emlrtContextGlobal) - 1], &b_emlrtDCI, &emlrtContextGlobal), &b_emlrtBCI, &emlrtContextGlobal);
    memcpy((void *)&b_b[0], (void *)&D2[(b_i2 - 1) << 3], sizeof(real_T) << 3);
    /* 'Calc_CrossCorr3D_8:18' w = w(:)*D3(:,i3(p))'; */
    b_i2 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i3[emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(p, &j_emlrtDCI, &emlrtContextGlobal), &j_emlrtBCI, &emlrtContextGlobal) - 1], &c_emlrtDCI, &emlrtContextGlobal), &c_emlrtBCI, &emlrtContextGlobal);
    /* 'Calc_CrossCorr3D_8:19' w = w(:).*Mask(:); */
    b_i1 = (int32_T)i1[(int32_T)p - 1];
    for (i0 = 0; i0 < 8; i0++) {
        c_b[i0] = D3[i0 + ((b_i2 - 1) << 3)];
        for (c_i1 = 0; c_i1 < 8; c_i1++) {
            b_D1[c_i1 + (i0 << 3)] = D1[c_i1 + ((b_i1 - 1) << 3)] * b_b[i0];
        }
    }
    for (i0 = 0; i0 < 8; i0++) {
        for (c_i1 = 0; c_i1 < 64; c_i1++) {
            c_D1[c_i1 + (i0 << 6)] = b_D1[c_i1] * c_b[i0];
        }
    }
    /* 'Calc_CrossCorr3D_8:20' w = reshape(w,[I1,I2,I3]); */
    for (i0 = 0; i0 < 512; i0++) {
        w[i0] = c_D1[i0] * Mask[i0];
    }
    /* 'Calc_CrossCorr3D_8:22' for p1=1:p-1 */
    loop_ub = p - 1.0;
    p1 = 1;
    while ((real_T)p1 <= loop_ub) {
        /* b(p1) = kron(D2(:,i2(p1))',D1(:,i1(p1))')*w; */
        /* b(p1) = D1(:,i1(p1))'*W*D2(:,i2(p1));  */
        /* bn(p1) = double(ttensor(tensor(w),D1(:,i1(p1))',D2(:,i2(p1))',D3(:,i3(p1))')); */
        /* 'Calc_CrossCorr3D_8:28' u = D1(:,i1(p1))'*reshape(w,[I1,I2*I3]); */
        EMLRTPUSHRTSTACK(&emlrtRSI);
        memcpy((void *)&y[0], (void *)&w[0], sizeof(real_T) << 9);
        b_i1 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i1[emlrtBoundsCheckR2011a(p1, &k_emlrtBCI, &emlrtContextGlobal) - 1], &d_emlrtDCI, &emlrtContextGlobal), &d_emlrtBCI, &emlrtContextGlobal);
        memcpy((void *)&b_b[0], (void *)&D1[(b_i1 - 1) << 3], sizeof(real_T) << 3);
        EMLRTPUSHRTSTACK(&b_emlrtRSI);
        EMLRTPUSHRTSTACK(&c_emlrtRSI);
        EMLRTPUSHRTSTACK(&d_emlrtRSI);
        memset((void *)&u[0], 0, sizeof(real_T) << 6);
        ceval_xgemm(1, 64, 8, 1.0, b_b, 1, 1, y, 1, 8, 0.0, u, 1, 1);
        EMLRTPOPRTSTACK(&d_emlrtRSI);
        EMLRTPOPRTSTACK(&c_emlrtRSI);
        EMLRTPOPRTSTACK(&b_emlrtRSI);
        EMLRTPOPRTSTACK(&emlrtRSI);
        /* 'Calc_CrossCorr3D_8:29' u = reshape(u,[1,I2,I3]); */
        memcpy((void *)&b_u[0], (void *)&u[0], sizeof(real_T) << 6);
        /* 'Calc_CrossCorr3D_8:30' u = D2(:,i2(p1))'*reshape(permute(u,[2,1,3]),[I2,I3]); */
        permute(b_u, x);
        memcpy((void *)&b_y[0], (void *)&x[0], sizeof(real_T) << 6);
        b_i2 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i2[emlrtBoundsCheckR2011a(p1, &l_emlrtBCI, &emlrtContextGlobal) - 1], &e_emlrtDCI, &emlrtContextGlobal), &e_emlrtBCI, &emlrtContextGlobal);
        memcpy((void *)&b_b[0], (void *)&D2[(b_i2 - 1) << 3], sizeof(real_T) << 3);
        /* u = reshape(u,[1,1,I3]); */
        /* b(p1) = D3(:,i3(p1))'*reshape(permute(u,[3,1,2]),[I3,1]); */
        /* 'Calc_CrossCorr3D_8:33' b(p1) = D3(:,i3(p1))'*u'; */
        b_i2 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(i3[emlrtBoundsCheckR2011a(p1, &m_emlrtBCI, &emlrtContextGlobal) - 1], &f_emlrtDCI, &emlrtContextGlobal), &f_emlrtBCI, &emlrtContextGlobal);
        for (i0 = 0; i0 < 8; i0++) {
            c_b[i0] = D3[i0 + ((b_i2 - 1) << 3)];
            d_b[i0] = 0.0;
            for (c_i1 = 0; c_i1 < 8; c_i1++) {
                d_b[i0] += b_b[c_i1] * b_y[c_i1 + (i0 << 3)];
            }
            e_b[i0] = d_b[i0];
        }
        b[emlrtBoundsCheckR2011a(p1, &n_emlrtBCI, &emlrtContextGlobal) - 1] = ceval_xdot(8, c_b, 1, 1, e_b, 1, 1);
        /*     for j1=1:I1 */
        /*         for j2=1:I2 */
        /*             for j3=1:I3 */
        /*                 b(p1) = b(p1) + w(j1,j2,j3)*D1(j1,i1(p1))*D2(j2,i2(p1))*D3(j3,i3(p1)); */
        /*             end */
        /*         end */
        /*     end */
        p1++;
        emlrtBreakCheck();
    }
    /* 'Calc_CrossCorr3D_8:44' b = b(1:p-1); */
    loop_ub = p - 1.0;
    if (1.0 > loop_ub) {
        i0 = 0;
    } else {
        i0 = emlrtBoundsCheckR2011a((int32_T)emlrtIntegerCheckR2011a(loop_ub, &g_emlrtDCI, &emlrtContextGlobal), &g_emlrtBCI, &emlrtContextGlobal);
    }
    b_sizes[0] = i0;
    b_i2 = i0 - 1;
    for (i0 = 0; i0 <= b_i2; i0++) {
        b_data[i0] = b[i0];
    }
    /* bn = bn(1:p-1); */
}
/* End of code generation (Calc_CrossCorr3D_8.c) */
