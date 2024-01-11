#pragma GCC optimize("O3")
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

const int maxn = 1e6 + 5;
int A[maxn], B[2 * maxn], res[maxn], n;
vector<int> st[4 * maxn];

#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)

void build(int p, int l, int r) { // O(n)
    st[p].assign(r - l + 1, 0);
    if (l == r) {
        st[p][0] = B[l];
        return;
    }
    int pl = left(p), pr = right(p), m = (l + r) / 2;
    build(pl, l, m);
    build(pr, m + 1, r);
    merge(st[pl].begin(), st[pl].end(), st[pr].begin(), st[pr].end(), st[p].begin());
}

int query(int p, int l, int r, int i, int j, int a, int b) {
    if (j < l || i > r) return 0;
    if (i <= l && j >= r)
        return upper_bound(st[p].begin(), st[p].end(), b) - lower_bound(st[p].begin(), st[p].end(), a);
    int m = (l + r) / 2;
    return query(left(p), l, m, i, j, a, b) + query(2 * p + 1, m + 1, r, i, j, a, b);
}

int query(int i, int j, int a, int b) { return query(1, 0, n - 1, i, j, a, b); }

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) A[i]--;

    for (int i = 0; i < n; i++) {
        if (A[i] < i) {
            B[i] = A[i] + n;
            B[i + n] = A[i];
        } else {
            B[i] = A[i];
            B[i + n] = A[i] + n;
        }
    }

    build(1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        /* int l = i + 1, r = A[i] - 1 + n * (A[i] < i); */
        /* res[A[i]] = A[i] - i - query(l, r, l, r); */
        /* if (A[i] < i) res[A[i]] += n; */
        if (A[i] < i) {

        } else {

        }
    }

    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
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
