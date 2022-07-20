#include <stdio.h>

double A, B, C;

double media(double A, double B, double C){
    double media = (A*2+B*3+C*5)/(2+3+5);
    return media;
}

int main(){
    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);
    printf("MEDIA = %.1f\n", media(A, B, C));
    return 0;
}
