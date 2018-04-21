/*
 * Calc_cii3D_8.c
 *
 * Code generation for function 'Calc_cii3D_8'
 *
 * C source code generated on: Tue Oct 23 11:31:34 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "sqrt.h"
#include "sum.h"
#include "power.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 22, "Calc_cii3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_cii3D_8.m" };
static emlrtRSInfo b_emlrtRSI = { 26, "Calc_cii3D_8", "/Users/ccaiafa/Dropbox/Kronecker Inpainting/Test3D/Calc_cii3D_8.m" };

/* Function Declarations */

/* Function Definitions */

/*
 * function [cii] = Calc_cii3D_8(D1,D2,D3,Mask)
 */
void Calc_cii3D_8(const real_T D1[64], const real_T D2[64], const real_T D3[64], const real_T Mask[512], real_T cii[512])
{
    real_T b_cii[512];
    int32_T j3;
    int32_T j2;
    int32_T b_j1;
    int32_T i0;
    real_T b[8];
    real_T b_b[8];
    int32_T i1;
    real_T b_D1[64];
    real_T c_D1[512];
    real_T d_D1[512];
    /* 'Calc_cii3D_8:3' I1 = size(D1,1); */
    /* 'Calc_cii3D_8:4' I2 = size(D2,1); */
    /* 'Calc_cii3D_8:5' I3 = size(D3,1); */
    /* cii = zeros(I1*I2*I3,1); */
    /* 'Calc_cii3D_8:7' cii = zeros(I1,I2,I3); */
    memset((void *)&b_cii[0], 0, sizeof(real_T) << 9);
    /* mask = zeros(I1*I2,1); */
    /* mask(sub2ind([I1,I2], ind1(1:K)', ind2(1:K)'))=1; */
    /* 'Calc_cii3D_8:12' for j3=1:I3 */
    for (j3 = 0; j3 < 8; j3++) {
        /* 'Calc_cii3D_8:13' for j2=1:I2 */
        for (j2 = 0; j2 < 8; j2++) {
            /* 'Calc_cii3D_8:14' for j1=1:I1 */
            for (b_j1 = 0; b_j1 < 8; b_j1++) {
                /* w = kron(D2(:,j2),D1(:,j1)).*mask; */
                /* W = (D1(:,j1)*D2(:,j2)').*Mask; */
                /* 'Calc_cii3D_8:18' w = D1(:,j1)*D2(:,j2)'; */
                for (i0 = 0; i0 < 8; i0++) {
                    b[i0] = D2[i0 + (j2 << 3)];
                    /* 'Calc_cii3D_8:19' w = w(:)*D3(:,j3)'; */
                    b_b[i0] = D3[i0 + (j3 << 3)];
                }
                /* 'Calc_cii3D_8:20' w = w(:).*Mask(:); */
                /* cii(sub2ind([I1,I2,I3], j1, j2, j3)) = sqrt(sum(w(:).^2)); */
                /* 'Calc_cii3D_8:22' cii(j1, j2, j3) = sqrt(sum(w(:).^2)); */
                EMLRTPUSHRTSTACK(&emlrtRSI);
                for (i0 = 0; i0 < 8; i0++) {
                    for (i1 = 0; i1 < 8; i1++) {
                        b_D1[i1 + (i0 << 3)] = D1[i1 + (b_j1 << 3)] * b[i0];
                    }
                }
                for (i0 = 0; i0 < 8; i0++) {
                    for (i1 = 0; i1 < 64; i1++) {
                        c_D1[i1 + (i0 << 6)] = b_D1[i1] * b_b[i0];
                    }
                }
                for (i0 = 0; i0 < 512; i0++) {
                    d_D1[i0] = c_D1[i0] * Mask[i0];
                }
                power(d_D1, 2.0, c_D1);
                b_cii[(b_j1 + (j2 << 3)) + (j3 << 6)] = sum(c_D1);
                b_sqrt(&b_cii[(b_j1 + (j2 << 3)) + (j3 << 6)]);
                EMLRTPOPRTSTACK(&emlrtRSI);
                emlrtBreakCheck();
            }
            emlrtBreakCheck();
        }
        emlrtBreakCheck();
    }
    /* 'Calc_cii3D_8:26' cii = reshape(cii,[I1*I2*I3,1]); */
    EMLRTPUSHRTSTACK(&b_emlrtRSI);
    memcpy((void *)&cii[0], (void *)&b_cii[0], sizeof(real_T) << 9);
    EMLRTPOPRTSTACK(&b_emlrtRSI);
}
/* End of code generation (Calc_cii3D_8.c) */
