/*
 * Calc_CrossCorr_8_api.c
 *
 * Code generation for function 'Calc_CrossCorr_8_api'
 *
 * C source code generated on: Wed Oct 17 12:43:00 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Calc_CrossCorr_8.h"
#include "Calc_CrossCorr_8_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64]);
static void c_emlrt_marshallIn(const mxArray *i1, const char_T *identifier, real_T y[64]);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64]);
static real_T e_emlrt_marshallIn(const mxArray *p, const char_T *identifier);
static void emlrt_marshallIn(const mxArray *D1, const char_T *identifier, real_T y[64]);
static const mxArray *emlrt_marshallOut(real_T u_data[64], int32_T u_sizes[1]);
static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64]);
static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64]);
static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId);

/* Function Definitions */

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64])
{
    g_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *i1, const char_T *identifier, real_T y[64])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    d_emlrt_marshallIn(emlrtAlias(i1), &thisId, y);
    emlrtDestroyArray(&i1);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId, real_T y[64])
{
    h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
    emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const mxArray *p, const char_T *identifier)
{
    real_T y;
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    y = f_emlrt_marshallIn(emlrtAlias(p), &thisId);
    emlrtDestroyArray(&p);
    return y;
}

static void emlrt_marshallIn(const mxArray *D1, const char_T *identifier, real_T y[64])
{
    emlrtMsgIdentifier thisId;
    thisId.fIdentifier = identifier;
    thisId.fParent = NULL;
    b_emlrt_marshallIn(emlrtAlias(D1), &thisId, y);
    emlrtDestroyArray(&D1);
}

static const mxArray *emlrt_marshallOut(real_T u_data[64], int32_T u_sizes[1])
{
    const mxArray *y;
    const mxArray *m0;
    real_T (*pData)[];
    int32_T i2;
    int32_T i;
    y = NULL;
    m0 = mxCreateNumericArray(1, (int32_T *)u_sizes, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T (*)[])mxGetPr(m0);
    i2 = 0;
    for (i = 0; i < u_sizes[0]; i++) {
        (*pData)[i2] = u_data[i];
        i2++;
    }
    emlrtAssign(&y, m0);
    return y;
}

static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *parentId)
{
    real_T y;
    y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
    emlrtDestroyArray(&u);
    return y;
}

static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64])
{
    int32_T i;
    int32_T iv0[2];
    int32_T i3;
    for (i = 0; i < 2; i++) {
        iv0[i] = 8;
    }
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv0);
    for (i = 0; i < 8; i++) {
        for (i3 = 0; i3 < 8; i3++) {
            ret[i3 + (i << 3)] = (*(real_T (*)[64])mxGetData(src))[i3 + (i << 3)];
        }
    }
    emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId, real_T ret[64])
{
    int32_T i4;
    int32_T iv1[2];
    for (i4 = 0; i4 < 2; i4++) {
        iv1[i4] = 1 + 63 * i4;
    }
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 2U, iv1);
    for (i4 = 0; i4 < 64; i4++) {
        ret[i4] = (*(real_T (*)[64])mxGetData(src))[i4];
    }
    emlrtDestroyArray(&src);
}

static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *msgId)
{
    real_T ret;
    emlrtCheckBuiltInR2011a(msgId, src, "double", FALSE, 0U, 0);
    ret = *(real_T *)mxGetData(src);
    emlrtDestroyArray(&src);
    return ret;
}

void Calc_CrossCorr_8_api(const mxArray * const prhs[6], const mxArray *plhs[1])
{
    real_T D1[64];
    real_T D2[64];
    real_T i1[64];
    real_T i2[64];
    real_T p;
    real_T Mask[64];
    int32_T b_sizes;
    real_T b_data[64];
    /* Marshall function inputs */
    emlrt_marshallIn(emlrtAliasP(prhs[0]), "D1", D1);
    emlrt_marshallIn(emlrtAliasP(prhs[1]), "D2", D2);
    c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "i1", i1);
    c_emlrt_marshallIn(emlrtAliasP(prhs[3]), "i2", i2);
    p = e_emlrt_marshallIn(emlrtAliasP(prhs[4]), "p");
    emlrt_marshallIn(emlrtAliasP(prhs[5]), "Mask", Mask);
    /* Invoke the target function */
    Calc_CrossCorr_8(D1, D2, i1, i2, p, Mask, b_data, &b_sizes);
    /* Marshall function outputs */
    plhs[0] = emlrt_marshallOut(b_data, *(int32_T (*)[1])&b_sizes);
}
/* End of code generation (Calc_CrossCorr_8_api.c) */
