#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

int arr[MAX];
int app[MAX];
int vis[MAX];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        app[i] = 0;
    } 
    for(int i = 0; i < n; i++){
        vis[i] = 0;
    } 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        app[arr[i]]++;
    } 
    int ntirar = 0;
    for(int i = 0; i < n; i++){
        if(app[arr[i]]>1 && vis[arr[i]] == 0){
            ntirar+=app[arr[i]]-1;
            vis[arr[i]]++;
        }
    } 
    if(ntirar%2==1) ntirar++;
    cout << n - ntirar << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
