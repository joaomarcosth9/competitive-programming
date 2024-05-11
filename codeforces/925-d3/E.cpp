#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    priority_queue<int> pq;
    ll osize = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int it = int(s.size()) - 1;
        int cnt = 0;
        while (s[it] == '0') it--, cnt++;
        while (it >= 0) s[it] = '1', it--;
        a[i] = s;
        osize += int(s.size()) - cnt;
        pq.push(cnt);
    }
    int play = 1;
    while (pq.size()) {
        auto now = pq.top();
        pq.pop();
        if (!play) {
            osize += now;
        }
        play ^= 1;
    }
    return (osize <= m);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Anna" : "Sasha") << endl;
    }
}
