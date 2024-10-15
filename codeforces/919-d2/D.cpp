#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

string to_string(__int128 o) {
    string r;
    while (o > 0) {
        r += char(o % 10 + '0');
        o /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}

ostream& operator<<(ostream& os, __int128 o) {
    return os << (ll)o;
}

void solve() {
    int n, q; cin >> n >> q;

    vector<pair<int, int>> a(n);
    for (auto &[u, v] : a) {
        cin >> u >> v;
    }

    __int128 len = 0;
    int last = 0;

    vector<int> back(n);

    for (int i = 0; i < n; i++) {
        auto &[x, y] = a[i];
        if (len > (__int128)1e18)
            continue;
        if (x == 1) {
            back[i] = 1;
            if (i > 0) back[i] += back[i - 1];
            len++;
        } else {
            len *= (y + 1);
            back[i] = 0;
        }
        last++;
    }

    auto f = [&] (ll i) {
        int it = last - 1;
        auto clen = len;
        //cout << "i: " << i << endl;
        //cout << "len: " << len << endl;
        while (it >= 0) {
            //cout << "it: " << it << " - clen: " << clen << endl;
            while (it > 0 && a[it].first == 2) {
                //cout << clen << " {" << a[it].first << " " << a[it].second << "}" << endl;
                clen /= (a[it].second + 1);
                i %= clen;
                it--;
            }
            //cout << "it: " << it << " - back[it]: " << back[it] << " - clen: " << clen << endl;
            if (i >= clen - back[it]){
                assert(a[it - (clen - i - 1)].first == 1);
                return a[it - (clen - i - 1)].second;
            } 
            clen -= back[it];
            it -= back[it];
        }
        return -1LL;
    };

    while (q--) {
        ll x; cin >> x;
        x--;
        cout << f(x) << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
