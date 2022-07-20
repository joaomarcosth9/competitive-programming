#include <stdio.h>

int A, B;

int prod(int A, int B){
    int resultado = A * B;
    return resultado; 
}

int main(){
    scanf("%d", &A);
    scanf("%d", &B);
    printf("PROD = %d\n", prod(A,B));
    return 0;
}
