#include "newtons_interpolation.h"
#include <stdio.h> 

int main()
{
    int n = 4;
    float value, sum, y[10][10];
    float x[] = { 5, 6, 9, 11 };
 
    y[0][0] = 12;
    y[1][0] = 13;
    y[2][0] = 14;
    y[3][0] = 16;
 
    dividedDiffTable(x, y, n);
 
    value = 7;
    
    float solution = interpolate(value, x, y, n);

    printf("value of fxn at x = %f is : %f\n", value, solution);
    
    return 0;
}