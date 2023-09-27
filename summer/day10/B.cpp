#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 1e7 + 5;
int divi[maxn];
vector<int> primes;
char mu[maxn];

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) {
            divi[i] = i, primes.push_back(i);
            mu[i] = -1;
        }
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
            if((i % j) == 0){
                mu[i * j] = 0;
            } else {
                mu[i * j] = mu[i] * mu[j];
            }
		}
	}
}

int mult(int l, int r, int u){
    return r / u - (l - 1) / u;
}

void solve() {
    mu[1] = 1;
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    long long res = 0;
    for(int i = 1; i <= max(l2, r2); i++){
        res += (long long) mu[i] * mult(l1, r1, i) * mult(l2, r2, i);
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    crivo(10000003);
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
