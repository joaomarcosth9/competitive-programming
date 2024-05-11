#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

vector<int> ask(vector<int> a) {
    cout << "? ";
    for (auto u : a) cout << u << " ";
    cout << endl;
    int k; cin >> k;
    vector<int> ans(k + 1);
    ans[0] = k;
    for (int i = 0; i < k; i++) cin >> ans[i + 1];
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> q;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        q.push_back(i);
        q.push_back(i);
    }
    auto ans1 = ask(q);
    q.clear();
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        q.push_back(i);
        q.push_back(i);
    }
    auto ans2 = ask(q);

    for (int i = 0; i < int(ans1.size()); i++) {
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
