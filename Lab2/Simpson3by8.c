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
  
    //                                odd position terms       even position terms
    // formula = h/3[ (y0 + yn) + 4(y1 + y3 + y5 +...yn-1) +2(y2 + y4 + y6 ... yn-2)];
    
    sum = valueAt(a) + valueAt(b);
    int pos = 1;
    
    for(float i = a+h ; i < b ; i +=h)
    {
        if(pos % 2 == 0)
            sum += 2*valueAt(i);
        else
            sum += 4*valueAt(i);
        pos++;    
    }
    
    sum = (h*sum)/3;
    
    printf("The value of Intergal is = %f" , sum);
    return 0;
}