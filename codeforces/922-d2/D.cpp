#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template <typename T, auto OP> struct op_stack : stack<T> {
    stack<T> st;
    T get() {
        return st.top();
    }
    void add(T element) {
        this->push(element);
        st.push(st.empty() ? element : OP(element, st.top()));
    }
    void remove() {
        st.pop();
        this->pop();
    }
};

template <typename T, auto OP> struct op_queue : queue<T> {
    op_stack<T, OP> st1, st2;
    T get() {
        if (st1.empty()) return st2.get();
        if (st2.empty()) return st1.get();
        return OP(st1.get(), st2.get());
    }
    void add(T element) {
        this->push(element);
        st1.add(element);
    }
    void remove() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.add(st1.top());
                st1.remove();
            }
        }
        st2.remove();
        this->pop();
    }
};

const int N = 400100;
int n, a[N];
ll dp[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll L = *max_element(a, a + 1 + n);
    ll R = accumulate(a, a + 1 + n, 0ll);
    ll ans = -1;

    while (L <= R) {
        ll M = (L + R) >> 1;
        for (int i = 0; i <= n; i++) {
            dp[i] = 0;
        }
        debug(M);

        auto f = [] (ll x, ll y) {
            return min(x, y);
        };

        op_queue<ll, f> q;

        ll ac = a[1];
        dp[1] = a[1];
        q.add(0);
        q.add(dp[1]);
        int LL = 0;

        for (int i = 2; i <= n; i++) {
            while (ac - a[LL] > M) {
                ac -= a[LL++];
                if (q.size()) q.remove();
            }
            debug(LL, i - 1);
            if (q.size()) debug(q.get());
            dp[i] = a[i] + (LL && q.size() ? q.get() : 0);
            ac += a[i];
            q.add(dp[i]);
        }

        bool db = 0;
        ac = 0;
        for (int i = n; i >= 1; i--) {
            if (ac <= M) {
                db |= dp[i] <= M;
            }
            ac += a[i];
        }

        if (db) {
            ans = M;
            R = M - 1;
        } else L = M + 1;

    }
    
    cout << ans << endl;

    for (int i = 0; i <= n; i++) {
        a[i] = dp[i] = 0;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
