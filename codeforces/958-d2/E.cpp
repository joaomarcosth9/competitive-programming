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
    vector<ll> a(n);
    for (ll &i : a) { 
        cin >> i;
    }

    vector<int> fl(n, -1), fr(n, n), sl(n, -1), sr(n, n);

    stack<int> st, st2;

    for (int i = 0; i < n; i++) {
        vector<int> t;
        while (st.size() && a[i] < a[st.top()]) {
            fr[st.top()] = i;
            t.push_back(st.top());
            st.pop();
        }
        st.push(i);
        while (st2.size() && a[i] < a[st2.top()]) {
            sr[st2.top()] = i;
            st2.pop();
        }
        reverse(t.begin(), t.end());
        for (auto u : t) {
            st2.push(u);
        }
    }

    while (st.size()) {
        st.pop();
    }
    while (st2.size()) {
        st2.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        vector<int> t;
        while (st.size() && a[i] < a[st.top()]) {
            fl[st.top()] = i;
            t.push_back(st.top());
            st.pop();
        }
        st.push(i);
        while (st2.size() && a[i] < a[st2.top()]) {
            sl[st2.top()] = i;
            st2.pop();
        }
        reverse(t.begin(), t.end());
        for (auto u : t) {
            st2.push(u);
        }
    }

    ll tot = 0;
    vector<ll> contrib(n);
    for (int i = 0; i < n; i++) {
        contrib[i] = a[i] * (i - fl[i]) * (fr[i] - i);
        tot += contrib[i];
    }
    debug(tot);
    // removing a[i], for all elements that have a[i] in: a[j] ... a[i] ... fr[j], tot -= a[j] * (j - fl[j])
    // and, for all elements that have a[i] in:
    // a[j] .... a[i] (i == fr[j]), ..., sr[j] , tot += a[j] * (j - fl[j]) * (sr[j] - fr[j] - 1)
    vector<ll> rem(n);

    auto update = [&] (int l, int r, ll val) {
        l = max(l, 0);
        r = min(r, n - 1);
        if (l > r) return;
        rem[l] += val;
        if (r < n - 1) rem[r + 1] -= val;
    };

    for (int i = 0; i < n; i++) {
        // a[i] * (i - fl[i])
        update(i + 1, fr[i] - 1, -a[i] * (i - fl[i]));
        // a[i] * (fr[i] - i)
        update(fl[i] + 1, i - 1, -a[i] * (fr[i] - i));

        update(fr[i], fr[i], a[i] * (i - fl[i]) * (sr[i] - fr[i] - 1));
        update(fl[i], fl[i], a[i] * (fr[i] - i) * (fl[i] - sl[i] - 1));
    }

    for (int i = 1; i < n; i++) {
        rem[i] += rem[i - 1];
    }

    for (int i = 0; i < n; i++) {
        ll now = tot - contrib[i] + rem[i];
        cout << now << " \n"[i == n - 1];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
