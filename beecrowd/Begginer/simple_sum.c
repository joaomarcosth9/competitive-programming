#include <stdio.h>

int A, B;

int soma(int A, int B){
    int resultado = A + B;
    return resultado; 
}

int main(){
    scanf("%d", &A);
    scanf("%d", &B);
    printf("SOMA = %d\n", soma(A,B));
    return 0;
}
