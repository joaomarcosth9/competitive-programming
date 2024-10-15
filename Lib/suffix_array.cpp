#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

namespace sa {
    const int N = 4e5 + 5;
    int id[N], id2[N], sa[N];
    int count[N], vis[N];
    int all[N], all2[N];
    void build(string s) {
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            id[i] = (int)(s[i] - 'a') + 1;
        }
        for (int sz = 2; sz < 2 * n; sz *= 2) {
            int aux = sz / 2;
            for (int i = 0; i <= max(26, n); i++) {
                count[i] = 0;
                vis[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                int idr = i + aux < n ? id[i + aux] : 0;
                all[i] = i;
                count[idr]++;
            }
            for (int i = 1; i <= max(26, n); i++) {
                count[i] += count[i - 1];
            }
            for (int i = 0; i < n; i++) {
                int j = all[i];
                int idr = j + aux < n ? id[j + aux] : 0;
                int idx = (idr ? count[idr - 1] : 0) + vis[idr];
                all2[idx] = all[i];
                vis[idr]++;
            }
            for (int i = 0; i <= max(26, n); i++) {
                count[i] = 0;
                vis[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                all[i] = all2[i];
                int j = all[i];
                count[id[j]]++;
            }
            for (int i = 1; i <= max(26, n); i++) {
                count[i] += count[i - 1];
            }
            for (int i = 0; i < n; i++) {
                int j = all[i];
                int idx = (id[j] ? count[id[j] - 1] : 0) + vis[id[j]];
                all2[idx] = all[i];
                vis[id[j]]++;
            }
            int it = 0;
            pair<int, int> last = {-1, -1};
            for (int i = 0; i < n; i++) {
                int j = all2[i];
                pair<int, int> now = {id[j], j + aux < n ? id[j + aux] : 0};
                if (now != last) {
                    it++;
                    last = now;
                }
                id2[j] = it;
            }
            for (int i = 0; i < n; i++) {
                id[i] = id2[i];
            }
        }
        sa[0] = n;
        for (int i = 0; i < n; i++) {
            sa[id[i]] = i;
        }
    }
}

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    sa::build(s);
    for (int i = 0; i <= n; i++) {
        cout << sa::sa[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
