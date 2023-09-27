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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (a[0] == a[n - 1]) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0]) {
                curr += 1;
                if (curr == k) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        cout << "NO" << endl;
        return;
    }

    int lc = a[n - 1];
    int curr = 0;
    int r = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == lc) {
            curr += 1;
        }
        if (curr == k) {
            r = i;
            break;
        }
    }

    lc = a[0];
    curr = 0;

    if (r < n)
        for (int i = 0; i < r; i++) {
            if (a[i] == lc) {
                curr += 1;
            }
            if (curr == k) {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
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
