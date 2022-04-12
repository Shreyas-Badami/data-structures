#include "complex.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    while (1)
    {
        char command[100];
        scanf("%s", command);
        if (strcmp("ADD", command) == 0)
        {
            int n;
            scanf("%d", &n);
            float *arr1 = (float*)malloc(sizeof(float)*n);
            float *arr2 = (float*)malloc(sizeof(float)*n);
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr1[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr2[i]);
            }
            struct complex *a = createComplex(n);
            struct complex *b = createComplex(n);
            a->coeffs = arr1;
            b->coeffs = arr2;
            struct complex *c = ADD(a, b);
            print(c);
        }
        else if (strcmp("SUB", command) == 0)
        {
            int n;
            scanf("%d", &n);
            float *arr1 = (float*)malloc(sizeof(float)*n);
            float *arr2 = (float*)malloc(sizeof(float)*n);
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr1[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr2[i]);
            }
            struct complex *a = createComplex(n);
            struct complex *b = createComplex(n);
            a->coeffs = arr1;
            b->coeffs = arr2;
            struct complex *c = SUB(a, b);
            print(c);
        }
        else if (strcmp("MOD", command) == 0)
        {
            int n;
            scanf("%d", &n);
            float *arr1 = (float*)malloc(sizeof(float)*n);
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr1[i]);
            }
            struct complex *a = createComplex(n);
            a->coeffs = arr1;
            printf("%0.2f\n", MOD(a));
        }
        else if (strcmp("DOT", command) == 0)
        {
            int n;
            scanf("%d", &n);
            float *arr1 = (float*)malloc(sizeof(float)*n);
            float *arr2 = (float*)malloc(sizeof(float)*n);
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr1[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr2[i]);
            }
            struct complex *a = createComplex(n);
            struct complex *b = createComplex(n);
            a->coeffs = arr1;
            b->coeffs = arr2;
            printf("%0.2f\n", DOT(a,b));
        }
        else if (strcmp("COS", command) == 0)
        {
            int n;
            scanf("%d", &n);
            float *arr1 = (float*)malloc(sizeof(float)*n);
            float *arr2 = (float*)malloc(sizeof(float)*n);
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr1[i]);
            }
            for (int i = 0; i < n; i++)
            {
                scanf("%f", &arr2[i]);
            }
            struct complex *a = createComplex(n);
            struct complex *b = createComplex(n);
            a->coeffs = arr1;
            b->coeffs = arr2;
            printf("%0.2f\n", COS(a,b));
        }
    }
}