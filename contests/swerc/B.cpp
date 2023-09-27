#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const int maxn = 4e2;
int arr[maxn];

void solve() {
    int n, h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ii> diffs;
    for (int i = 1; i < n; i++) {
        diffs.emplace_back(i - 1, i);
    }
    sort(diffs.begin(), diffs.end(),
         [&](ii &a, ii &b) { return abs(arr[a.first] - arr[a.second]) < abs(arr[b.first] - arr[b.second]); });
    ll res = 0;
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
