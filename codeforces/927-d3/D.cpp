#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

vector<pair<string, string>> ans;
bool db;
int conv[300], back[4];

void solve(int n, char T, vector<pair<int, char>> p1, vector<pair<int, char>> p2) {
    set<int> trumps1, trumps2;
    vector<set<int>> deck1(4), deck2(4);

    bool now = 1;

    vector<pair<string, string>> plays;

    for (int i = 0; i < n / 2; i++) {
        auto [rnk, suit] = p1[i];
        if (suit == T) {
            trumps1.insert(rnk);
        } else {
            deck1[conv[int(suit)]].insert(rnk);
        }
    }

    for (int i = 0; i < n / 2; i++) {
        auto [rnk, suit] = p2[i];
        if (suit == T) {
            trumps2.insert(rnk);
        } else {
            deck2[conv[int(suit)]].insert(rnk);
        }
    }

    debug(trumps2, trumps1);

    int to_kill = int(trumps1.size());
    for (auto u : trumps1) {
        auto beat = trumps2.upper_bound(u);
        if (beat == trumps2.end()) {
            now = 0; break;
        }
        string c1 = to_string(u) + string(1, T);
        string c2 = to_string(*beat) + string(1, T);
        plays.push_back({c1, c2});
        trumps2.erase(beat);
        to_kill--;
    }

    if (to_kill) {
        now = 0;
    }

    if (now) for (int i = 0; i < 4; i++) {
        for (auto u : deck1[i]) {
            auto beat = deck2[i].upper_bound(u);
            if (beat == deck2[i].end()) {
                if (trumps2.size()) {
                    string c1 = to_string(u) + string(1, char(back[i]));
                    string c2 = to_string(*trumps2.begin()) + string(1, T);
                    plays.push_back({c1, c2});
                    trumps2.erase(trumps2.begin());
                } else {
                    now = 0;
                    break;
                }
            } else {
                string c1 = to_string(u) + string(1, char(back[i]));
                string c2 = to_string(*beat) + string(1, char(back[i]));
                deck2[i].erase(beat);
                plays.push_back({c1, c2});
            }
        }
        if (now == 0) break;
    }

    if (now) {
        db = 1;
        ans = plays;
    }
}

void solve() {
    db = 0;
    ans.clear();
    int n; cin >> n;
    char T; cin >> T;
    vector<pair<int, char>> a(n * 2);

    vector<pair<int, char>> p1, p2;

    set<int, greater<>> trumps;
    vector<vector<int>> deck(4);

    for (int i = 0; i < n * 2; i++) {
        char num; cin >> num;
        a[i].first = num - '0';
        cin >> num;
        a[i].second = num;
        if (a[i].second == T) {
            trumps.insert(a[i].first);
        } else {
            deck[conv[a[i].second]].push_back(a[i].first);
        }
    }

    int np1 = 0, np2 = 0;

    for (auto u : trumps) {
        if (np2 == n) {
            p1.push_back({u, T});
            np1++;
        } else {
            p2.push_back({u, T});
            np2++;
        }
    }

    for (int i = 0; i < 4; i++) {
        int sz = deck[i].size();
        sort(deck[i].begin(), deck[i].end());
        int l = 0, r = sz - 1;
        while (l < r) {
            int L = deck[i][l], R = deck[i][r];
            if (np2 < n && np1 < n) {
                p1.push_back({L, back[i]});
                p2.push_back({R, back[i]});
                np1++, np2++;
                l++, r--;
            } else if (np1 < n) {
                p1.push_back({L, back[i]});
                np1++;
                l++;
            } else if (np2 < n) {
                p2.push_back({R, back[i]});
                np2++;
                r--;
            }
        }
        if (l == r) {
            if (np1 == n) {
                p2.push_back({deck[i][l], back[i]});
                np2++;
            } else {
                p1.push_back({deck[i][l], back[i]});
                np1++;
            }
        }
    }

    debug(p1, p2);
    debug(p1);

    solve(2 * n, T, p1, p2);

    if (db == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto [u, v] : ans) {
            cout << u << " " << v << endl;
        }
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    conv[int('C')] = 0;
    conv[int('D')] = 1;
    conv[int('H')] = 2;
    conv[int('S')] = 3;
    back[0] = 'C';
    back[1] = 'D';
    back[2] = 'H';
    back[3] = 'S';

    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
