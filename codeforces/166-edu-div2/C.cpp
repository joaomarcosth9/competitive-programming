#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, m; cin >> n >> m;

    int N = n + m + 1;
    vector<pair<int, int>> a(N);
    vector<int> tr1(N), tr2(N);
    for (int i = 0; i < N; i++) {
        cin >> tr1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> tr2[i];
    }
    for (int i = 0; i < N; i++) {
        a[i] = {tr1[i], tr2[i]};
    }

    // tenho N caras

    vector<pair<int, int>> pref(N + 1), psum(N + 1);
    vector<int> mx(N + 1), t1(N + 1), t2(N + 1), score(N + 1);

    pref[0] = {0, 0};
    score[0] = 0;

    for (int i = 1; i <= N; i++) {
        pref[i] = pref[i - 1];
        psum[i] = psum[i - 1];
        score[i] = score[i - 1];
        mx[i] = mx[i - 1];
        t1[i] = t1[i - 1];
        t2[i] = t2[i - 1];
        t1[i] += a[i - 1].first;
        t2[i] += a[i - 1].second;

        if (a[i - 1].first > a[i - 1].second) {
            psum[i].first++;
            mx[i] += a[i - 1].first;
            if (pref[i].first < n) {
                pref[i].first++;
                score[i] += a[i - 1].first;
            } else {
                pref[i].second++;
                score[i] += a[i - 1].second;
            }
        } else {
            psum[i].second++;
            mx[i] += a[i - 1].second;
            if (pref[i].second < m) {
                pref[i].second++;
                score[i] += a[i - 1].second;
            } else {
                pref[i].first++;
                score[i] += a[i - 1].first;
            }
        }
    } 

    auto query1 = [&] (int l, int r) {
        return t1[r] - t1[l - 1];
    };
    auto query2 = [&] (int l, int r) {
        return t2[r] - t2[l - 1];
    };
    auto query_great = [&] (int l, int r) {
        return mx[r] - mx[l - 1];
    };

    debug(t2);
    debug(mx);

    for (int i = 1; i < N; i++) {
        // vou excluir o i
        int score_now = score[i - 1];
        pair<int, int> have = pref[i - 1];

        int l = i + 1, r = N;
        int ans = -1;
        pair<int, int> best = have;

        while (l <= r) { 
            int mid = midpoint(l, r);
            auto now = psum[mid];
            now.first -= psum[i].first;
            now.second -= psum[i].second;
            // now eh quanto vou ganhar em cada um
            debug(l, r, mid, psum[mid], now);
            if (have.first + now.first <= n && have.second + now.second <= m) {
                ans = mid;
                best = {have.first + now.first, have.second + now.second};
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        debug(i, score_now, have, best, ans);

        if (ans == -1) {
            int other = 0;
            if (best.first == n) {
                other = query2(i + 1, N);
            } else if (best.second == m) {
                other = query1(i + 1, N);
            } else {
                assert(false);
            }
            cout << score_now + other << " ";
        } else {
            // vou pegar otimo de [i + 1, ans];
            // pegar so um deles de [ans + 1, N];
            int other = 0;
            if (best.first == n) {
                other = query2(ans + 1, N);
            } else if (best.second == m) {
                other = query1(ans + 1, N);
            } else {
                assert(false);
            }
            cout << score_now + query_great(i + 1, ans) + other << " ";
        }
    }

    cout << score[N - 1] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}