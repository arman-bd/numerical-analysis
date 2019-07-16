/*
Newton-Gregory Forward Interpolation

Code By: Arman Hossain
CSE 11'th Batch,
Shanto-Mariam University of Creative Technology
Dhaka, Bangladesh

GitHub: https://github.com/arman-bd/numerical-analysis
Portfolio: https://arman-bd.github.io/
*/

#include<stdio.h>
#include<stdlib.h>

// Function Declaration
int factorial(int);
float function_u(float, int);

int main()
{
    float u, h, a, x, e, fx, series; // Variables
    int i, j, k;
    int tr; // Total Variables

    printf("Enter Initial Point: ");
    scanf("%f", &a);

    printf("Enter End Point: ");
    scanf("%f", &e);

    printf("Enter Interval: ");
    scanf("%f", &h);

    printf("Enter Variable: ");
    scanf("%f", &x);

    // Calculate u
    u = (x - a) / h;
    printf("\nu = %f", u);

    // Calculate Total Count
    tr = (int) (((e - a) / h) + 1); // +1 for Initial Row
    printf("\nTotal Rows: %d\n\n", tr);

    // Dynamic Data Matrix
    float **dm = (float **) malloc(tr * sizeof(float *));
    for(i = 0; i < tr; i++)
    {
        dm[i] = (float *) malloc((tr - i) * sizeof(float));
    }

    // Input for Interpolation
    for(i = 0, series = a; i < tr; i++, series += h)
    {
        // Get Input for Interpolation Matrix
        printf("Element [%.0f]: ", series);
        scanf("%f", &dm[0][i]);
    }

    // Interpolate
    for(i = 1; i < tr; i++)
    {
        for(j = 0; j < (tr - i); j++)
        {
            dm[i][j] = dm[i-1][j+1] - dm[i-1][j];
        }
    }

    printf("\n\nInterpolation: ");
    for(i = 0; i < tr; i++)
    {
        for(j = 0; j < (tr - i); j++)
        {
            printf("\n%*s", i * 8, " "); // Variable Space
            printf("%.3f", dm[i][j]);
        }
    }

    // Final Calculation
    printf("\n\nf(x) = ");
    for(i = 0, fx = 0; i < tr; i++)
    {
        if(i > 0)
        {
            printf("+ ");
        }
        printf("(%.3f * %.3f) ", function_u(u, i), dm[i][0]);

        fx += function_u(u, i) * dm[i][0];
    }

    printf("\n\nResult: %f\n\n", fx);

    return 0;
}

int factorial(int n)
{
    int i, f = 1;

    for(i = 1; i <= n; i++)
    {
        f = f * i;
    }

    return f;
}

float function_u(float u, int n)
{
    int i, j;
    float val;

    if(n == 0)
    {
        val = 1;

    }else{

        val = u;
        for(i = 0, j = 1; i < (n - 1); i++, j++)
        {
            val = val * (u - j);
        }

        val = val / factorial(n);
    }

    return val;
}
