#include<stdio.h>

// y = a + bx;


int main()
{
    int n;
    
    printf("Enter the value of number of observation = ");
    scanf("%d",&n);
    
    float x[n],y[n],xy[n],x2[n];
    float Sx=0,Sy=0,Sxy=0,Sx2=0;
    
    double a , b;
    
    printf("Enter the values of x =");
    for(int i=0; i<n; i++)
    {
        scanf("%f",&x[i]);
        Sx += x[i];
    }
    
    printf("Enter the value of y = ");
    for(int i=0; i<n; i++)
    {
        scanf("%f",&y[i]);
        Sy += y[i];
    }
    
    for(int i=0; i<n; i++)
    {
        xy[i] = x[i]*y[i];
        Sxy += xy[i]; 
        x2[i] = x[i]*x[i];
        Sx2 += x2[i]; 
    }
    
    a = (((Sxy*Sx) - (Sy*Sx2)) / ((Sx*Sx) - (n*Sx2)));
    b = (((Sy - (n*a)))/Sx);
    
    printf("The equation of the Straight Line is \n");
    printf("And the form of equation is y = a + b*x is\n");
    printf("y = %0.4f + (%0.4f)*X", a, b);
    return 0;
}