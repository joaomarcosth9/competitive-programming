#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
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

vector<int> a;
int n;
vector<ii> res;

void op(int l, int r) {
    res.eb(l + 1, r + 1);
    int X = 0;
    for (int i = l; i <= r; i++) X ^= a[i];
    for (int i = l; i <= r; i++) a[i] = X;
}

void printres() {
    assert(ssize(res) <= 8);
    cout << ssize(res) << endl;
    for (auto [l, r] : res) cout << l << " " << r << endl;
    res.clear();
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
        op(0, n - 1);
        op(0, n - 1);
    } else {
        op(1, n - 1);
        op(1, n - 1);
        op(0, 1);
        op(0, 1);
    }
    assert(a == vector<int> (n, 0));
    printres();
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
}
