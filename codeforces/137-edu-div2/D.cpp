#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 1.1e6;

void solve() {
    int n;
    string ss;
    cin >> n >> ss;
    vector<int> s(n), res(n);
    for (int i = 0; i < n; i++) {
        s[i] = ss[i] == '1';
    }
    res = s;

    vector<pair<int, int>> ones;

    int last = -1, _seq = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 1 && !_seq) {
            last = i;
            _seq = 1;
        }
        if (s[i] == 0 && _seq) {
            ones.emplace_back(last, i - 1);
            _seq = 0;
        }
    }

    if (ones.empty()) {
        cout << 0 << endl;
        return;
    }

    vector<int> rang(ones[0].second - ones[0].first + 1);
    iota(rang.begin(), rang.end(), 1);

    vector<vector<int>> poss;

    for (int rn : rang) {
        vector<int> temp = res;
        for (auto &[l, r] : ones) {
            if (l == n) break;
            if (l < n) s[l] = 0;
            if (r < n - 1) s[r + 1] = 1;
            l++, r++;
        }
        for (int i = 0; i < n; i++) {
            temp[i] |= s[i];
        }
        poss.push_back(temp);
        db(temp);
        db(s);
    }

    vector<int> best;
    vector<bool> nop(poss.size());

    for (int j = 0; j < n; j++) {
        vector<int> o, z;
        db(j);
        for (int i = 0; i < (int)poss.size(); i++)
            if (!nop[i]) {
                db(i, poss[i]);
                if (poss[i][j] == 0)
                    z.push_back(i);
                else
                    o.push_back(i);
            }
        db(o, z);
        if (o.size() == 1) {
            db("fsdfdsf<F4><F4>SAS");
            best = poss[o[0]];
            break;
        } else if (j == n - 1) {
            db("ASAS");
            best = poss[(o.empty() ? z[0] : o[0])];
            break;
        }
        if (o.empty()) continue;
        for (int i : z) nop[i] = 1;
    }

    reverse(begin(best), end(best));
    while (best.back() == 0 && best.size() > 1) best.pop_back();
    reverse(begin(best), end(best));
    for (int i = 0; i < (int)best.size(); i++) {
        cout << best[i];
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
