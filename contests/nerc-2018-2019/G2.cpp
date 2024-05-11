#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

string s, t;
const int N = 260;
int n;
int dp[N][N];
int type[N][N];
pair<int, int> par;

int solve(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return dp[l][r] = 1;
    if (l == r) return dp[l][r] = 0;
    
    dp[l][r] = 0;

    if (s[l] != s[r]) {
        if (solve(l + 1, r - 1)) {
            dp[l][r] = 1;
            type[l][r] = 2;
        }
    }

    for (int i = l + 1; i < r - 1; i++) {
        if (solve(l, i) and solve(i + 1, r)) {
            dp[l][r] = 1;
            type[l][r] = 1;
        }
    }

    return dp[l][r];
}

string ans;

void get_ans(int l, int r) {
    if (l > r) return;
    if (type[l][r] == 2) {
        ans.push_back('[');
        get_ans(l + 1, r - 1);
        ans.push_back(']');
    } else {
        for (int i = l; i < r; i++) {
            if (solve(l, i) and solve(i + 1, r)) {
                get_ans(l, i);
                get_ans(i + 1, r);
                break;
            }
        }
    }
}

void solve() {
    memset(dp, -1, sizeof dp);

    cin >> s;
    n = int(s.size());

    bool dr = (n & 1);

    for (int i = 0; i + 1 < n; i += 2) {
        string now = s.substr(i, 2);
        if (now != ">>" && now != "<<") dr = 1;
    }

    if (dr) {
        cout << "Keine Loesung" << endl;
        return;
    }

    t = "$";

    for (int i = 0; i + 1 < n; i += 2) {
        string now = s.substr(i, 2);
        if (now == ">>") {
            t.push_back('2');
        } else if (now == "<<") {
            t.push_back('1');
        } else assert(false);
    }

    s = t;
    n = int(s.size() - 1);

    if (solve(1, n) == 1) {
        get_ans(1, n);
        cout << ans << endl;
    } else {
        cout << "Keine Loesung" << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
