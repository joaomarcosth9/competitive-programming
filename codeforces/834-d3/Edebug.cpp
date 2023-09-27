#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    long long n, h;
    cin >> n >> h;
    int g = 2, b = 1;
    int ones = 0;
    vector<long long> temp(n), v;
    for (auto &a : temp) cin >> a;
    for (auto &a : temp)
        if (a > 1) v.push_back(a);
    sort(v.begin(), v.end());
    ones = n - v.size();
    n = v.size();
    int i;
    for (i = 0; i < n; i++) {
        if (h > v[i]) {
            h += v[i] / 2;
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else if (g && h * 2 > v[i]) {
            h *= 2;
            h += v[i] / 2;
            g--;
            /* cout << "Usando green e "; */
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else if (b && h * 3 > v[i]) {
            h *= 3;
            h += v[i] / 2;
            b--;
            /* cout << "Usando blue e "; */
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else if (g == 2 && h * 4 > v[i]) {
            h *= 4;
            h += v[i] / 2;
            g -= 2;
            /* cout << "Usando 2 green e "; */
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else if (g && b && h * 6 > v[i]) {
            h *= 6;
            h += v[i] / 2;
            g--, b--;
            /* cout << "Usando green e blue e "; */
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else if (g == 2 && b && h * 12 > v[i]) {
            h *= 12;
            h += v[i] / 2;
            g -= 2, b--;
            /* cout << "Usando 2 green e blue e "; */
            /* cout << "Absorvendo " << v[i] << " e nova vida " << h << endl; */
        } else {
            /* cout << "Nao consigo absorver " << v[i] << " com vida " << h << endl; */
            /* cout << "Ainda resta " << g << ' ' << b << endl; */
            break;
        }
    }
    cout << (i + ones * (h > 1)) << endl;
    /* cout << "----------------------\n"; */
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
