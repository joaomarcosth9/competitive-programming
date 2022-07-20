#include <stdio.h>

int A, B, C, D;

int difference(int A, int B, int C, int D){
    int diff = (A*B)-(C*D);
    return diff;
}

int main(){
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    printf("DIFERENCA = %d\n", difference(A, B, C, D));
    return 0;
}
