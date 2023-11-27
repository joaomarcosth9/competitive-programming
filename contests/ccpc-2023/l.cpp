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

struct Node {
    int freq, L, R;
    ll val;
    Node() : freq(0), L(-1), R(-1), val(0) {}
};

struct SegmentTree {
    vector<Node> seg;
    vector<int> roots;
    int last, N;
    int le(int id) {
        if (seg[id].L == -1) {
            seg[id].L = seg.size();
            seg.emplace_back();
        }
        return seg[id].L;
    }
    int ri(int id) {
        if (seg[id].R == -1) {
            seg[id].R = seg.size();
            seg.emplace_back();
        }
        return seg[id].R;
    }
    void build(int id, int l, int r) {
        if (l == r) { seg[id] = Node(); return; }
        int mid = (l + r) / 2;
        build(le(id), l, mid);
        build(ri(id), mid + 1, r);
        seg[id].freq = seg[le(id)].freq + seg[ri(id)].freq;
        seg[id].val = seg[le(id)].val + seg[ri(id)].val;
    }
    void build (int n) {
        last = 0;
        N = n;
        seg.reserve(6 * N);
        seg.emplace_back();
        roots.emplace_back(0);
        build(0, 0, N - 1);
    }
    void update(int i, ll x, int id, int prev, int l, int r) {
        if (l == r) { seg[id].freq = 1, seg[id].val = x; return; }
        int mid = (l + r) / 2;
        if (i <= mid) {
            update(i, x, le(id), le(prev), l, mid);
            seg[id].R = seg[prev].R;
        } else {
            update(i, x, ri(id), ri(prev), mid + 1, r);
            seg[id].L = seg[prev].L;
        }
        seg[id].freq = seg[le(id)].freq + seg[ri(id)].freq;
        seg[id].val = seg[le(id)].val + seg[ri(id)].val;
    }
    void update(int i, ll x) {
        roots.emplace_back(seg.size());
        seg.emplace_back();
        update(i, x, seg.size() - 1, last, 0, N - 1);
        last = roots.back();
    }
    ll kth(int k, int id, int l, int r) {
        if (k <= 0) return 0;
        if (l == r) { return seg[id].val; }
        int mid = (l + r) / 2;
        int fl = seg[le(id)].freq;
        if (fl > k) return kth(k, le(id), l, mid);
        else return seg[le(id)].val + kth(k - fl, ri(id), mid + 1, r);
    }
    ll kth(int k, int x) { return kth(k, roots[x], 0, N - 1); }
} seg;

vector<ii> a;

ll calc(int x, int k) {
    return (ll)a[x].second + a[x].first + seg.kth(k - 1, x);
}

vector<ll> res;

void dnc(int l, int r, int L, int R) {
    if (l > r) return;
    int mid = (l + r) / 2;
    ll best = -1;
    int where = -1;
    for (int i = max(L, mid); i <= R; i++) {
        ll now = calc(i, mid + 1);
        if (where == -1 || now < best) {
            best = now;
            where = i;
        }
    }
    assert(where > -1);
    res[mid] = best;
    dnc(l, mid - 1, L, where);
    dnc(mid + 1, r, where, R);
}

void solve() {
    int n; cin >> n;
    a.resize(n);
    res.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<int> compr;
    sort(all(a), [&] (ii &l, ii &r) { return l.second < r.second; });
    for (int i = 0; i < n; i++) compr.eb(a[i].first);
    sort(all(compr));
    vector<int> id(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        id[i] = lower_bound(all(compr), a[i].first) - begin(compr) + freq[a[i].first];
        freq[a[i].first]++;
    }
    seg.build(n + 10);
    for (int i = 0; i < n; i++) {
        seg.update(id[i], a[i].first);
    }
    dnc(0, n - 1, 0, n - 1);
    for (int i = 0; i < n; i++) cout << res[i] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
