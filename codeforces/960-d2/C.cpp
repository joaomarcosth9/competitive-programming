#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    auto oa = a;

    function<ll()> brute = [&]() {
        ll sum = accumulate(a.begin(), a.end(), 0LL);
        while (a != vector<int> (n, 0)) {
            vector<int> b(n);
            vector<int> f(n + 1);
            int who = 0;
            for (int i = 0; i < n; i++) {
                f[a[i]]++;
                if (f[a[i]] >= 2 && a[i] > who) {
                    who = a[i];
                }
                b[i] = who;
            }
            ll sum2 = accumulate(b.begin(), b.end(), 0LL);
            debug(b, sum2);
            sum += sum2;
            swap(a, b);
        }
        a = oa;
        return sum;
    };

    vector<int> b(n);
    vector<int> f(n + 1);

    ll sum = accumulate(a.begin(), a.end(), 0LL);

    int who = 0;

    for (int i = 0; i < n; i++) {
        f[a[i]]++;
        if (f[a[i]] >= 2 && a[i] > who) {
            who = a[i];
        }
        b[i] = who;
    }

    ll sum2 = accumulate(b.begin(), b.end(), 0LL);

    debug(sum, sum2);

    sum += sum2;

    f = vector<int>(n + 1);

    for (int i = 0; i < n; i++) {
        if (b[i] == 0) continue;
        f[b[i]]++;
    }

    vector<bool> rem(n);

    for (int i = 0; i < n; i++) {
        if (f[b[i]] <= 1) {
            rem[i] = true;
        }
    }

    int last = 0;
    for (int i = 0; i < n; i++) {
        if (rem[i]) {
            debug(i, b[i], last);
            sum2 -= b[i];
            sum2 += last;
            b[i] = last;
        } else {
            last = b[i];
        }
    }

    debug(rem);
    debug(sum2);

    bool first = 1;
    for (int i = n - 1; i >= 0; i--) {
        sum2 -= b[i];
        sum += sum2;
    }

    /* debug("BRUTE"); */
    /* if (sum != brute()) { */
    /*     cout << "a: "; */
    /*     for (int i : a) cout << i << ' '; */
    /*     cout << endl; */
    /*     cout << sum << ' ' << brute() << endl; */
    /*     exit(0); */
    /* } */

    cout << sum << endl;
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
