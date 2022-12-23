#include<stdio.h>
#include<math.h>

float valueAt(float x)
{
    return 1/(1+(x*x));
}


void Trapezoidal(float a , float b  , float h)
{
    float sum = 0;
    sum = valueAt(a) + valueAt(b);
    
    for(float i = a+h ; i < b ; i +=h)
    {
        sum += 2*valueAt(i);
    }
    sum = (sum*h)/2;
    
    printf("The value of Intergal is = %f\n" , sum);
}



void Simpson1by3(float a , float b  , float h)
{
    float sum = 0;
    sum = valueAt(a) + valueAt(b);
    printf("%f",sum);
    int pos = 1;
    for(float i = a+h ; i < b ; i +=h)
    {
        if(pos%2 == 0)
            sum += 2*valueAt(i);
        else
            sum += 4*valueAt(i);
        pos++;
    }
    sum = (sum*h)/3;
    
    printf("The value of Intergal is = %f\n" , sum);
}

void Simpson3by8(float a , float b , float h)
{
    float sum = 0;
    sum = valueAt(a) + valueAt(b);
    int pos = 1;
    
    for(float i = a+h ; i < b ; i +=h)
    {
        if(pos%3 == 0)
            sum += 2*valueAt(i);
        else
            sum += 3*valueAt(i);
        pos++;    
    }
    sum = (sum*h*3)/8;
    
    printf("The value of Intergal is = %f\n" , sum);
}



int main(){

   int n;
   float a , b , h;
   
   
   printf("Enter the value of n =");
   scanf("%d",&n);
   
   printf("Enter the value of a and b = ");
   scanf("%f%f",&a,&b);
   
    h = (b-a)/n;

    int ch;
    
    do{
        
        printf("1.Trapezoidal \n 2. Simpson1/3 \n 3.Simpson3/8 \n 4.Exit\n");
        printf("Enter the choice = ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: Trapezoidal(a , b, h);
                    break;
            case 2: Simpson1by3(a , b, h);
                    break;
            case 3: Simpson3by8(a , b, h);
                    break;        
            case 4: break;
            default:printf("Invalid chioce");
                    break;
        }
        
    }while(ch != 4);
    return 0;
}