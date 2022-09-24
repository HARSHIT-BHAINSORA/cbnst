#include<stdio.h>
#include<math.h>

float polyFunc(float x){
    return -cos(x)+3*x-1;
}

float diffFunc(float x){
    float ans = sin(x)+3;
    return ans; 
}


float hx(float x){
    float ans = (polyFunc(x)/diffFunc(x));
    return ans; 
}

int step = 1;
void calNewtonRaphson(float x , float allowErr){
    
    x = x - (hx(x));
    step++;
    printf("The value of x is = %f\n" , x);
    if(fabs(polyFunc(x)) <= allowErr){
        printf("The steps are = %d\n" , step);
        return;
    }
    
    calNewtonRaphson(x , allowErr);
    
}

int main(){
    float a , b , allowErr;
    
    printf("Enter guessed range  = ");
    scanf("%f%f" , &a, &b);
    
    if(polyFunc(a) * polyFunc(b))
    {
        float x;
        printf("Root are accepted !!!\n");
        printf("Enter the Allow error - ");
        scanf("%f" , &allowErr);
        printf("Enter any mid value between range = ");
        scanf("%f" , &x);
        printf("The value of x is = %f\n" , x);
        calNewtonRaphson(x, allowErr);
    }
    else{
        printf("oops invalid input !!!");
    }
    return ;
}

// float ans = log10(x) + 0.43429;
// x*log10(x) - 1.2; 