#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s; cin >> s;
    map<char,int> f;
    for(auto u : s) f[u]++;
    if(f['O'] != 1 || f['X'] != 2){
        cout << "?" << endl;
        return;
    }
    for(int i = 0; i < 2; i++){
        if(s[i] == s[i + 1]){
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "*" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
