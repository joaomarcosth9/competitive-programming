#include <bits/stdc++.h>

using namespace std;

#define int long long
int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve() {
    int f1 = 1, ff1 = 0, f2 = 1, ff2 = 0;
    int n;
    cin >> n;
    while (n--) {
        int d, k;
        string x;
        cin >> d >> k >> x;
        d--;
        int fa = 0;
        int fna = 0;
        for (int i = 0; i < (int)x.size(); i++) {
            fa += (x[i] == 'a');
            fna += (x[i] != 'a');
        }
        (d ? f2 += fa *k : f1 += fa * k);
        (d ? ff2 += fna *k : ff1 += fna * k);
        int db = 0;
        if (ff2)
            db = 1;
        else if (ff1)
            ;
        else
            db = (f1 < f2);
        cout << (db ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
