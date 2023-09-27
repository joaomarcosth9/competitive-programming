#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

vector<string> pots(60);

long long make(string &n, string &pot) {
    int ret = 0, ip = 0, in = 0;

    for (in = 0; in < (int)n.size(); in++) {
        if (ip < (int)pot.size() && n[in] == pot[ip]) {
            ip++;
        } else
            ret++;
    }

    db(n, pot, ret, ip, in);

    ret += (int)pot.size() - ip;

    db(ret);

    return ret;
}

void solve() {
    string n;
    cin >> n;
    long long k = LLONG_MAX;
    for (string &p : pots) k = min(k, make(n, p));
    cout << k << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long current = 1;
    pots[0] = to_string(current);
    for (int i = 1; i < 60; i++) {
        pots[i] = to_string(current <<= 1);
    }
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
