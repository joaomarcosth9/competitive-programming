#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

void _print() { }
template<typename T, typename... U>
void _print(T a, U... b) {
    if (sizeof...(b)) {
        cerr << a << ", ";
        _print(b...);
    } else cerr << a;
}

#ifdef BRUTE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x), cerr << "]" << endl
#else
#define debug(...)
#endif

// -------- END OF TEMPLATE --------

vector<int> pi(const string s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

const int N = 5005;
const int S = 2 * N;

struct SAM {
    array<int, 26> go[S];
    int lnk[S], len[S], endpos[S], id = 2, last = 1;
    
    void push(char ch) {
        int c = ch - 'a';
        int cur = id++;
        len[cur] = len[last] + 1;
        endpos[cur] = 1;
        int p = last;
        while (p > 0 && !go[p][c]) {
            go[p][c] = cur;
            p = lnk[p];
        }
        if (p == 0) {
            lnk[cur] = 1;
        } else {
            int s = go[p][c];
            if (len[s] == len[p] + 1) {
                lnk[cur] = s;
            } else {
                int clone = id++;
                len[clone] = len[p] + 1;
                lnk[clone] = lnk[s];
                go[clone] = go[s];
                while (p > 0 && go[p][c] == s) {
                    go[p][c] = clone;
                    p = lnk[p];
                }
                lnk[cur] = lnk[s] = clone;
            }
        }
        last = cur;
    }
    vector<int> adj[S];

    void dfs(int u) {
        for (int v : adj[u]) {
            dfs(v);
            endpos[u] += endpos[v];
        }
    }

    int curr = 1;

    void set_string(const string& s) {
        for (int i = 1; i < id; i++) {
            for (int j = 0; j < 26; j++) {
                go[i][j] = 0;
            }
            adj[i].clear();
        }

        memset(lnk, 0, sizeof lnk);
        memset(len, 0, sizeof len);
        memset(endpos, 0, sizeof endpos);

        id = 2, last = 1, curr = 1;

        for (char c : s) {
            push(c);
        }

        for (int i = 2; i < id; i++) {
            adj[lnk[i]].push_back(i);
        }

        dfs(1);
    }

    int advance(char ch) {
        int c = ch - 'a';
        if (go[curr][c] != 0) {
            return curr = go[curr][c];
        }
        return curr = 0;
    }

    int get_occurr() {
        return curr > 1 ? endpos[curr] : 0;
    }
} sa;

string s, t;
int mx[N][N];
int dp[N][N];

int n, m;

ll solve(string s, string t) {
    memset(mx, 0, sizeof mx);
    memset(dp, 0, sizeof dp);

    n = (int)s.size();
    m = (int)t.size();

    sa.set_string(t);

    for (int suf = 1; suf < n; suf++) {
        string suf_s = s.substr(suf);
        int sz = (int)suf_s.size();

        auto p = pi(suf_s + "#" + s);

        int first_s = sz + 1;

        for (int i = first_s, j = 0; i < (int)p.size(); i++, j++) {
            mx[j][suf] = p[i];
        }

        p = pi(suf_s);

        dp[suf][suf] = 1;
        for (int i = 1, j = suf + 1; j < n; i++, j++) {
            int prev = p[i] ? dp[suf][suf + p[i] - 1] : 0;
            dp[suf][j] = 1 + prev;
        }
    }

    ll res = 0;

    for (int i = 1; i < n; i++) {
        sa.curr = 1;
        for (int j = i; j < n - 1; j++) {
            sa.advance(s[j]);
            ll count = sa.get_occurr();
            int mx_len = mx[i - 1][j + 1];
            res += count * (dp[j + 1][j + mx_len]);
        }
    }

    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s >> t;

    ll res = 0;

    res += solve(s, t);

    res += solve(t, s);

    n = (int)s.size();
    sa.set_string(t);

    for (int i = 0; i < n; i++) {
        sa.curr = 1;
        for (int j = i; j < n; j++) {
            sa.advance(s[j]);
            ll count = sa.get_occurr();
            res += count;
        }
    }

    cout << res << endl;
}

