#include <stdio.h>

int number;
int hours;
float salary;

int main(){
    scanf("%d%d%f", &number, &hours, &salary);
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", hours*salary);
    return 0;
}
