#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    int res = (n-3)%8;
    if (res == 3){
        cout << 1 << endl;
    } else if (res == 4){
        cout << 2 << endl;
    } else if (res == 5){
        cout << 3 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
