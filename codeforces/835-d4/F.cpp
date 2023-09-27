#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
long long n, c, d;

long long mx(int k, vector<long long> &v) {
    if (k >= n) {
        long long gap = k - n + 1, res = 0, tot = 0;
        for (auto &a : v) tot += a;
        long long passo = n + gap, extra = d % passo;
        res += (d / passo) * tot;
        for (int i = d - extra + 1, id = 0; i <= d && id < n; i++, id++) {
            res += v[id];
        }
        return res;
    } else {
        long long ig = n - k - 1;
        long long tempn = n - ig;
        long long res = 0, tot = 0;
        for (int i = 0; i < tempn; i++) tot += v[i];
        res += (d / tempn) * tot;
        long long extra = d % tempn;
        for (int i = d - extra + 1, id = 0; i <= d && id < n; i++, id++) {
            res += v[id];
        }
        return res;
    }
}

void solve() {
    cin >> n >> c >> d;
    vector<long long> qs(n);
    for (auto &a : qs) cin >> a;
    sort(qs.rbegin(), qs.rend());
    long long t1 = 0, t2 = 0;
    for (int i = 0; i < d; i++) {
        t1 += qs[0];
        if (i < n) t2 += qs[i];
    }
    if (t1 < c) {
        cout << "Impossible\n";
        return;
    } else if (t2 >= c) {
        cout << "Infinity\n";
        return;
    }

    /* int teste; cin >> teste; */

    /* long long res = mx(teste, qs); */

    /* if(res >= c){ */
    /*     cout << "Deu bom" << endl; */
    /*     if (mx(teste+1, qs) < c) */
    /*         cout << " e eh a melhor" << endl; */
    /*     else */
    /*         cout << " mas n eh a melhor" << endl; */
    /* } else { */
    /*     cout << "Deu ruinzao" << endl; */
    /* } */

    long long res = -1;

    int l = 0, r = 1e9;

    auto check = [&](int k) { return (mx(k, qs) >= c); };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        bool db = check(mid);
        if (db) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << res << endl;
}

int main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
