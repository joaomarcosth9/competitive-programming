#include <stdio.h>
#include <stdlib.h>

void solve(){
    int n;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int minor = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] <= minor){
            minor = arr[i];
        }
    }
    int eated = 0;
    for (int i = 0; i < n; i++){
        while (arr[i]-minor){
            arr[i]--;
            eated++;
        }
    }
    printf("%d\n", eated);

}

int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
