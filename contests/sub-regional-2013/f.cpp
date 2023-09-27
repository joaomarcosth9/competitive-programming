#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> pref[i + 1];
        pref[i + 1] += pref[i];
    }
    map<int, bool> freq;
    long long t = pref.back();
    for (int i = 1; i <= n; i++) {
        freq[pref[i] % t] = 1;
    }

    if (t % 3) {
        cout << 0 << '\n';
        return;
    }
    long long passo = t / 3;

    int res = 0;

    for (int i = 1; i <= n; i++) {
        long long curr = pref[i];
        // cout << curr << ' ' << (curr+passo)%t << ' ' << (curr+2*passo)%t << '\n';
        res += (freq[(curr + passo) % t] && freq[(curr + 2 * passo) % t]);
    }
    cout << res / 3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
