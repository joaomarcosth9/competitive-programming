#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
int arr[MAX];

void solve(){
    int len;
    scanf("%d", &len);

    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    int pairity_even_index = arr[0]%2;
    int pairity_odd_index = arr[1]%2;

    for (int i=2; i < len; i++){
        if(i%2){
            if (arr[i]%2 != pairity_odd_index){
                printf("NO\n");
                return;
            }
        } else {
            if (arr[i]%2 != pairity_even_index){
                printf("NO\n");
                return;
            }
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
