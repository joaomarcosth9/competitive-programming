#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve() {
    vector<string> m = {"Mm", "Ee", "Oo", "Ww"};
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] != 'M' && s[0] != 'm') {
        cout << "NO" << endl;
        return;
    }
    int id = 0;
    string se = m[id];
    for (int i = 1; i < n; i++) {
        int outra = 1;
        for (char c : se)
            if (c == s[i]) outra = 0;
        se = m[id += outra];
        int ok = 0;
        for (char c : se)
            if (c == s[i]) ok = 1;
        if (!ok) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
