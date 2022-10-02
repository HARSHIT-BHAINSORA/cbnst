#include<stdio.h>
#include<math.h>

int main(){

    
    int n;
    printf("Enter the order of the matrix = ");
    scanf("%d" , &n);
    
    // Step 1 : Take input from the user

    float arr[n][n+1];

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j < n+1 ; j++){
            scanf("%f" , &arr[i][j]);
        }
    }


    // step 2 : convert the given agrumnented matrix into upper triangular matrix

    // here i is for row and j is for columns 
    // in the kth part we basically trying r? - multi*r1 and update it

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n+1 ; j++)
        {
            if(j < i){
                float ratio = arr[i][j] / arr[j][j];

                for(int k = 0 ; k < n+1 ; k++)
                {
                    arr[i][k] = arr[i][k] - ratio*(arr[j][k]);
                } 
            }
        }
    }

    printf("After Converting to upper triangular matrix \n");

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n+1 ; j++)
        {
            printf("%0.2f ",arr[i][j]);
        }
        printf("\n");
    }

    // Now its time to Apply Backward subsitution 

    // if zero based indexing 

    // n = 3 
    // i = (0 , 1 , 2)  & j (0 , 1, 2 ,3);

    // eq be like 
    
    // x00 a + x01 b + x02 c = x 03
    // 0     + x11 b + x12 c = x 13
    // 0     +  0    + x22 c = x 23

    // so value of c = x 23 / x22;
    // b = x13 - x12 c / x11;
    // a = x03 - (x01 b + x02 c) / x00; 

    float x[n];
    // last value means c is directly put 
    x[n-1] = arr[n-1][n] / arr[n-1][n-1];

    // start solving eq from second last row
    for(int i = n-2 ; i >=0 ; i--)
    {
        float sum = 0;
        for(int j = i+1 ; j < n ; j++)
        {
            sum += arr[i][j]*x[j];
        }
        x[i] = (arr[i][n]-sum)/arr[i][i];
    }

    printf("The Values are = \n");

    for(int i = 0 ; i < n ; i ++)
    {
        printf("The value of x%d =  %0.2f\n" , i, x[i]); 
    }
    return 0;
}