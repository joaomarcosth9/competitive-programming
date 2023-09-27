#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> vis(n);
    if(s == string(n, '?')){
        cout << string(n, '0') << '\n';
        return;
    }
    char fst = -1;
    int ifst = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != '?') {
            fst = s[i];
            ifst = i;
            break;
        }
    }
    for(int i = 0; i < ifst; i++){
        s[i] = fst;
    }
    char lst = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != '?') lst = s[i];
        else s[i] = lst;
    }
    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
