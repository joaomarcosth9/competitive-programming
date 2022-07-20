#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool diffbyone(char arr1[2], char arr2[2]){
    bool p1 = (arr1[0] == arr2[0]);
    bool p2 = (arr1[1] == arr2[1]);

    if ((p1 && !(p2))){
        return 1;
    } else if (p2 && !(p1)){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    int num;
    scanf("%d", &num);
    char **v = malloc(sizeof(char*)*num);

    for (int i = 0; i < num; i++){
        char *arr = malloc(sizeof(char)*2);
        //char arr[2];

        scanf(" %c%c", &arr[0], &arr[1]);

        v[i] = arr;
    }

    long long count = 0;

    for (int i = 0; i < num; i++){
        for (int j = i+1; j < num; j++){
            if (diffbyone(v[i], v[j])){
                count++;
            }
        }
    }
    printf("%lld\n", count);
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
