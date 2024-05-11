#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<int> pi(string &s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < int(s.size()); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

vector<int> matching(string &s, string &t) { // s = texto, t = padrao
    vector<int> p = pi(t), match;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != t[j]) {
            j = p[j - 1];
        }
        if (s[i] == t[j]) {
            j++;
        }
        if (j == (int)t.size()) {
            match.push_back(i - j + 1);
            j = p[j - 1];
        }
    }
    return match;
}

const int N = 21;
int n;
string s[N];
bool valid[N];
int ps[N][N];
int dp[1 << N][N], sz[N];

void solve() {
    memset(dp, 0x3f, sizeof dp);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        valid[i] = 1;
    }
    vector<string> valids;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            auto match = matching(s[i], s[j]);
            debug(i, j, match);
            if (match.size() > 1) {
                valid[j] = 0;
            } else if ((int)match.size() == 1) {
                if (match[0] == 0) valid[max(i, j)] = 0;
                else valid[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (valid[i]) valids.push_back(s[i]);
    }
    for (int i = 0; i < (int)valids.size(); i++) {
        s[i] = valids[i];
        sz[i] = (int)s[i].size();
    }
    n = (int)valids.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto now = s[j] + "#" + s[i];
            ps[i][j] = pi(now).back();
        }
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = (int)s[i].size();
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            for (int k = 0; k < n; k++) if (!(i & (1 << k))) {
                dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + (int)s[k].size() - ps[j][k]);
            }
        }
    }

    cout << *min_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n) << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
