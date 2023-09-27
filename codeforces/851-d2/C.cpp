#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<ll, ll> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif
#define int ll

void solve() {
    int n;
    cin >> n;
    if ((n & 1) == 0) {
        cout << "No" << endl;
        return;
    }
    ll summ = (4ll * n * n + 2ll * n) >> 1ll;
    ll a0 = ((summ / n) - n / 2);
    ll an = a0 + n - 1;
    db(a0, an);
    vector<ll> values(n);
    vector<ii> pairs;
    iota(values.begin(), values.end(), a0);
    pairs.emplace_back(1, 2 * n);
    ll mid = summ / n;
    ll nextl = mid - 1, nextr = an;
    ll l = 2, r = (n + 1) / 2 + 1;
    db(nextl, nextr);
    db(l, r);
    while ((int)pairs.size() < n) {
        pairs.emplace_back(l, nextl - l);
        pairs.emplace_back(r, nextr - r);
        nextl--, nextr--;
        l++, r++;
    }
    sort(pairs.begin(), pairs.end(),
         [](const ii &a, const ii &b) -> bool { return (a.first + a.second) < (b.first + b.second); });
    cout << "Yes" << endl;
    for (auto [a, b] : pairs) {
        cout << a << " " << b << endl;
    }
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
