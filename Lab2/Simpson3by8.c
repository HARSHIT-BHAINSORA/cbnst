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
  
    //                                                  multiple of 3 terms
    // formula = 3h/8[ (y0 + yn) + 3(y1 + y2 + y4 + y5) +2(y3 + y6 ...)];
    
    sum = valueAt(a) + valueAt(b);
    int pos = 1;
    
    for(float i = a+h ; i < b ; i +=h)
    {
        if(pos % 3 == 0)
            sum += 2*valueAt(i);
        else
            sum += 3*valueAt(i);
        pos++;    
    }
    
    sum = (h*sum*3)/8;
    
    printf("The value of Intergal is = %f" , sum);
    return 0;
}