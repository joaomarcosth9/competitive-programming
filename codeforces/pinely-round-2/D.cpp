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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (string &i : mat) cin >> i;
    bool db = 1;
    for (int i = 0; i < n; i++) {
        int hm = 0;
        for (int j = 0; j < m; j++) {
            hm += mat[i][j] == 'U' || mat[i][j] == 'D';
        }
        db &= (hm % 2) == 0;
    }
    for (int i = 0; i < m; i++) {
        int hm = 0;
        for (int j = 0; j < n; j++) {
            hm += mat[j][i] == 'L' || mat[j][i] == 'R';
        }
        db &= (hm % 2) == 0;
    }
    if (!db) {
        cout << -1 << endl;
        return;
    }
    auto change = [&] (int &color) { color ^= 1 ^ 2; };
    vector paint(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        int color = 1;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'U') {
                paint[i][j] = color;
                change(color);
            }
        }
        color = 2;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'D') {
                paint[i][j] = color;
                change(color);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int color = 1;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 'L') {
                paint[j][i] = color;
                change(color);
            }
        }
        color = 2;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == 'R') {
                paint[j][i] = color;
                change(color);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paint[i][j]) cout << (paint[i][j] == 1 ? "B" : "W");
            else cout << ".";
        }
        cout << endl;
    }
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
