#include <bits/stdc++.h>
using namespace std;
#define int long long
int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

const int neutral = 0, MOD = 1e9 + 7, P = 101;

int binexp(int b, int e) {
    int r = 1;
    while (e > 0) {
        if (e & 1) {
            r = (r * b) % MOD;
        }
        b = (b * b) % MOD;
        e >>= 1;
    }
    return r;
}

class FenwickTree {
  private:
    vector<int> ft;

  public:
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    int rsq(int i) { // returns RSQ(1, i)
        int sum = neutral;
        for (; i; i -= (i & -i)) {
            sum = (sum + ft[i] + MOD) % MOD;
        }
        return sum % MOD;
    }
    int rsq(int i, int j) { return (rsq(j) - rsq(i - 1) + MOD) % MOD; }
    void update(int i, int v) {
        for (; i > 0 && i < (int)ft.size(); i += (i & -i)) {
            ft[i] = (ft[i] + v + MOD) % MOD;
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    FenwickTree ft1(n), ft2(n);
    auto rev = [&](int i) { return n - i + 1; };
    for (int i = 0; i < n; i++) {
        int v1 = (1 + (s[i] - 'a')) * binexp(P, i + 1);
        int v2 = (1 + (s[i] - 'a')) * binexp(P, rev(i + 1));
        ft1.update(i + 1, v1 % MOD);
        ft2.update(i + 1, v2 % MOD);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            // update
            int i;
            char c;
            cin >> i >> c;
            s[i - 1] = c;

            ft1.update(i, -ft1.rsq(i, i));
            int v1 = (1 + (c - 'a')) * binexp(P, i);
            ft1.update(i, v1 % MOD);

            ft2.update(i, -ft2.rsq(i, i));
            int v2 = (1 + (c - 'a')) * binexp(P, rev(i));
            ft2.update(i, v2 % MOD);

        } else if (t == 2) {
            // query
            int l, r;
            cin >> l >> r;
            int b1 = binexp(P, l - 1);
            int q1 = (ft1.rsq(l, r) * binexp(b1, MOD - 2)) % MOD;
            int b2 = binexp(P, rev(r + 1));
            int q2 = (ft2.rsq(l, r) * binexp(b2, MOD - 2)) % MOD;
            cout << (q1 == q2 ? "Adnan Wins" : "ARCNCD!") << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
