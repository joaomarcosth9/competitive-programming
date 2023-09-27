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
#define int ll
vector<int> u;
vector<int> pref;

int queryP(int l, int r) {
    l++; r++;
    assert(r < (int)pref.size());
    return pref[r] ^ pref[l - 1];
}

#include <cstdio>
const int neutral = 0; //comp(x, neutral) = x
#define comp(a, b) ((a)^(b))

class SegmentTree {
private:
	vector<int> st, lazy;
	int size;
#define left(p) (p << 1)
#define right(p) ((p << 1) + 1)
	void build(int p, int l, int r, vector<int>& A, string& s) {
		if (l == r) { st[p] = (s[l] == '1' ? A[l] : 0); return; }
		int m = (l + r) / 2;
		build(left(p), l, m, A, s);
		build(right(p), m+1, r, A, s);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	void push(int p, int l, int r) {
        if (lazy[p] & 1) {
            st[p] ^= queryP(l, r);
        }
		if (l != r) {
			lazy[right(p)] += lazy[p] & 1;
			lazy[left(p)] += lazy[p] & 1;
		}
		lazy[p] = 0;
	}
	void update(int p, int l, int r, int a, int b, int k) {
		push(p, l, r);
		if (a > r || b < l) return;
		else if (l >= a && r <= b) {
			lazy[p] ^= 1; push(p, l, r); return;
		}
		int m = (l + r) / 2;
		update(left(p), l, m, a, b, k);
		update(right(p), m+1, r, a, b, k);
		st[p] = comp(st[left(p)], st[right(p)]);
	}
	int query(int p, int l, int r, int a, int b) {
		push(p, l, r);
		if (a > r || b < l) return neutral;
		if (l >= a && r <= b) return st[p];
		int m = (l + r) / 2;
		int p1 = query(left(p), l, m, a, b);
		int p2 = query(right(p), m+1, r, a, b);
		return comp(p1, p2);
	}
public:
	SegmentTree(vector<int> a, string s) {
        size = a.size();
		st.assign(4 * size, neutral);
		lazy.assign(4 * size, 0);
		build(1, 0, size - 1, a, s);
	}
	int query(int a, int b) { return query(1, 0, size - 1, a, b); }
	void update(int a, int b, int k) { update(1, 0, size - 1, a, b, k); }
};

void solve() {
    int n; cin >> n;
    u.assign(n, 0);
    pref.assign(n + 1, 0);
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ u[i];
    }
    string s; cin >> s;

    SegmentTree seg(u, s);
    int q; cin >> q;
    for (int Q = 0; Q < q; Q++) {
        int t; cin >> t;
        if (t == 2) {
            int g; cin >> g;
            // XOR de todos que s[i] == g;
            if (g) cout << seg.query(0, n - 1) << " ";
            else cout << (seg.query(0, n - 1) ^ queryP(0, n - 1)) << " ";
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            // flipar s[l, ..., r];
            seg.update(l, r, 1);
        }
    }
    cout << endl;
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
