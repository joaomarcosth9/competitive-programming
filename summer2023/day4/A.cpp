#include <bits/stdc++.h>
#include <ranges>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> esp(32);

    int size = n;
    vector<int> indexes(n);
    iota(indexes.begin(), indexes.end(), 1);
    int bit = 0;
    int res = 0;
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(i);

    while (1) {
        if (s.size() == 1) {
            cout << "! " << *(s.begin()) << endl;
            return;
        }
        vector<int> b1, b0;
        int e1 = 0, e0 = 0;
        for (int j : s) {
            e1 += (bool)(j & (1 << bit));
            e0 += (bool)(~j & (1 << bit));
        }
        for (int i : indexes) {
            cout << "? " << i << " " << bit << endl;
            int res_bit;
            cin >> res_bit;
            if (res_bit == 1) {
                b1.push_back(i);
            } else {
                b0.push_back(i);
            }
        }
        if ((int)b1.size() < e1) {
            res |= (1 << bit);
            /* cout << "Esperava mais 1's no bit " << bit << endl; */
            /* cout << res << endl; */
            indexes = b1;
        } else if ((int)b0.size() < e0) {
            /* cout << "Esperava mais 0's no bit " << bit << endl; */
            /* cout << res << endl; */
            indexes = b0;
        }
        int bb = (1 << bit) & res;
        vector<int> apagar;
        for (auto a : s) {
            int ba = (1 << bit) & a;
            if (bb != ba) {
                apagar.push_back(a);
            }
        }
        for (auto a : apagar) s.erase(a);
        bit++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
