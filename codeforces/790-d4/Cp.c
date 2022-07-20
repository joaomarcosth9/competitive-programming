#include <stdio.h>
#include <stdlib.h>
 
int diff_words(int len, char arr1[], char arr2[]){
    int cost = 0;
    for (int i = 0; i < len; i++){
        if (arr1[i] < arr2[i]){
            cost += arr2[i] - arr1[i];
        } else if (arr1[i] > arr2[i]){
            cost += arr1[i] - arr2[i];
        }
    } 
    return cost;
}
 
char* v[500];
 
void solve(){
    int n;
    int len;
    scanf("%d %d", &n, &len);
    for (int i = 0; i < n; i++){
        char *arr = malloc(sizeof(char)*len);
        for (int j = 0; j < len; j++){
            scanf(" %c", &arr[j]);
        } 
        v[i] = arr;
    }
 
    int minor = diff_words(len, v[0], v[1]);
    int diff;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            diff = diff_words(len, v[i], v[j]);
            if (diff < minor){
                minor = diff;
            }
        }
    }
    printf("%d\n", minor);
}
 
int main(){
    int testcases;
    scanf("%d", &testcases);
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
