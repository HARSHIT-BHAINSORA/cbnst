#include<stdio.h>

int main()
{
    int n;
    
    printf("Enter the value of number of observation = ");
    scanf("%d",&n);
    
    float x[n],y[n],xy[n],x2[n];
    float Sx=0,Sy=0,Sxy=0,Sx2=0;
    
    double byx;
    
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

    
    byx = ((n*Sxy) - (Sx*Sy)) / ((n*Sx2) - (Sx*Sx));
    Sx = Sx/n;
    Sy = Sy/n;
    float z = (byx*Sx)-Sy;

    printf("The Regression Line of y and x in \n");
    printf("y = (%0.4f)*x - (%0.4f)", byx ,z);
    return 0;
} 