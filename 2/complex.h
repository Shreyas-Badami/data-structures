#ifndef COMPLEX
#define COMPLEX

struct complex
{
    float *coeffs;
    int dimensions;
};

struct complex *createComplex(int);
struct complex *ADD(struct complex*, struct complex*);
struct complex *SUB(struct complex*, struct complex*);
float MOD(struct complex*);
float DOT(struct complex*, struct complex*);
float COS(struct complex*, struct complex*);
void print(struct complex*);

#endif