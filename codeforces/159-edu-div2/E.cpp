#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct trie {
    vector<map<int, int>> to;
    vector<int> end, pref;
    int sigma;
    char norm;
    trie(int sigma_ = 26, char norm_ = 'a') : sigma(sigma_), norm(norm_) {
        to = {map<int, int>()};
        end = {0}, pref = {0};
    }
    void insert(string s) {
        int x = 0;
        for (auto c : s) {
            int &nxt = to[x][c - norm];
            if (!nxt) {
                nxt = to.size();
                to.push_back(map<int, int>());
                end.push_back(0), pref.push_back(0);
            }
            x = nxt, pref[x]++;
        }
        end[x]++, pref[0]++;
    }
    void erase(string s) {
        int x = 0;
        for (char c : s) {
            int &nxt = to[x][c - norm];
            x = nxt, pref[x]--;
            if (!pref[x]) nxt = 0;
        }
        end[x]--, pref[0]--;
    }
    ll find(string s) {
        int x = 0;
        ll cnt = 0;
        for (auto c : s) {
            x = to[x][c - norm];
            if (!x) break;
            cnt += pref[x];
        }
        return cnt;
    }
    int count_pref(string s) { return pref[find(s)]; }
};

void solve() {
    int n; cin >> n;
    vector<string> b(n);
    for (auto& x : b) cin >> x;

    ll res = 0;
    trie t;

    for (int i = 0; i < n; i++) {
        auto s = b[i];
        reverse(all(s));
        t.insert(s);
    }

    ll sz = 0;
    for (int i = 0; i < n; i++) {
        sz += b[i].size();
    }
    for (int i = 0; i < n; i++) {
        res += sz;
    }

    for (int i = 0; i < n; i++) {
        res -= t.find(b[i]);
    }

    cout << res * 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
