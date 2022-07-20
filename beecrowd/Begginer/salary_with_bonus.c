#include <stdio.h>

char nome[30];
float salary;
float sales;

int main(){
    scanf("%s%f%f", nome, &salary, &sales);
    printf("TOTAL = R$ %.2f\n", salary+(sales*0.15));
    return 0;
}
