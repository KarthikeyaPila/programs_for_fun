#include <stdio.h> 
#include <math.h> 

double function_val(double a, double b, double c, double d, double e, double x1){
    return a*pow(x1, 4) + b*pow(x1, 3) + c*pow(x1, 2) + d*pow(x1, 1) + e;
}

double bisection(double a, double b, double c, double d, double e, double x1, double x2){

    double fxn1 = function_val(a, b, c, d, e, x1);
    double fxn2 = function_val(a, b, c, d, e, x2);

    double x3;
    double fxn3; 

    while((x2-x1) >= 0.001){
        x3 = (x1+x2)/2;
        fxn3 = function_val(a, b, c, d, e, x3);

        if (fabs(fxn3) < 0.001){
            return x3;
        }
        if (fxn1*fxn3<0) {
            x2 = x3;
            fxn2 = fxn3;
        } else {
            x1 = x3;
            fxn1 = fxn3;
        }
    }

    return x2;
}

int main(){
    double a, b, c, d, e, x1, x2;

    printf("enter the coefficient from variables from the left: ");
        scanf("%lf", &a);
        scanf("%lf", &b);
        scanf("%lf", &c);
        scanf("%lf", &d);
        scanf("%lf", &e);
    
    printf("Enter the interval [x1, x2] to find a root: ");
    scanf("%lf %lf", &x1, &x2);

    double root = bisection(a, b, c, d, e, x1, x2);

    printf("the root is: %lf\n", root);

    return 0;
}