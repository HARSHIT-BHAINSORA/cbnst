#include <stdio.h>
#include <math.h>

float polyFunc(float x)
{
    return 2 * x - (log(x) / log(10)) - 7;
}

float diffFunc(float x)
{
    return 1 / (2 * x * log(10));
}

float xForm(float x)
{
    return ((log(x) / log(10)) + 7) / 2;
}
int steps = 0;
void calIterative(float x, float allowErr)
{
    x = xForm(x);
    steps++;
    printf("%d  iteration and the value of x is - %f\n", steps, x);
    if (fabs(polyFunc(x)) <= allowErr)
        return;
    calIterative(x, allowErr);
}

int main()
{

    float x, allowErr;

    printf("Enter the guessed value - ");
    scanf("%f", &x);

    if (diffFunc(x) < 1)
    {

        printf("Input is satisfying the condition\n");
        printf("Enter the allowed Error - ");
        scanf("%f", &allowErr);
        calIterative(x, allowErr);
    }
    else
        printf("Oops invalid input!!!");
    return 0;
}