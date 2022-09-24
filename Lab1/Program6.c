#include <stdio.h>
#include <math.h>

float polyFunc(float x)
{
    return (x * x) * exp(-x / 2) - 1;
}

int steps = 0;
void calSecant(float a, float b, float errAllow)
{

    float x = b - (((b - a) / (polyFunc(b) - polyFunc(a))) * polyFunc(b));

    printf("The Roots are %f  , %f  and the  values of x is %f  , %f\n", a, b, x, polyFunc(x));
    steps++;
    if (fabs(polyFunc(x)) <= errAllow)
    {
        printf("The root of given Equation is -  %f \n", x);
        printf("Steps are - %d", steps);
        return;
    }
    calSecant(x, a, errAllow);
}

int main()
{

    float x1, x2, a, b, allowErr;

    printf("Enter given range  = ");
    scanf("%f%f", &x1, &x2);

    printf("Enter the Allow error - ");
    scanf("%f", &allowErr);
    printf("Enter any value of a and b in between the range = ");
    scanf("%f%f", &a, &b);
    calSecant(a, b, allowErr);
}