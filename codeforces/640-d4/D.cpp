#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int l = 0, r = n - 1;
    int num = 0;
    int curr = 1;
    int la = 0, lb = 0;
    int aa = 0, bb = 0;
    while (l <= r) {
        int c = 0;
        if (curr) {
            while (l <= r && c <= lb) {
                c += a[l++];
            }
            aa += c;
            la = c;
            num++;
        } else {
            while (l <= r && c <= la) {
                c += a[r--];
            }
            bb += c;
            lb = c;
            num++;
        }
        curr ^= 1;
    }
    cout << num << " " << aa << " " << bb << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}