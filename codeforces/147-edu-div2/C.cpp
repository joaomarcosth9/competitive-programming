#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> idx(26);

    for(int i = 0; i < 26; i++)
        idx[i].emplace_back(-1);

    for(int i = 0; i < n; i++){
        int index = s[i] - 'a';
        idx[index].emplace_back(i);
    }

    for(int i = 0; i < 26; i++)
        idx[i].emplace_back(n);

    int res = INT_MAX;
    for(int i = 0; i < 26; i++){

        if(idx[i].size() == 2) continue;

        db(char(i+'a'));
        int curr = 0;

        int nn = idx[i].size();
        for(int ii = 1; ii < nn; ii++){
            int sz = idx[i][ii] - idx[i][ii-1] - 1;
            db(sz);
            if(sz > 0) curr = max(curr, __lg(sz) + 1);
        }

        db(res, curr);
        res = min(res, curr);
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
