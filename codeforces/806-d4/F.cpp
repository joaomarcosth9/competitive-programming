#include <bits/stdc++.h>
using namespace std;

#define int long long

const int neutral = 0;
#define comp(a, b) ((a) + (b))

class FenwickTree {
  private:
    vector<int> ft;

  public:
    FenwickTree(int n) { ft.assign(n + 1, 0); }
    int rsq(int i) { // returns RSQ(1, i)
        int sum = neutral;
        for (; i; i -= (i & -i)) sum = comp(sum, ft[i]);
        return sum;
    }
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
    void update(int i, int v) {
        for (; i > 0 && i < (int)ft.size(); i += (i & -i)) ft[i] = comp(v, ft[i]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> idx;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (a < i) {
            v.push_back(a);
            idx.push_back(i);
        }
    }

    int nn = (int)v.size();

    FenwickTree ft(n + 1);

    int res = 0;
    for (int i = 0; i < nn; i++) {
        if (v[i] != 0) {
            res += ft.rsq(min(v[i] - 1, idx[i]));
        }
        ft.update(idx[i], 1);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    while (testcases--) solve();
    return 0;
}
