/*
Trapezoidal Rule Rule

Code By: Arman Hossain
CSE 11'th Batch,
Shanto-Mariam University of Creative Technology
Dhaka, Bangladesh

GitHub: https://github.com/arman-bd/numerical-analysis
Portfolio: https://arman-bd.github.io/
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Trapezoidal_Rule(int n, double h, double *y, int show);

int main()
{
    int i, n, show;
    double a, b, h, *x, *y, result;

    printf("Enter Lower Bound: ");
    scanf("%lf", &a);

    printf("Enter Upper Bound: ");
    scanf("%lf", &b);

    printf("Enter Parts: ");
    scanf("%d", &n);

    show = -1;
    while(!(show == 1 || show == 2))
    {
        printf("Display Steps?");
        printf("\n[1] Yes");
        printf("\n[2] No");
        printf("\nSteps: ");
        fflush(stdin);
        scanf("%d", &show);

    }

    // Calculate Parts [ h ]
    h = (b - a) / n;

    printf("\na = %.4f", a);
    printf("\nb = %.4f", b);
    printf("\nn = %d", n);
    printf("\nh = (b - a) / n");
    printf("\n  = (%.4f - %.4f) / %d", b, a, n);
    printf("\n  = %.4f", h);

    x = malloc(sizeof(double) * (n + 1));
    y = malloc(sizeof(double) * (n + 1));

    if(show == 1){printf("\n\nX      | Y     \n");}

    for(i = 0; i <= n; i++)
    {
        if(i == 0){
            x[i] = a;
        }else{
            x[i] = x[i-1] + h;
        }

        // Place Your Equations Here //
        y[i] = 1 / (1 + (x[i]*x[i]));

        // Display X / Y
        if(show == 1){printf("%.4f | %.4f\n", x[i], y[i]);}
    }


    printf("\n\nSolving With Trapezoidal Rule:");
    result = Trapezoidal_Rule(n, h, y, show);
    printf("\n\nResult: %f", result);
    printf("\n\n");

    // Clean Up Memory
    free(x);
    free(y);

    return 0;
}

double Trapezoidal_Rule(int n, double h, double *y, int show)
{
    int i;
    double sum, equation;

    if(show == 1){
        printf("\n\nEquation = (h / 2)[( y[0] + y[n] ) + 2( y[1] + .... + y[n-1] )]");
        printf("\n\nEquation = (%.4f / 2)[(%.4f + %.4f) + 2(", h, y[0], y[n]);
    }

    for(i = 1, sum = 0; i < n; i++){
        sum = sum + y[i];
        if(show == 1){
            if(y[i] < 0){
                printf("(%.4f)", y[i]);
            }else{
                printf("%.4f", y[i]);
            }
            if(i < n - 1){
                printf(" + ");
            }
        }
    }

    if(show == 1){
        printf(")]");
        printf("\n\nEquation = %.4f [%.4f + 2(%.4f)]", (h / 2), (y[0] + y[n]), sum);
        printf("\n\nEquation = %.4f [%.4f + %.4f]", (h / 2), (y[0] + y[n]), 2 * sum);
        printf("\n\nEquation = %.4f (%.4f)", (h / 2), (y[0] + y[n]) * 2 * sum);
    }

    equation = (h / 2) * ((y[0] + y[n]) + (2 * sum));

    return equation;
}

