#include <stdio.h>
#include <math.h>

float polyFunc(float x){
     return (x*x*x) - (5*x) +1;
     
}


void calbisector(float a , float b ,float allowed_error)
{
    float x = (a + b) /2;
    
    printf("The Roots are %f  , %f  and the  values of x is %f  , %f\n" ,
    a , b, x , polyFunc(x) );
    
    if(fabs(polyFunc(x)) <= allowed_error){
        printf("Root will be %f" , x);
        return ;
    }
    
    if(polyFunc(a) * polyFunc(x) < 0){
        calbisector(a , x , allowed_error);
    }
    else if(polyFunc(x) * polyFunc(b) < 0){
        calbisector(x , b , allowed_error);
    }
}


int main() {
   
   float a , b , allowed_error = 0.0001 ;
   
   printf("Enter the any two roots of Equations ");
   scanf("%f %f" , &a , &b);
   
   if(polyFunc(a) * polyFunc(b) < 0){
       printf("Roots are accepted ... \n");
       
       calbisector(a , b , allowed_error );
   }
   else{
       printf("Invalid Roots...");
   }

    return 0;
}