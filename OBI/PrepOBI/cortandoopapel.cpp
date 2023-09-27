#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1.1e9;
const long long INFLL = 1.1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> unique{0, v[0]};
    for (int i = 1; i < n; i++) {
        if (v[i] != unique.back()) {
            unique.push_back(v[i]);
        }
    }
    unique.push_back(0);

    auto pico = [&](int i) { return unique[i] > unique[i - 1] && unique[i] > unique[i + 1]; };
    auto vale = [&](int i) { return unique[i] < unique[i - 1] && unique[i] < unique[i + 1]; };

    vector<pair<int, int>> nw;
    for (int i = 1; i < (int)unique.size() - 1; i++) {
        if (pico(i)) {
            nw.push_back({unique[i], -1});
        } else if (vale(i)) {
            nw.push_back({unique[i], 1});
        }
    }

    sort(begin(nw), end(nw));

    int res = 2, temp = 2;
    for (int i = 0; i < (int)nw.size(); i++) {
        temp += nw[i].second;
        res = max(res, temp);
    }
    cout << res << endl;
}

signed main() {
#ifdef SUBLIME
    freopen("/tmp/input.txt", "r", stdin);
    freopen("/tmp/output.txt", "w", stdout);
#endif
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
    return 0;
}
