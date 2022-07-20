#include <stdio.h>
#include <stdlib.h>

void list(){
    int len;
    scanf("%d", &len);
    int *arr = malloc(len*sizeof(int)+1e4);

    for (int i=0; i < len; i++){
        int j;
        scanf("%d", &j);
        arr[i] = j;
    }

    int *app = malloc(len*sizeof(int)+1e4);

    for (int i = 0; i < len; i++){
        app[i]=0;
    }

    for (int i = 0; i < len; i++){
        app[arr[i]-1] += 1;
        if (app[arr[i]-1] == 3){
             printf("%d\n", arr[i]);
             return;
        }
    }
    printf("-1\n");
    return;
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        list();
    }
    return 0;
}
