#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 500;
int n, m;
ll arr[MAX];

void solve() {
    cin >> n >> m;
    vector<ll> dm;
    vector<ll> dmv;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            dm.push_back(arr[i] - arr[i + 1]);
        else
            dm.push_back(0);
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            dmv.push_back(arr[i] - arr[i - 1]);
        else
            dmv.push_back(0);
    }
    vector<ll> pf(n);
    vector<ll> sf(n);
    for (int i = 1; i < n; i++) {
        pf[i] = dm[i - 1] + pf[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = dmv[i] + sf[i + 1];
    }
    for (int i = 0; i < m; i++) {
        int s, t;
        cin >> s >> t;
        if (t >= s)
            cout << pf[t - 1] - pf[s - 1] << endl;
        else
            cout << sf[t - 1] - sf[s - 1] << endl;
    }
}

int main() {
    _ solve();
    return 0;
}
