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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (is_sorted(all(a))) {
        return 0;
    }
    if (is_sorted(rall(a))) {
        return 1;
    }

    int res = 0;

    auto test = [&] (vector<int> b) {
        int N = size(b);

        auto mn = *min_element(all(b));

        int J = -1, K = -1;

        for (int i = 0; i < N; i++) {
            if (b[i] == mn) {
                J = K = i;
                while (b[(J + 1) % n] == mn) {
                    J = (J + 1) % n;
                }
                while (b[(K - 1 + n) % n] == mn) {
                    K = (K - 1 + n) % n;
                }
                break;
            }
        }

        debug(b);
        debug(J, K);

        auto c = b;
        reverse(all(c));

        for (int i = 0; i < N; i++) b.eb(b[i]);

        bool db = 1;
        for (int i = K + 1; i < K + N; i++) {
            db &= b[i] >= b[i - 1];
        }
        if (db) return db;

        for (int i = 0; i < N; i++) c.eb(c[i]);
        
        J = N - 1 - J;
        for (int i = J + 1; i < J + N; i++) {
            db &= b[i] >= b[i - 1];
        }
        if (db) return db;

        return false;

    };

    auto ra = a;
    reverse(all(ra));

    if (!test(a) && !test(ra)) return -1;

    auto calc = [&] (vector<int> b) {
        int N = size(b);

        auto mn = *min_element(all(b));

        int J = -1, K = -1;
        for (int i = 0; i < N; i++) {
            if (b[i] == mn) {
                J = K = i;
                while (b[(J + 1) % N] == mn) {
                    J = (J + 1) % N;
                }
                while (b[(K - 1 + N) % N] == mn) {
                    K = (K - 1 + N) % N;
                }
                break;
            }
        }

        for (int i = 0; i < N; i++) b.eb(b[i]);
        debug(b);

        int res = 2e9;

        vector<int> c;
        for (int i = K; i < K + N; i++) {
            c.eb(b[i]);
        }
        if (is_sorted(all(c))) {
            res = min(res, N - K);
        }
        if (is_sorted(rall(c))) {
            res = min(res, N - K + 1);
        }
        debug(c);
        c.clear();
        for (int i = N + J; i > J; i--) {
            c.eb(b[i]);
        }
        debug(c);
        if (is_sorted(all(c))) {
            res = min(res, N - J);
        }
        if (is_sorted(rall(c))) {
            res = min(res, N - J - 1);
        }

        return res;
    };

    return min(calc(a), calc(ra) + 1);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
