#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int MAX = 1e7 + 10;
 
void solve() {
    int n, x; cin >> n >> x;
    int u = n / 2, v = (n + 1) / 2;
    vector<int> a(u), b(v);
    for(int i = 0; i < u; i++){
        cin >> a[i];
    }
    for(int i = 0; i < v; i++){
        cin >> b[i];
    }

    vector<int> freq;
    vector<pair<int, int>> freq2;

    for(int i = 0; i < (1 << u); i++){
        long long c = 0;
        for(int j = 0; j < u; j++){
            if(i & (1 << j)){
                c += a[j];
            }
        }
        if(c > x) continue;
        freq.emplace_back(c);
    }

    if (freq.empty()) {
        cout << 0 << endl;
        return;
    }

    sort(begin(freq), end(freq));

    freq2.emplace_back(freq[0], 1);

    for (int i = 1; i < (int)freq.size(); i++) {
        if (freq[i] == freq2.back().first) {
            freq2.back().second++;
        } else {
            freq2.emplace_back(freq[i], 1);
        }
    }

    long long res = 0;

    for(int i = 0; i < (1 << v); i++){
        long long c = 0;
        for(int j = 0; j < v; j++){
            if(i & (1 << j)){
                c += b[j];
            }
        }
        if (c > x) continue;
        int t = x - c;
        auto [k, f] = *lower_bound(begin(freq2), end(freq2), make_pair(t, 0));
        if (k == t) {
            res += f;
        }
    }

    cout << res << '\n';

}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
