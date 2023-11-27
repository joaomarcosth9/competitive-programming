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

const int inf = 1e9;
const ii neutral = {-inf, inf};
#define comp(a, b) ii(max(a.first, b.first), min(a.second, b.second))

class SegmentTree {
  private:
    vector<ii> st;
    vector<int> lazy;
    int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
    void build(int p, int l, int r, vector<int>& A) {
        if (l == r) {
            st[p] = {A[l], A[l]};
            return;
        }
        int m = (l + r) / 2;
        build(left(p), l, m, A);
        build(right(p), m + 1, r, A);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    void push(int p, int l, int r) {
        st[p].first += lazy[p]; 		    //Caso RMQ
        st[p].second += lazy[p]; 		    //Caso RMQ
        if (l != r) {
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        lazy[p] = 0;
    }
    void update(int p, int l, int r, int a, int b, int k) {
        push(p, l, r);
        if (a > r || b < l) return;
        else if (l >= a && r <= b) {
            lazy[p] = k;
            push(p, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(left(p), l, m, a, b, k);
        update(right(p), m + 1, r, a, b, k);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    ii query(int p, int l, int r, int a, int b) {
        push(p, l, r);
        if (a > r || b < l) return neutral;
        if (l >= a && r <= b) return st[p];
        int m = (l + r) / 2;
        ii p1 = query(left(p), l, m, a, b);
        ii p2 = query(right(p), m + 1, r, a, b);
        return comp(p1, p2);
    }

  public:
    SegmentTree(vector<int> bg) {
        size = bg.size();
        st.assign(4 * size, neutral);
        lazy.assign(4 * size, 0);
        build(1, 0, size - 1, bg);
    }
    ii query(int a, int b) { return query(1, 0, size - 1, a, b); }
    void update(int a, int b, int k) { update(1, 0, size - 1, a, b, k); }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<ii> a(n);
    for (auto &[l, r] : a) cin >> l >> r;
    vector<int> compr;
    for (auto &[l, r] : a) compr.eb(l), compr.eb(r);
    sort(all(compr));
    compr.erase(unique(all(compr)), end(compr));
    map<int, int> conv;
    bool has0 = compr[0] > 1;
    bool hasm = compr.back() < m;
    conv[compr[0]] = has0;
    for (int i = 1; i < (int)compr.size(); i++) {
        conv[compr[i]] = conv[compr[i - 1]] + 1 + (compr[i] - compr[i - 1] > 1);
    }
    m = 0;
    for (auto &[l, r] : a) {
        l = conv[l];
        r = conv[r];
        m = max(m, r);
    }
    if (hasm) m++;
    vector<int> line(m + 1);
    for (auto &[l, r] : a) {
        line[l]++;
        if (r < m) line[r + 1]--;
    }
    for (int i = 1; i <= m; i++) line[i] += line[i - 1];
    SegmentTree seg(line);
    vector<vector<ii>> L(m + 1), R(m + 1);
    for (auto &[l, r] : a) {
        L[l].eb(l, r);
        R[r].eb(l, r);
    }
    debug(has0, hasm);
    debug(m, line);
    int best = 0;
    for (int i = 0; i <= m; i++) {
        for (auto [l, r] : L[i]) seg.update(l, r, -1);
        if (i > 0) for (auto [l, r] : R[i - 1]) seg.update(l, r, +1);
        auto [mx, mn] = seg.query(0, m);
        best = max(best, mx - mn);
    }
    cout << best << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
