#include<stdio.h>
# define f(x,y) x+(y*y)

int main()
{
    float x0,y0,n,h,xn,yn,k1,k2,k3,k4,k;
    
    printf("Enter the value of x0 and y0 =");
    scanf("%f%f",&x0,&y0);
    
    printf("Enter the value of xn =");
    scanf("%f",&xn);
    
    printf("Enter the value of h = ");
    scanf("%f",&h);
    
    n = (xn-x0)/h;
    
    
    printf("x \t\t y \t\t yn\n");
    for(int i = 0; i < n; i++)
    {
        k1 = h*(f(x0,y0));
        k2 = h*(f((x0+h/2),(y0+k1/2)));
        k3 = h*(f((x0+h/2),(y0+k2/2)));
        k4 = h*(f((x0+h),(y0+k3)));
        
        k = (k1+k4+2*(k2+k3))/6;
        
        yn = y0+k;
        
        printf("%0.4f \t\t %0.4f \t\t %0.4f\n", x0 , y0 , yn);
        y0 = yn;
        x0 = x0+h;
    }
    printf("\n Value of y at n = %0.4f is %0.4f", xn ,yn);
}