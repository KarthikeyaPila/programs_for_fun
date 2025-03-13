#include <stdio.h>

float multiply(int i, float* x, float val){
    float out = 1;
    for (int j = 0; j < i; j++) {
        out *= (val - x[j]);
    }
    return out;
}

void dividedDiffTable(float* x, float** y, int n){
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j][i - 1] - y[j + 1] [i - 1])/(x[j] - x[i + j]);
        }
    }
}

float interpolate(float val, float* x, float** y, int n){
    float sum = y[0][0];
 
    for (int i = 1; i < n; i++) {
      sum = sum + (multiply(i, x, val) * y[0][i]);
    }
    return sum;
}
