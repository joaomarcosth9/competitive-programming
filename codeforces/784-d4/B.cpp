#include <bits/stdc++.h>

using namespace std;

void solve(){
    int len;
    cin >> len;
    //unordered_map<int,int> A;
    vector<int> A(len+1);

    int r = -1;
    A[0][1];
    for (int i = 0; i < len; i++){
        int a; cin >> a;
        A[a]++;
        if (A[a] == 3){
            r = a;
        }
    }
    cout << r << '\n';
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
