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

void solve() {
    int n; cin >> n;
    vector<int> a(n), odd, even;
    for (int &i : a) {
        cin >> i;
        if (i & 1) odd.emplace_back(i);
        else even.emplace_back(i);
    }
    vector<int> msk(n);
    for (int i = 0; i < n; i++) {
        msk[i] = a[i] & 1;
    }
    sort(begin(even), end(even));
    sort(begin(odd), end(odd));
    int i = 0, j = 0;
    for (int idx = 0; idx < n; idx++) {
        if (msk[idx]) {
            a[idx] = odd[i++];
        } else {
            a[idx] = even[j++];
        }
        if (idx > 0 && a[idx] < a[idx - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}
