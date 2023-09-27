#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int n;
string s;

void solve(){
    cin >> s;
    n = s.size();
    int q; cin >> q;
    vector<priority_queue<tuple<int,int,int,char>>> upd(n);
    int t = 0;
    while(q--){
        char c;
        int i, a, k;
        cin >> i >> a >> k >> c;
        i--;
        upd[i].emplace(t++, a, k, c);
    }
    for(int i = 0; i < n; i++){
        if(upd[i].empty()) { cout << s[i]; continue; }
        auto& [_t, a, k, c] = upd[i].top();
        cout << c;
        if(i + a < n && k > 0) upd[i+a].emplace(_t, a, k-1, c);
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
