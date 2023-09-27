#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve() {
    long long n, m;
    cin >> n >> m;
    int f5 = 0, f2 = 0;
    long long temp = n;
    while (temp % 5 == 0) {
        f5++;
        temp /= 5;
    }
    temp = n;
    while ((temp & 1) == 0) {
        f2++;
        temp >>= 1;
    }
    long long mult = 1;
    /* cout << f2 << ' ' << f5 << endl; */
    if (f2 < f5) {
        while (f2 < f5 && mult <= m) {
            mult <<= 1;
            f2++;
        }
        if (mult > m) {
            mult >>= 1;
        }
        /* cout << "Mult 2 " << mult << endl; */
    } else if (f2 > f5) {
        while (f2 > f5 && mult <= m) {
            mult *= 5;
            f5++;
        }
        if (mult > m) {
            mult /= 5;
        }
        /* cout << "Mult 5 " << mult << endl; */
    }

    while (mult * 10 <= m) {
        mult *= 10;
    }

    long long oldn = n;
    n *= mult;

    /* cout << n << ' '; */
    n = n * ((m * oldn) / n);

    cout << n << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
