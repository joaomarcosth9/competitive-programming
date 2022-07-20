#include <stdio.h>

int getdiv(int rating){
    int division;
    if (rating <= 1399){
        division = 4;
    } else if (rating <= 1599){
        division = 3;
    } else if (rating <= 1899){
        division = 2;
    } else {
        division = 1;
    }
    return division;
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        int rat;
        scanf("%d", &rat);
        int div = getdiv(rat);
        printf("Division %d\n", div);
    }
    return 0;
}
