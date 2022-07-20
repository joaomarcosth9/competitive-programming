#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, s, d; cin >> a >> s >> d;
    int mod = s-d;
    int res = 0;
    while(1){
        if(a <= s){
            res++;
            break;
        } else {
            res++;
            a -= mod;
        }
    }
    cout << res << endl;
}

int main(){
    solve();
    return 0;
}
