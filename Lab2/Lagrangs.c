#include<stdio.h>

int main(){
    int n ;
    printf("Enter the number of terms = ");
    scanf("%d", &n);

    float X[n] , Y[n] , sum = 0 , x;

    printf("Enter the values of X = ");
    for(int i = 0 ; i < n ; i++)
        scanf("%f" , &X[i]);

    printf("Enter the values of Y = ");
    for(int i = 0 ; i < n ; i++)
        scanf("%f" , &Y[i]);

    printf("Enter the values of x which you want find y = ");
    scanf("%f" , &x);

    for(int i = 0 ; i < n ; i++)
    {
        float product = 1;
        for(int j = 0 ; j < n ; j++)
        {
            if(i != j)
            {
                product = product * ((x - X[j])/(X[i] - X[j])); 
            }
        } 
        sum = sum + (product * Y[i]);
    }
    printf("\n Value of x is %0.2f and the sum is = %0.2f" , x , sum);
    return 0;
}