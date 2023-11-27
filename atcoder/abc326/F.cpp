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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> X, Y;
    for (int i = 0; i < n; i++) {
        if (i & 1) X.eb(a[i]);
        else Y.eb(a[i]);
    }

    auto solve = [&] (vector<int> coords, int target) {
        int N = size(coords);
        int mid = N / 2;
        vector<int> L, R;
        for (int i = 0; i < mid; i++) L.eb(coords[i]);
        for (int i = mid; i < N; i++) R.eb(coords[i]);
        unordered_map<ll, int, custom_hash> hasL, hasR;
        int sl = size(L), sr = size(R);
        for (int i = 0; i < (1 << sl); i++) {
            ll sum = 0;
            for (int j = 0; j < sl; j++) {
                if (i & (1 << j)) sum += L[j];
                else sum -= L[j];
            }
            hasL[sum] = i;
        }
        for (int i = 0; i < (1 << sr); i++) {
            ll sum = 0;
            for (int j = 0; j < sr; j++) {
                if (i & (1 << j)) sum += R[j];
                else sum -= R[j];
            }
            hasR[sum] = i;
        }
        for (auto [sum, mask] : hasL) {
            if (hasR.count(target - sum)) {
                ll ret = 0;
                for (int i = 0; i < sl; i++) if (mask & (1 << i)) ret |= 1ll << i;
                int mask2 = hasR[target - sum];
                for (int i = 0; i < sr; i++) if (mask2 & (1 << i)) ret |= 1ll << (i + sl);
                return ret;
            }
        }
        return -1ll;
    };

    auto canX = solve(X, x);
    auto canY = solve(Y, y);
    debug(canX, canY);

    if (canX == -1 || canY == -1) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

    pair<int, int> now = {1, 0};
    int ity = 0, itx = 0;

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            auto dir = (canX >> itx) & 1;
            if (dir) {
                if (now.second == 1) {
                    cout << "R";
                } else if (now.second == -1) {
                    cout << "L";
                }
                now = {1, 0};
            } else {
                if (now.second == 1) {
                    cout << "L";
                } else if (now.second == -1) {
                    cout << "R";
                }
                now = {-1, 0};
            }
            itx++;
        } else {
            auto up = (canY >> ity) & 1;
            if (up) {
                if (now.first == 1) {
                    cout << "L";
                } else if (now.first == -1) {
                    cout << "R";
                }
                now = {0, 1};
            } else {
                if (now.first == 1) {
                    cout << "R";
                } else if (now.first == -1) {
                    cout << "L";
                }
                now = {0, -1};
            }
            ity++;
        }
    }

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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
