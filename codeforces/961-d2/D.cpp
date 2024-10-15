#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, c, k; cin >> n >> c >> k;
    string s; cin >> s;

    if (n == 1 || k == n) {
        cout << 1 << endl;
        return;
    }

    auto rev = [&] (int x) {
        return x ^ ((1 << c) - 1); 
    };

    int c_mask = 0;
    vector<int> freq(c, 0);

    vector<int> masks;

    for (int i = 0; i < k; i++) {
        int c = s[i] - 'A';
        freq[c]++;
        c_mask |= (1 << c);
    }
    masks.push_back(c_mask);

    for (int i = k; i < n; i++) {
        int c = s[i - k] - 'A';
        freq[c]--;
        if (freq[c] == 0) {
            c_mask &= ~(1 << c);
        }
        c = s[i] - 'A';
        freq[c]++;
        if (freq[c] == 1) {
            c_mask |= (1 << c);
        }
        masks.push_back(c_mask);
    }

    /*

    pra cada intervalo de tamanho k, eu tenho uma mascara de frequencia
    [010101010001...], a minha mascara pra ser boa, tem que ter AND != 0
    com todas as (n - k + 1) mascaras de frequencia, ou seja, pra uma mascara
    ser ruim, tem que ter AND == 0 com ALGUMA mascara de frequencia

    dada a mascara msk, msk tem AND == 0 com alguem? 
    tipo, msk = 10100 tem AND == 0 com y = 01011 (~msk)
    ou tambem com y = qualquer submascara de ~msk

    */

    vector<int> has(1 << c, 0), bad(1 << c, 0);

    for (auto y : masks) {
        has[y] = 1;
    }

    for (int i = 0; i < (1 << c); i++) {
        for (int j = 0; j < c; j++) if (i & (1 << j)) {
            has[i] |= has[i ^ (1 << j)];
        }
    }

    int best = 1e9, last = s.back() - 'A';

    for (int msk = 0; msk < (1 << c); msk++) {
        // tenho AND == 0 com alguem?
        bad[msk] = has[rev(msk)];
        if ((msk & (1 << last)) && !bad[msk]) {
            best = min(best, (ll)__builtin_popcount(msk));
        }
    }

    cout << best << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
