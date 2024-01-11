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
#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    auto c = a, d = b;

    set<vector<int>> ra, rb;
    
    for (int i = 0; i < n; i++) {
        sort(all(c[i]));
        sort(all(d[i]));
        ra.emplace(c[i]);
        rb.emplace(d[i]);
    }

    if (ra != rb) {
        cout << -1 << endl;
        return;
    }

    c = a, d = b;
    set<vector<int>> ca, cb;

    for (int i = 0; i < m; i++) {
        vector<int> nowa, nowb;
        for (int j = 0; j < n; j++) nowa.eb(c[j][i]);
        for (int j = 0; j < n; j++) nowb.eb(d[j][i]);
        sort(all(nowa));
        sort(all(nowb));
        ca.emplace(nowa);
        cb.emplace(nowb);
    }

    if (ca != cb) {
        cout << -1 << endl;
        return;
    }

    vector<int> testr(n);
    iota(all(testr), 0);

    int best = 1e9;

    do {

        auto idra = testr;
        auto aa = a;
        int res = 0;
        vector<int> testc(m);
        iota(all(testc), 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (idra[j] > idra[j + 1]) {
                    swap(idra[j], idra[j + 1]);
                    swap(aa[j], aa[j + 1]);
                    res++;
                }
            }
        }
        do {
            auto aaa = aa;
            idra = testc;
            int res2 = res;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m - 1 - i; j++) {
                    if (idra[j] > idra[j + 1]) {
                        swap(idra[j], idra[j + 1]);
                        for (int k = 0; k < n; k++) swap(aaa[k][j], aaa[k][j + 1]);
                        res2++;
                    }
                }
            }

            if (aaa == b) {
                best = min(best, res2);
            }

        } while (next_permutation(all(testc)));

    } while (next_permutation(all(testr)));

    cout << best << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
