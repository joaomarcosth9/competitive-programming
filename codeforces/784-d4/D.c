#include <stdio.h>
#include <stdlib.h>

void solve(){
    int len;
    scanf("%d", &len);
    char *arr = malloc(sizeof(char)*len);

    for (int i = 0; i < len; i++){
        char j;
        scanf(" %c", &j);
        arr[i] = j;
    }

    int findR = 0, findB = 0, isonW = 1;

    for (int i = 0; i < len; i++){
        if (arr[i] == 'B'){
            findB = 1;
            isonW = 0;
        } else if (arr[i] == 'R'){
            findR = 1;
            isonW = 0;
        } else if (arr[i] == 'W'){
            if ((findR != 1 || findB != 1) && isonW == 0){
                printf("NO\n");
                return;
            } else {
                findR = 0;
                findB = 0;
                isonW = 1;
            }
        }
    }
    if ((findR == 1 && findB == 0) || (findR == 0 && findB == 1)){
        printf("NO\n");
        return;
    } else {
        printf("YES\n");
    }
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
