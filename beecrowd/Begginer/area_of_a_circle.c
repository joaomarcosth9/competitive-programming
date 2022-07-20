#include <stdio.h>
#include <math.h>

double pi = 3.14159;

double circle_area(double r){
    double area = pi * pow(r, 2);
    return area;
}

int main(){
    double r;
    scanf("%lf", &r);
    printf("A=%.4lf\n", circle_area(r));
    return 0;
}
