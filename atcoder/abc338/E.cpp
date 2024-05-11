#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n; cin >> n;
    stack<int> st;
    vector<int> line(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        line[a] = (i << 1);
        line[b] = (i << 1) ^ 1;
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (line[i]) {
            if (line[i] & 1) {
                if (st.top() != (line[i] ^ 1)) return 1;
                st.pop();
            } else {
                st.push(line[i]);
            }
        }
    }
    return 0;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    /* solve(); */
    /* cout << solve() << endl; */
    cout << (solve() ? "Yes" : "No") << endl;
}
