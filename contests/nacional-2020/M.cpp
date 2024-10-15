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

const int S = 4e5 + 5;

array<int, 26> go[S];
int lnk[S], len[S], endpos[S], id = 2, last = 1;

struct Update {
    vector<pair<int&, int>> changes;
    ll old_sum;
    int nodes_to_delete = -1;
    void change(int &x, int new_val) {
        changes.push_back({x, x});
        x = new_val;
    }
};

vector<Update> upd;

ll sum = 0;
int leaf[S];

void push(char ch) {
    Update now;
    int c = ch - 'A';
    int cur = id;
    now.old_sum = sum;
    now.change(id, id + 1);
    now.change(len[cur], len[last] + 1);
    now.change(endpos[cur], 1);
    now.change(leaf[cur], 1);
    int p = last;
    while (p > 0 && !go[p][c]) {
        now.change(go[p][c], cur);
        p = lnk[p];
    }
    if (p == 0) {
        now.change(lnk[cur], 1);
        // sum += len[cur] - len[lnk[cur]];
    } else {
        int s = go[p][c];
        if (len[s] == len[p] + 1) {
            now.change(lnk[cur], s);
            if (leaf[s]) {
                sum += len[s] - len[lnk[s]];
                now.change(leaf[s], 0);
            }
            // sum += len[cur] - len[lnk[cur]];
        } else {
            int clone = id;
            now.change(id, id + 1);
            now.change(len[clone], len[p] + 1);
            now.change(lnk[clone], lnk[s]);
            sum += len[clone] - len[lnk[clone]];
            go[clone] = go[s];
            now.nodes_to_delete = clone;
            while (p > 0 && go[p][c] == s) {
                now.change(go[p][c], clone);
                p = lnk[p];
            }
            if (!leaf[s]) sum -= len[s] - len[lnk[s]];
            now.change(lnk[cur], clone);
            now.change(lnk[s], clone);
            // sum += len[cur] - len[lnk[cur]];
            if (!leaf[s]) sum += len[s] - len[lnk[s]];
        }
    }
    now.change(last, cur);

    upd.push_back(now);
}

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
        push(s[i]);
    }
    cout << sum << endl;
    string t;
    cin >> t;
    for (char c : t) {
        if (c == '-') {
            auto &now = upd.back();
            if (now.nodes_to_delete != -1) {
                go[now.nodes_to_delete] = go[0];
            }
            while (now.changes.size()) {
                auto &[x, val] = now.changes.back();
                x = val;
                now.changes.pop_back();
            }
            sum = now.old_sum;
            upd.pop_back();
        } else {
            push(c);
        }
        cout << sum << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}

