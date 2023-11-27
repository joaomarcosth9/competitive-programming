#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll

int f(int A, int B, int w) {
    if (A * w + B > (int)9e18 / w) {
        return 2e18;
    }
    return A * w * w + B * w;
}

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int &u : a) cin >> u;
    for (int &u : a) c -= u * u;
    int A = 4 * n, B = 0;
    for (int i = 0; i < n; i++) B += 4 * a[i];
    c /= 4, A /= 4, B /= 4;
    int l = 1, r = 1e9;
    int mid = -1;
    while (l <= r) {
        mid = (l + r) >> 1;
        int ret = f(A, B, mid);
        if (ret == c) {
            break;
        } else if (ret < c) l = mid + 1;
        else r = mid - 1;
    }
    cout << mid << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}

