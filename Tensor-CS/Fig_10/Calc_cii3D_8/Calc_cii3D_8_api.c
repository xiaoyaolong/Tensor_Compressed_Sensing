/*
 * Calc_cii3D_8_api.c
 *
 * Code generation for function 'Calc_cii3D_8_api'
 *
 * C source code generated on: Tue Oct 23 11:31:34 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii3D_8.h"
#include "Calc_cii3D_8_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64]);
static void c_emlrt_marshallIn(const mxArray *Mask, const char_T *identifier, real_T y[512]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[512]);
static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64]);
static void emlrt_marshallIn(const mxArray *D1, const char_T *identifier, real_T y[64]);
static const mxArray *emlrt_marshallOut(const real_T u[512]);
static void f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[512]);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64])
{
    e_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *Mask, const char_T *identifier, real_T y[512])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(Mask), &thisId, y);
    emlrtDestroyArray(&Mask);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[512])
{
    f_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64])
{
    int32_T i;
    int32_T iv3[2];
    int32_T i2;
    for (i = 0; i < 2; i++) {
        iv3[i] = 8;
    }
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv3);
    for (i = 0; i < 8; i++) {
        for (i2 = 0; i2 < 8; i2++) {
            ret[i2 + (i << 3)] = (*(real_T (*)[64])mxGetData(src))[i2 + (i << 3)];
        }
    }
    emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *D1, const char_T *identifier, real_T y[64])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(D1), &thisId, y);
    emlrtDestroyArray(&D1);
}

static const mxArray *emlrt_marshallOut(const real_T u[512])
{
    const mxArray *y;
    static const int32_T iv2[1] = { 512 };
    const mxArray *m2;
    real_T (*pData)[];
    int32_T i;
    y = NULL;
    m2 = mxCreateNumericArray(1, (int32_T *)&iv2, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m2);
    for (i = 0; i < 512; i++) {
        (*pData)[i] = u[i];
    }
    emlrtAssign(&y, m2);
    return y;
}

static void f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[512])
{
    int32_T i;
    int32_T iv4[3];
    int32_T i3;
    int32_T i4;
    for (i = 0; i < 3; i++) {
        iv4[i] = 8;
    }
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 3U, iv4);
    for (i = 0; i < 8; i++) {
        for (i3 = 0; i3 < 8; i3++) {
            for (i4 = 0; i4 < 8; i4++) {
                ret[(i4 + (i3 << 3)) + (i << 6)] = (*(real_T (*)[512])mxGetData(src))[(i4 + (i3 << 3)) + (i << 6)];
            }
        }
    }
    emlrtDestroyArray(&src);
}

void Calc_cii3D_8_api(const mxArray * const prhs[4], const mxArray *plhs[1])
{
    real_T D1[64];
    real_T D2[64];
    real_T D3[64];
    real_T Mask[512];
    real_T cii[512];
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "D1", D1);
    emlrt_marshallIn(emlrtAliasP(prhs[1]), "D2", D2);
    emlrt_marshallIn(emlrtAliasP(prhs[2]), "D3", D3);
    c_emlrt_marshallIn(emlrtAliasP(prhs[3]), "Mask", Mask);
    /* Invoke the target function */
    Calc_cii3D_8(D1, D2, D3, Mask, cii);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(cii);
}
/* End of code generation (Calc_cii3D_8_api.c) */
