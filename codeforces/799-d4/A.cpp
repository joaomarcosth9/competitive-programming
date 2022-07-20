#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    int res = 0;
    if (b>a){
        res++;
    }
    if (c>a){
        res++;
    }
    if (d>a){
        res++;
    }
    cout << res << '\n';
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
