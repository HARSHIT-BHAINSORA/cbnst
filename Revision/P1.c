#include<stdio.h>
#include<math.h>

int a;


void NewtonForward(float arr[][a+1])
{
    int n = a;
    int fact =1;
    float u , newU , y , x;
    
    printf("Enter the value of x which you want find y = ");
    scanf("%f" , &x);


    u = (x - arr[0][0])/(arr[1][0] - arr[0][0]);
    newU = u;
    y = arr[0][1];
    
    for(int i = 2 ; i < n+1 ; i++)
    {
        y = y + (newU * arr[0][i])/fact;
        fact = fact*i;
        newU = newU * (u - (i-1));
    }
    
    printf("The value of x and y is = %0.2f and %0.2f\n" , x , y);

    
}



void NewtonBackward(float arr[][a+1])
{
    int n = a;
    int fact =1;
    float u , newU , y , x;
    int j =2;
    
    printf("Enter the value of x which you want find y = ");
    scanf("%f" , &x);

    
    u = (x - arr[n-1][0])/(arr[1][0] - arr[0][0]);
    newU = u;
    y = arr[n-1][1];
    
    for(int i = n-2 ; i >= 0 ; i--)
    {
        y = y + (newU * arr[i][j])/fact;
        fact = fact*j;
        newU = newU * (u + (j-1));
        j++;
    }
    
    printf("The value of x and y is = %0.2f and %0.2f\n" , x , y);

    
}



int main(){

    int n;
  
    printf("Enter the value of n = ");
    scanf("%d" , &n);
    
    a = n;
 
    float arr[n][n+1];

    printf("Enter the value's of X = ");
    for(int i = 0 ; i < n ; i++)
        scanf("%f" , &arr[i][0]);

    printf("Enter the value's of Y = ");
    for(int i = 0 ; i < n ; i++)    
        scanf("%f" , &arr[i][1]);

   
    
    for(int j = 2 ; j < n+1 ; j++)
    {
        for(int i = 0 ; i <= n-j ; i++)
        {
            arr[i][j] = arr[i+1][j-1] - arr[i][j-1];
        }
    }

   
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <= n-i ; j++)
        {
            printf("%0.2f " , arr[i][j]);
        }
        printf("\n");
    }
    
    
    int ch;
    
    do{
        
        printf("1. Newton Forward \n 2. Newton Backward \n 3. Exit\n");
        printf("Enter the choice = ");
        scanf("%d" , &ch);
        
        switch(ch)
        {
            case 1: NewtonForward(arr);
                    break;
            case 2: NewtonBackward(arr);
                    break;
            case 3: break;
            
            default:printf("Invalid chioce");
                    break;
        }
        
    }while(ch != 3);
    return 0;
}