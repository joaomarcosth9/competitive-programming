#include <stdio.h>

double A, B;

double media(double A, double B){
    double media = (A*3.5+B*7.5)/11.0;
    return media;
}

int main(){
    scanf("%lf", &A);
    scanf("%lf", &B);
    printf("MÉDIA JOÃO NÚMERO= %.5lf\n", media(A, B));
    return 0;
}
