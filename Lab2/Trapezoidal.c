#include<stdio.h>

float valueAt(float x)
{
    return 1/(1+(x*x));
}


int main(){
    
    int n;
    float a , b , sum = 0 , h;
    
    printf("Enter the number of Intervals = ");
    scanf("%d",&n);
    
    printf("Enter the value of a and b = ");
    scanf("%f%f",&a,&b);

    h = (b-a)/n;
   
    
    // formula = h/2[ y0 + yn + 2(y1 + y2 + y3 ... yn-1)];
    
    sum = valueAt(a) + valueAt(b);
    
    for(float i = a+h ; i < b ; i +=h)
    {
        sum += 2*valueAt(i);
    }
    
    sum = (h*sum)/2;
    
    printf("The value of Intergal is = %f" , sum);
    return 0;
}