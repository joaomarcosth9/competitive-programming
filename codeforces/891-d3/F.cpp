#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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

int mysqrt(int u) {
    if (u < 0) return 0;
    int l = 0, r = 1e10;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * mid <= u) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> aa(n);
    for (int &i : aa) cin >> i;
    unordered_map<int, int, custom_hash> f;
    for (int &i : aa) f[i]++;
    int q;
    cin >> q;
    while (q--) {
        int s, p;
        cin >> s >> p;
        // y = xaj - aj^2
        // -x^2 + xs - y = 0
        int a = -1, b = s, c = -p;
        int delta = b * b - 4 * a * c;
        int u = mysqrt(delta);
        debug(delta, u);
        int res = 0;
        if (u * u == delta && delta >= 0) {
            /* cout << "u " << u << endl; */
            if ((s - u) % 2 == 0) {
                int x1 = (s - u) / 2;
                res += f[x1] * (f[s - x1] - (x1 + x1 == s));
            }
            if (u != 0 && (s + u) % 2 == 0) {
                int x2 = (s + u) / 2;
                res += f[x2] * (f[s - x2] - (x2 + x2 == s));
            }
            res /= 2;
        }
        cout << res << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
