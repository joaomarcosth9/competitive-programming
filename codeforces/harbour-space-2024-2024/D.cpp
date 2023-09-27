#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n;
    cin >> n;
    vector mat(n, vector<int>(n));
    vector tag(n, vector<int>(n));
    vector tagL(n, vector<int>(n));
    vector tagR(n, vector<int>(n));

    auto valid = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            mat[i][j] = c - '0';
        }
    }

    auto pushD = [&](int i, int j) {
        mat[i][j] ^= 1;
        if (valid(i + 1, j)) {
            tag[i + 1][j] ^= 1;
        }
    };
    auto pushL = [&](int i, int j) {
        if (valid(i + 1, j - 1)) {
            tagL[i + 1][j - 1] ^= 1;
            tag[i + 1][j - 1] ^= 1;
        }
    };
    auto pushR = [&](int i, int j) {
        if (valid(i + 1, j + 1)) {
            tagR[i + 1][j + 1] ^= 1;
            tag[i + 1][j + 1] ^= 1;
        }
    };

    int op = 0;
    for (int i = 0; i < n; i++)
        if (mat[0][i]) {
            tag[0][i] = tagL[0][i] = tagR[0][i] = 1;
            pushD(0, i);
            pushL(0, i);
            pushR(0, i);
            op += 1;
        }
    debug(mat[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tag[i][j]) pushD(i, j);
            if (tagL[i][j]) pushL(i, j);
            if (tagR[i][j]) pushR(i, j);
            debug(i, j, mat[i], op);
            if (mat[i][j]) {
                op += 1;
                tag[i][j] = tagL[i][j] = tagR[i][j] = 1;
                if (tag[i][j]) pushD(i, j);
                if (tagL[i][j]) pushL(i, j);
                if (tagR[i][j]) pushR(i, j);
            }
        }
    }
    cout << op << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
