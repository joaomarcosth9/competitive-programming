#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> Np;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Np.push_back({a, b});
    }

    int res = (1 << n) - 1;
    for (int j = 1; j <= (1 << n) - 1; j++) {
        vector<int> Pm;
        for (int i = 1; i <= n; i++) {
            if ((1 << (i - 1)) & j) Pm.push_back(i);
        }

        int dmr = 0;
        for (int k = 0; k < m; k++) {
            int dr = 0;
            if (dmr) break;
            auto [a, b] = Np[k];
            for (int i = 0; i < (int)Pm.size(); i++) {
                if (Pm[i] == a || Pm[i] == b) {
                    dr++;
                    if (dr == 2) {
                        dmr = 1;
                        res--;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    _ solve();
    return 0;
}
