#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#define bin(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> freq(n, vector<int>(26));
    vector<int> mask(n);
    vector<vector<int>> zeros(n);
    vector<vector<int>> fmask(26, vector<int>(n + 1));
    /* vector<unordered_map<int,int>> fmask(26); */
    for (int i = 0; i < n; i++) {
        for (char c : v[i]) {
            freq[i][c - 'a']++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (freq[i][j] == 0) zeros[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        int &maskk = mask[i];
        for (int j = 0; j < (int)v[i].size(); j++) {
            char &c = v[i][j];
            int &fq = freq[i][c - 'a'];
            /* db(i, v[i], c, fq); */
            if (fq > 0 && fq & 1) {
                maskk |= (1 << (c - 'a'));
            }
        }
    }
    vector<int> id(1 << 26);
    for (int i = 0; i < n; i++) {
        if (id[mask[i]] == 0) id[mask[i]] = i + 1;
    }
    ll res = 0;
    for (int j = 0; j < n; j++) {
        db(j + 1, v[j], zeros[j]);
    }
    for (int j = 0; j < n; j++) {
        if (zeros[j].empty()) continue;
        auto &_msk = mask[j];
        for (auto idx : zeros[j]) {
            fmask[idx][id[_msk]]++;
            /* fmask[idx][_msk]++; */
        }
        db("-----------------------");
        db(j + 1, bin(_msk));
        db("-----------------------");
        for (auto idx : zeros[j]) {
            auto msk = _msk;
            msk ^= (1 << 26) - 1;
            db("XOR", bin(msk));
            msk &= ~(1 << idx);
            db("APAGANDO", (char)(idx + 'a'), bin(msk));
            if (fmask[idx][id[msk]]) {
                /* if(fmask[idx][msk]){ */
                db(bin(msk));
                res += fmask[idx][id[msk]];
                /* res += fmask[idx][msk]; */
                db(res, fmask[idx][id[msk]]);
            }
        }
    }
    cout << res << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
