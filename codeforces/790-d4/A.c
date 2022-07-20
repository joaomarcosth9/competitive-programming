#include <stdio.h>

void solve(){
    char arr[6];
    for (int i = 0; i < 6; i++){
        scanf(" %c", &arr[i]);
    }
    if ((arr[0]+arr[1]+arr[2]) == (arr[3]+arr[4]+arr[5])){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main (){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
