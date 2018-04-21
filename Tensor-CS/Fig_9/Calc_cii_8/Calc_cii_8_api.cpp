/*
 * Calc_cii_8_api.cpp
 *
 * Code generation for function 'Calc_cii_8_api'
 *
 * C source code generated on: Wed Oct 17 12:40:49 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_cii_8.h"
#include "Calc_cii_8_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64]);
static void c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64]);
static void emlrt_marshallIn(const mxArray *D1, const char_T *identifier, real_T y[64]);
static const mxArray *emlrt_marshallOut(const real_T u[64]);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64])
{
    c_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64])
{
    int32_T i;
    int32_T iv2[2];
    int32_T i1;
    for (i = 0; i < 2; i++) {
        iv2[i] = 8;
    }
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv2);
    for (i = 0; i < 8; i++) {
        for (i1 = 0; i1 < 8; i1++) {
            ret[i1 + (i << 3)] = (*(real_T (*)[64])mxGetData(src))[i1 + (i << 3)];
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

static const mxArray *emlrt_marshallOut(const real_T u[64])
{
    const mxArray *y;
    static const int32_T iv1[1] = { 64 };
    const mxArray *m1;
    real_T (*pData)[];
    int32_T i;
    y = NULL;
    m1 = mxCreateNumericArray(1, (int32_T *)&iv1, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m1);
    for (i = 0; i < 64; i++) {
        (*pData)[i] = u[i];
    }
    emlrtAssign(&y, m1);
    return y;
}

void Calc_cii_8_api(const mxArray * const prhs[3], const mxArray *plhs[1])
{
    real_T D1[64];
    real_T D2[64];
    real_T Mask[64];
    real_T cii[64];
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "D1", D1);
    emlrt_marshallIn(emlrtAliasP(prhs[1]), "D2", D2);
    emlrt_marshallIn(emlrtAliasP(prhs[2]), "Mask", Mask);
    /* Invoke the target function */
    Calc_cii_8(D1, D2, Mask, cii);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(cii);
}
/* End of code generation (Calc_cii_8_api.cpp) */
