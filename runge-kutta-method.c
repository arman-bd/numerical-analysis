/*
Runge Kutta Method

Code By: Arman Hossain
CSE 11'th Batch,
Shanto-Mariam University of Creative Technology
Dhaka, Bangladesh

GitHub: https://github.com/arman-bd/numerical-analysis
Portfolio: https://arman-bd.github.io/
*/

#include<stdio.h>

double f(double x, double y)
{
    return x * y;
}

int main()
{
    double k1, k2, k3, k4, del_y, h, x, y, vx;

    printf("Enter x[0]: ");
    scanf("%lf", &x);

    printf("Enter y[0]: ");
    scanf("%lf", &y);

    printf("Enter h   : ");
    scanf("%lf", &h);

    printf("Enter x   : ");
    scanf("%lf", &vx);

    while(x <= vx)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + (h / 2), y + (k1 / 2));
        k3 = h * f(x + (h / 2), y + (k2 / 2));
        k4 = h * f(x + h, y + k3);
        del_y = (double) (1.00 / 6.00) * (k1 + (2 * k2) + (2 * k3) + k4);

        printf("\n x     = %.15f", x);
        printf("\n k1    = %.15f", k1);
        printf("\n k2    = %.15f", k2);
        printf("\n k3    = %.15f", k3);
        printf("\n k4    = %.15f", k4);
        printf("\n del y = %.15f", del_y);
        printf("\n y     = %.15f\n", y);

        y = (double) y + del_y;
        x = (double) x + h;
    }

    return 0;
}
