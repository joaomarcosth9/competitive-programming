#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<long long> tempv(n), v(n), tempsq(w), sq(w);
    for (auto &a : tempv) cin >> a;
    for (auto &a : tempsq) cin >> a;
    for (int i = 1; i < n; i++) {
        v[i] = tempv[i] - tempv[i - 1];
    }
    for (int i = 1; i < w; i++) {
        sq[i] = tempsq[i] - tempsq[i - 1];
    }
    long long P = 2579, MOD = 1'000'000'007, H = 0, CH = 0, fator = 1;
    auto add = [&](long long &a, long long b) {
        a = (a + b) % MOD;
        if (a < 0) a += MOD;
    };
    auto mult = [&](long long &a, long long b) {
        a = (a * b) % MOD;
        if (a < 0) a += MOD;
    };
    for (int i = w - 1; i > 0; i--) {
        add(H, sq[i] * fator);
        mult(fator, P);
    }
    fator = 1;
    for (int i = w - 1; i > 0; i--) {
        add(CH, v[i] * fator);
        mult(fator, P);
    }
    int res = 0;
    res += CH == H;
    w--;
    for (int i = 2; i <= n - w; i++) {
        mult(CH, P);
        add(CH, -(fator * v[i - 1]));
        add(CH, v[i + w - 1]);
        res += CH == H;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
