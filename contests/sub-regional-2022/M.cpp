#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1e5 + 5;

int divi[maxn], mu[maxn];
vector<int> primes;

void crivo(int lim) {
    divi[1] = 1;
    mu[1] = 1;
    for (int i = 2; i <= lim; i++) {
        if (divi[i] == 0) divi[i] = i, mu[i] = -1, primes.push_back(i);
        for (int j : primes) {
            if (j > divi[i] or i * j > lim) break;
            divi[i * j] = j;
            if (i % j)
                mu[i * j] = mu[i] * mu[j];
            else
                mu[i * j] = 0;
        }
    }
}

vector<int> get_divs(int n) {
    vector<int> divs{n};
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            if (i * i != n)
                divs.emplace_back(i), divs.emplace_back(n / i);
            else
                divs.emplace_back(i);
        }
    sort(begin(divs), end(divs));
    return divs;
}

int v[maxn], l[maxn], r[maxn], ans[maxn];
long long freq[maxn];
pair<int, int> qu[maxn];
vector<int> has[maxn], divsq[maxn], divsv[maxn];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < q; i++) cin >> qu[i].first >> qu[i].second;

    for (int i = 0; i < n; i++) has[(q - 1) / 2].emplace_back(i);

    for (int i = 0; i < q; i++) divsq[i] = get_divs(qu[i].first);
    for (int i = 0; i < n; i++) divsv[i] = get_divs(i + 1);

    fill(begin(ans), end(ans), -1);
    fill(begin(r), end(r), q - 1);

    while (1) {
        bool br = 1;
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < q; i++) {
            auto [c, d] = qu[i];
            for (int u : divsq[i]) {
                freq[u] += d;
            }
            if (has[i].size()) {
                br = 0;
                for (int u : has[i]) {
                    long long casa = v[u];
                    for (int val : divsv[u]) {
                        casa += mu[val] * freq[val];
                    }
                    if (casa <= 0) {
                        ans[u] = i + 1;
                        r[u] = i - 1;
                    } else {
                        l[u] = i + 1;
                    }
                    if (l[u] <= r[u]) {
                        int mid = (l[u] + r[u]) / 2;
                        has[mid].emplace_back(u);
                    }
                }
            }
            has[i].clear();
        }
        if (br) break;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    crivo(maxn - 1);
    solve();
    return 0;
}
