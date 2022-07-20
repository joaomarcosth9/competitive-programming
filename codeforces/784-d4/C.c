#include <stdio.h>
#include <stdlib.h>

int pair(int num){
    if(num%2==0){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    int len;
    scanf("%d", &len);
    int *arr = malloc(len*sizeof(int));

    for (int i = 0; i < len; i++){
        int j;
        scanf("%d", &j);
        arr[i] = j;
    }

    int pairity_even_index = pair(arr[0]);
    int pairity_odd_index = pair(arr[1]);

    for (int i=2; i < len; i+=2){
        if (pair(arr[i]) != pairity_even_index){
            printf("NO\n");
            return;
        }
    }

    for (int i=3; i < len; i+=2){
        if (pair(arr[i]) != pairity_odd_index){
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
