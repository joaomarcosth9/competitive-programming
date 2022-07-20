#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

int arr[MAX];
int V[MAX];
int n, m, c;
int total = 0;

void verify(int crr){
    int prox = arr[crr];
    if(!prox){
        return;
    }
    if (V[prox]){
        cout << -1 << '\n';
        exit(0);
    }
    V[prox]++;
    total++;
    verify(prox);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        if (!arr[b]){
            arr[b] = a;
        }
    }
    verify(c);
    cout << total << '\n';
    return 0;
}
