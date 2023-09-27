#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    vector<string> s(2);
    cin >> s[0] >> s[1];
    int n = s[0].size();
    int diff = 0;
    for(int i = 0; i < n; i++){
        diff += s[0][i] != s[1][i];
    }
    int t, Q; cin >> t >> Q;
    queue<pair<int,int>> q;
    int time = 0;
    while(Q--){
        debug(s);
        debug(diff);
        int T; cin >> T;
        if(q.size() && time == q.front().first){
            auto [_, pos] = q.front();
            q.pop();
            debug("Desbloqueando", pos);
            if(s[0][pos] != s[1][pos]) diff++;
        }
        if (T == 1) {
            //block
            int pos; cin >> pos; pos--;
            debug("Bloqueando", pos);
            if(s[0][pos] != s[1][pos]) diff--;
            q.emplace(time + t, pos);
        } else if(T == 2) {
            int s1, p1, s2, p2;
            cin >> s1 >> p1 >> s2 >> p2; p1--, p2--, s1--, s2--;
            debug(s1, p1, s2, p2);
            int old = 0;
            old += s[s1][p1] != s[!s1][p1];
            old += s[s2][p2] != s[!s2][p2];
            diff -= old;
            debug(old);
            swap(s[s1][p1], s[s2][p2]);
            int now = 0;
            now += s[s1][p1] != s[!s1][p1];
            now += s[s2][p2] != s[!s2][p2];
            diff += now;
            debug(now);
            debug(diff);
        } else {
            // sao iguais ?
            cout << (diff == 0 ? "YES" : "NO") << '\n';
        }
        time++;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
