#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+50;

int len, op;
char arr[MAX];

int sum(char *s, int size){
    int soma = 0;
    for(int i = 0; i < size-1; i++){
        if(s[i] == '0' && s[i+1] == '0'){
            continue;
        } else if(s[i] == '0' && s[i+1] == '1'){
            soma+=1;
        } else if(s[i] == '1' && s[i+1] == '0'){
            soma+=10;
        } else if(s[i] == '1' && s[i+1] == '1'){
            soma+=11;
        }
    }
    return soma;
}

void solve(){
    cin >> len >> op;
    for (int i = 0; i < len; i++){
        cin >> arr[i];
    }
    int opo = op;
    int p = 0;
    int t = len-1;
    while(t >= 0 && arr[t] != '1' && op){
        op--;
        t--;
    }
    if (t >= 0 && arr[t] == '1' && t != len-1){
        arr[len-1] = '1';
        arr[t] = '0';
        while(p < len-1 && arr[p] != '1' && op){
            op--;
            p++;
        }
        if (p < len-1 && arr[p] == '1' && p != 0){
            arr[0] = '1';
            arr[p] = '0';
        }
    } else {
        op = opo;
        while(p < len-1 && arr[p] != '1' && op){
            op--;
            p++;
        }
        if (p < len-1 && arr[p] == '1' && p != 0){
            arr[0] = '1';
            arr[p] = '0';
        }
    }
    cout << sum(arr, len) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
