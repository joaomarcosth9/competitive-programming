#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

bool comp(int &a, int &b) { return abs(a) > abs(b); }

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &a : v) cin >> a;
    sort(begin(v), end(v));
    long long D = v.back() - v[0];
    vector<long long> pos, neg;
    for (auto &a : v) {
        if (a >= 0) {
            pos.push_back(a);
        } else {
            neg.push_back(a);
        }
    }
    if (pos.size()) sort(rbegin(pos), rend(pos));
    if (neg.size()) sort(begin(neg), end(neg));

    long long curr = 0;
    vector<long long> res;
    int i = 0, j = 0, sqpos = 0, sqneg = 0;

    for (;;) {
        if (i < (int)pos.size() && j < (int)neg.size()) {
            if (sqpos + pos[i] < D && abs(curr + pos[i]) <= abs(curr + neg[j])) {
                res.push_back(pos[i]);
                sqpos += pos[i];
                sqneg = 0;
                curr += pos[i++];
                if (sqpos >= D) {
                    cout << "NO" << endl;
                    return;
                }
            } else if (-sqneg - neg[j] < D) {
                sqneg += neg[j];
                sqpos = 0;
                res.push_back(neg[j]);
                curr += neg[j++];
                if (-sqneg >= D) {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        } else if (i < (int)pos.size()) {
            sqpos += pos[i];
            sqneg = 0;
            res.push_back(pos[i]);
            curr += pos[i++];
            if (sqpos >= D) {
                cout << "NO" << endl;
                return;
            }
        } else if (j < (int)neg.size()) {
            sqneg += neg[j];
            sqpos = 0;
            res.push_back(neg[j]);
            curr += neg[j++];
            if (-sqneg >= D) {
                cout << "NO" << endl;
                return;
            }
        } else {
            break;
        }
    }
    curr = 0;
    db(v, D, res);
    assert((int)res.size() == n);
    /* for(i = 0; i < n; i++){ */
    /*     curr += res[i]; */
    /*     if(abs(curr) > D){ */
    /*         cout << "NO" << endl; */
    /*         return; */
    /*     } */
    /* } */
    cout << "YES" << endl;
    for (int a : res) cout << a << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
