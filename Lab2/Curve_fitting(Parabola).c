#include<stdio.h>

// y = a + bx + cx^2;



void GuassElimination(float arr[3][4] , float x[])
{
    
    
    int n=3;
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
    

    x[n-1] = arr[n-1][n] / arr[n-1][n-1];

    for(int i = n-2 ; i >=0 ; i--)
    {
        float sum = 0;
        for(int j = i+1 ; j < n ; j++)
        {
            sum += arr[i][j]*x[j];
        }
        x[i] = (arr[i][n]-sum)/arr[i][i];
    }
    
     
}


int main()
{
    int n;
    
    printf("Enter the value of number of observation = ");
    scanf("%d",&n);
    
    float x[n],y[n],xy[n],x2[n],x3[n],x4[n],x2y[n];
    float Sx=0,Sy=0,Sxy=0,Sx2=0,Sx3=0,Sx4=0,Sx2y=0;
    
    printf("Enter the values of x = ");
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
        
        x3[i] = x2[i]*x[i];
        Sx3 += x3[i];
        
        x4[i] = x3[i]*x[i];
        Sx4 += x4[i];
        
        x2y[i]= x2[i]*y[i];
        Sx2y += x2y[i];
    }
    
    printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",Sx,Sy,Sxy,Sx2,Sx3,Sx4,Sx2y);
    
    
    // an + bSx + cSx2 = Sy
   // aSx + bSx2 + cSx3 = Sxy 
   // aSx2 + bSx3 + cSx4 = Sx2y   
    
    float mat[3][4];
    
    mat[0][0] = n;
    mat[0][1] = Sx;
    mat[0][2] = Sx2;
    mat[0][3] = Sy;
    mat[1][0] = Sx;
    mat[1][1] = Sx2;
    mat[1][2] = Sx3;
    mat[1][3] = Sxy;
    mat[2][0] = Sx2;
    mat[2][1] = Sx3;
    mat[2][2] = Sx4;
    mat[2][3] = Sx2y;
    
    
    float v[3];    
   GuassElimination(mat , v);
  
    printf("The equation of the Parabola Cruve is \n");
    printf("And the form of equation is y = a + b*x +c^2 is\n");
    printf("y = %0.4f + (%0.4f)*X + (%0.4f)*X^2", v[0], v[1],v[2]);
    return 0;
}