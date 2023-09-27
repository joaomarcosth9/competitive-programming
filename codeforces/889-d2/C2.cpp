#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int OP;
vector<pair<int,int>> ret;
vector<ll> a;

void add(int i, int j) {
    a[i] += a[j];
    OP++;
    ret.emplace_back(i + 1, j + 1);
}

void solve_pos() {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        while(a[i] < a[i - 1]) {
            add(i, i - 1);
        }
    }
}

void solve_neg() {
    int n = a.size();
    for (int i = n - 2; i >= 0; i--) {
        while(a[i] > a[i + 1]) {
            add(i, i + 1);
        }
    }
}

void solve() {
    int n; cin >> n;
    ret.clear();
    OP = 0;
    a = vector<ll> (n);
    for (ll &i : a) cin >> i;
    bool db = 1, all_neg = 1, all_pos = 1;
    all_neg &= a[0] <= 0;
    all_pos &= a[0] >= 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) db = 0;
        all_neg &= a[i] <= 0;
        all_pos &= a[i] >= 0;
    }
    if (db) {
        cout << 0 << endl;
        return;
    }

    if (all_pos) {
        solve_pos();
        cout << OP << endl;
        for (auto [i, j] : ret) cout << i << " " << j << endl;
        return;
    }
    if (all_neg) {
        solve_neg();
        cout << OP << endl;
        for (auto [i, j] : ret) cout << i << " " << j << endl;
        return;
    }

    int mx = *max_element(begin(a), end(a));
    int mn = *min_element(begin(a), end(a));
    int cnt = 0;
    for (int i = 0; i < n; i++){ 
        cnt += a[i] > 0;
    }
    int neg = n - cnt;

    if (abs(mx) > abs(mn)) {
        if (cnt >= 8) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == mx) idx = i;
            }
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) add(i, idx);
            }
            solve_pos();
        } else {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == mn) idx = i;
            }
            while (a[idx] > -20) add(idx, idx);
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) add(i, idx);
            }
            solve_neg();
        }
    } else {
        if (neg >= 8) {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == mn) idx = i;
            }
            for (int i = 0; i < n; i++) {
                if (a[i] > 0) add(i, idx);
            }
            solve_neg();
        } else {
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == mx) idx = i;
            }
            while (a[idx] < 20) add(idx, idx);
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) add(i, idx);
            }
            solve_pos();
        }
    }

    cout << OP << endl;
    for (auto [i, j] : ret) cout << i << " " << j << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}

