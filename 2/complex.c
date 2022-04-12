#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct complex* createComplex(int n)
{
    struct complex *c = (struct complex*)malloc(sizeof(struct complex));
    c->dimensions = n;
    c->coeffs = (float*)malloc(sizeof(float)*n);
    return c;
}

struct complex *ADD(struct complex* a, struct complex* b)
{
    assert(a->dimensions == b->dimensions);
    int n = a->dimensions;
    struct complex *c = createComplex(n);
    for (int i = 0; i < n; i++)
    {
        c->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }
    return c;
}

struct complex *SUB(struct complex* a, struct complex* b)
{
    assert(a->dimensions == b->dimensions);
    int n = a->dimensions;
    struct complex *c = createComplex(n);
    for (int i = 0; i < n; i++)
    {
        c->coeffs[i] = a->coeffs[i] - b->coeffs[i];
    }
    return c;
}

float MOD(struct complex* c)
{
    float mod = 0;
    for (int i = 0; i < c->dimensions; i++)
    {
        mod += c->coeffs[i]*c->coeffs[i];
    }
    return sqrt(mod);
}

float DOT(struct complex* a, struct complex* b)
{
    assert(a->dimensions == b->dimensions);
    int n = a->dimensions;
    float res = 0;
    for (int i = 0; i < n; i++)
    {
        res += a->coeffs[i] * b->coeffs[i];
    }
    return res;
}

float COS(struct complex* a, struct complex* b)
{
    float res = DOT(a,b)/(MOD(a)*MOD(b));
    return res;
}

void print(struct complex* c)
{
    for (int i = 0; i < c->dimensions; i++)
    {
        printf("%f ", c->coeffs[i]);
    }
    printf("\n");
}
