#include <bits/stdc++.h>

using namespace std;

int n, q;
const int MAX = 1.1e4;
char s[MAX];
vector<int> pref[30];
long long res;

void solve() {
    int L, R;
    char t;
    scanf("%d %d %c", &L, &R, &t);
    L--, R--;

    int sz = n;
    int pl = L % sz;
    int st = L - pl;
    int pr = R % sz;
    int en = R - pr;
    int ts = en - st + 1;

    auto &vec = pref[t - 'a'];
    if (vec.empty()) {
        printf("0\n");
        return;
    }

    res += vec.size() * (ts / sz);
    /* cout << "----------\n"; */
    /* for(auto a : vec) cout << a << ' '; */
    /* cout << endl; */
    /* cout << "Current res: "; */
    /* cout << res << endl; */

    int fst, lst;

    auto bs = [&](int cara) {
        int l = 0, r = vec.size() - 1, mid;
        int best = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (vec[mid] > cara) {
                r = mid - 1;
            } else if (vec[mid] <= cara) {
                best = mid + 1;
                l = mid + 1;
            }
        }
        return best;
    };

    fst = bs(pl - 1);
    lst = bs(pr);

    res -= fst, res += lst;

    printf("%lld\n", res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        scanf("%s", s);
        for (int i = 0; i < n; i++) {
            pref[s[i] - 'a'].push_back(i);
        }
        while (q--) {
            res = 0;
            solve();
        }
        for (int i = 0; i < 27; i++) {
            pref[i].clear();
        }
    }
    return 0;
}
