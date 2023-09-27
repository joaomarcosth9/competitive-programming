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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }
#define int ll

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> freq(k + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
#ifdef LOCAL_DEBUG
    vector mat(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << min(a[i], a[j]) << " ";
        }
        cout << endl;
    }
#endif

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    vector<int> pref(n, INT_MIN), suff(n, INT_MIN);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = max(pref[i - 1], a[i]);
    }
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(suff[i + 1], a[i]);
    }
    for (int i = 1; i <= k; i++) {
        if (freq[i] == 0) {
            cout << 0 << " ";
            continue;
        }
        int first = -1, last = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pref[mid] >= i) {
                first = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (suff[mid] >= i) {
                last = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << (last - first + 1) * 2 << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
