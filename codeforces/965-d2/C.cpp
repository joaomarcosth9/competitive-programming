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

struct Seg {
    vector<ll> S;
    vector<int> Q;
    int N, CNT;

    Seg(int _n) {
        N = 1;
        CNT = 0;
        while (N < _n) N *= 2;
        S.assign(2 * N, 0);
        Q.assign(2 * N, 0);
    }

    inline void update(int i, ll val, int d) {
        CNT += d;
        i += N;
        S[i] += val * d;
        Q[i] += d;
        for (i >>= 1; i > 0; i >>= 1) {
            S[i] = S[i << 1] + S[i << 1 | 1];
            Q[i] = Q[i << 1] + Q[i << 1 | 1];
        }
    }

    inline pair<int, ll> get_median() {
        int P = 1;
        int L = 0, R = N - 1;
        int len = (CNT + 1) / 2;
        while (L < R) {
            int M = (L + R) / 2;
            if (Q[P << 1] >= len) {
                P = P << 1;
                R = M;
            } else {
                len -= Q[P << 1];
                P = P << 1 | 1;
                L = M + 1;
            }
        }
        return {L, S[P] / Q[P]};
    }

    inline pair<ll, int> query(int L, int R) {
        pair<ll, int> ans = {0, 0};
        for (L += N, R += N + 1; L < R; L >>= 1, R >>= 1) {
            if (L & 1) {
                ans.first += S[L];
                ans.second += Q[L];
                L++;
            }
            if (R & 1) {
                R--;
                ans.first += S[R];
                ans.second += Q[R];
            }
        }
        return ans;
    }

    inline pair<ll, int> sum_kth_g_values(int p, int l, int r, int L, int R, int K) {
        if (l > R || r < L) {
            return {0, 0};
        }
        if (l >= L && r <= R && Q[p] <= K) {
            return {S[p], Q[p]};
        } else {
            int mid = (l + r) / 2;
            auto [S1, Q1] = sum_kth_g_values(p << 1 | 1, mid + 1, r, L, R, K);
            if (Q1 == K) {
                return {S1, Q1};
            } else {
                auto [S2, Q2] = sum_kth_g_values(p << 1, l, mid, L, R, K - Q1);
                return {S1 + S2, Q1 + Q2};
            }
        }
    }

    inline pair<ll, int> sum_kth_g_values(int K, int L, int R) {
        return sum_kth_g_values(1, 0, N - 1, L, R, K);
    }

};

ll get_max_median(Seg &seg0, Seg &seg1, int k, int sz, vector<ll> &d) {
    int l = 0, r = 4e9;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        // consigo fazer mid de mediana?
        // tenho sz caras, preciso ter (sz + 2) / 2 caras maiores ou iguais a mid
        int conv_mid = lower_bound(d.begin(), d.end(), mid) - d.begin();
        debug(mid, conv_mid);
        // d[conv_mid] eh o primeiro cara maior ou igual a mid
        int need = (sz + 2) / 2;
        auto q0 = seg0.query(conv_mid, seg0.N - 1);
        // q0 sao os caras que nao posso mexer
        auto q1 = seg1.query(conv_mid, seg1.N - 1);
        // q1 sao os caras que posso mexer, mas nao quero
        auto q1_change = seg1.query(0, conv_mid - 1);
        // q1_change sao os caras que posso mexer, e talvez queira
        debug(need);
        debug(q0, q1, q1_change);
        int have = q0.second + q1.second;
        bool ok = have >= need;
        debug(have, ok);
        if (!ok) {
            // tenho que mexer em alguns caras
            int need_change = need - have;
            if (q1_change.second >= need_change) {
                auto [sum, qnts] = seg1.sum_kth_g_values(need_change, 0, conv_mid - 1);
                int expected = need_change * mid;
                if (expected - sum <= k) {
                    ok = true;
                }
            }
        }
        if (ok) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    Seg seg(n), seg0(n), seg1(n);

    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<pair<int, int>> c(n);
    vector<int> d;

    for (int i = 0; i < n; i++) {
        d.push_back(a[i]);
    }
    d.push_back(1e18);

    sort(d.begin(), d.end());
    map<int, int> vis;

    for (int i = 0; i < n; i++) {
        c[i].first = a[i];
        c[i].second = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + vis[a[i]];
        vis[a[i]]++;
    }

    debug(a);
    debug(c);

    for (int i = 1; i < n; i++) {
        seg.update(c[i].second, c[i].first, 1);
        if (b[i] == 1) {
            seg1.update(c[i].second, c[i].first, 1);
        } else {
            seg0.update(c[i].second, c[i].first, 1);
        }
    }

    ll res = 0;

    if (b[0] == 1) {
        res = (ll)a[0] + k + seg.get_median().second;
    } else {
        // quero a maior mediana possivel com k operacoes
        res = max(res, (ll)a[0] + get_max_median(seg0, seg1, k, n - 1, d));
    }

    int mx = *max_element(a.begin(), a.end());

    for (int i = 1; i < n; i++) {
        seg.update(c[i - 1].second, c[i - 1].first, 1);
        seg.update(c[i].second, c[i].first, -1);

        if (b[i - 1] == 1) {
            seg1.update(c[i - 1].second, c[i - 1].first, 1);
        } else {
            seg0.update(c[i - 1].second, c[i - 1].first, 1);
        }
        if (b[i] == 1) {
            seg1.update(c[i].second, c[i].first, -1);
        } else {
            seg0.update(c[i].second, c[i].first, -1);
        }

        if (b[i] == 1) {
            res = max(res, (ll)a[i] + k + seg.get_median().second);
        } else if (a[i] == mx) {
            ll max_median = get_max_median(seg0, seg1, k, n - 1, d);
            res = max(res, (ll)a[i] + max_median);
        }
        debug(i, a[i], res);
    }

    cout << res << endl;
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
