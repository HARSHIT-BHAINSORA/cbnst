#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// step 1 : arrange the equation in the diagonal domination form 

# define f1(x,y,z) (17-y+2*z)/20
# define f2(x,y,z) (-18-3*x+z)/20
# define f3(x,y,z) (25-2*x+3*y)/20

int step = 1;
void calFunction(float x , float y , float z , float error){
    float x1 = f1(x , y , z);
    float y1 = f2(x1 , y , z);
    float z1 = f3(x1, y1 , z);

    printf("%d\t\t%0.4f\t%0.4f\t%0.4f\n" , step , x1, y1 , z1);

    float e1 = fabs(x - x1);
    float e2 = fabs(y - y1);
    float e3 = fabs(z - z1);

    step++;

    if(e1 <= error && e2 <= error && e3 <= error ){
        printf("The value of x =  %0.4f , y = %0.4f and z = %0.4f", x1 , y1 , z1);
        return;
    }

    calFunction(x1, y1, z1 , error);    
}



int main(){

    float error , x = 0 , y = 0 , z = 0;

    printf("Enter the allowed error = ");
    scanf("%f" , &error);

    printf("iteration\tx\ty\tz\n");
    calFunction(x, y , z , error);
}
