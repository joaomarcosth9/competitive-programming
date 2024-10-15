#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#ifndef ONLINE_JUDGE
const int N = 4e2 + 5;
#else
const int N = 2e5 + 5;
#endif

const int S = N * 2;

array<int, 27> go[S];
int id = 2, last = 1, lnk[S], len[S], endpos[S], idx[S], where[S];

void push(int idx_, char ch) {
    int c = (int)(ch - 'a');
    int cur = id++;
    len[cur] = len[last] + 1;
    endpos[cur] = 1;
    where[idx_] = cur;
    idx[cur] = idx_;
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
            idx[clone] = idx[s];
            lnk[clone] = lnk[s];
            go[clone] = go[s];
            while (p > 0 && go[p][c] == s) {
                go[p][c] = clone;
                p = lnk[p];
            }
            lnk[s] = lnk[cur] = clone;
        }
    }
    last = cur;
}

int n, m;
string s, t;
string sep = string(1, 'z' + 1);
int ans[2 * N];

void solve() {
    cin >> n >> m;

    cin >> s;
    s += s;
    n *= 2;

    while (m--) {
        string temp; cin >> temp;
        t += temp + sep;
    }

    m = (int)t.size();

    for (int i = 0; i < m; i++) {
        push(i, t[i]);
    }

    int node = 1, clen = 0;

    vector<pair<int, int>> its;

    for (int i = 0; i < n; i++) {
        // pra cada i, qual maior sufixo de s[0...i] que eh substring de t?
        int c = (int)(s[i] - 'a');
        while (node > 0 && !go[node][c]) {
            node = lnk[node];
            clen = len[node];
        }
        if (node == 0) {
            node = 1;
            clen = 0;
        } else {
            clen++;
            node = go[node][c];
            // pro i, tenho [i - clen + 1, i] como substring de t
            its.push_back({i - clen + 1, i});
        }
    }

    sort(its.begin(), its.end());

    multiset<pair<int, int>> current;
    multiset<pair<int, int>> in;

    int it = 0;

    for (int l = 0; l + n / 2 - 1 < n; l++) {
        // pra todo intervalo com intersecao com l, qual tem maior r valido
        while (it < (int)its.size() && its[it].first == l) {
            current.insert({its[it].second, its[it].first});
            it++;
        }
        int r = l + n / 2 - 1;
        auto ub = current.upper_bound({r, INT_MAX});
        if (current.size() && ub != current.begin()) {
            ub--;
            int mx = ub->first;
            if (mx >= l) {
                ans[l] = max(ans[l], mx - l + 1);
            }
        }
    }

    current.clear();

    sort(its.begin(), its.end(), [&] (pair<int, int> A, pair<int, int> B) {
        return A.second > B.second;
    });

    it = 0;

    for (int r = n - 1; r - n / 2 + 1 >= 0; r--) {
        // pra todo intervalo com intersecao com r, qual tem menor l valido
        while (it < (int)its.size() && its[it].second == r) {
            current.insert(its[it]);
            it++;
        }
        int l = r - n / 2 + 1;
        auto lb = current.lower_bound({l, INT_MIN});
        if (current.size() && lb != current.end()) {
            int mn = lb->first;
            if (mn <= r) {
                ans[l] = max(ans[l], r - mn + 1);
            }
        }
    }

    multiset<tuple<int, int, int>> current2;

    its2 = its;

    sort(its.begin(), its.end(), [&] (pair<int, int> A, pair<int, int> B) {
        return A.second < B.second;
    });

    it = 0;

    for (int l = 0; l + n / 2 - 1 < n; l++) {
        // agora, pra cada [l, l + n / 2 - 1], pegar o maior que cabe dentro desse intervalo

        int r = l + n / 2 - 1;

        // insiro quem tem final <= r
        while (it < (int)its.size() && its[it].second <= r) {
            if (its[it].first >= l) {
                current2.insert({its[it].second - its[it].first + 1, its[it].first, its[it].second});
                in.insert({its[it].first, its[it].second});
            }
            it++;
        }

        // retiro quem tem comeco < l
        while (in.size() && in.begin()->first < l) {
            auto [fst, snd] = *in.begin();
            in.erase(in.begin());
            auto to_erase = current2.find({snd - fst + 1, fst, snd});
            current2.erase(to_erase);
        }

        debug(l, r, current2, ans[l]);

        if (current2.size()) ans[l] = max(ans[l], get<0>(*current2.rbegin()));
    }


    // for (int i = 0; i < n - 1; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    cout << *min_element(ans, ans + n / 2) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(idx, -1, sizeof idx);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
