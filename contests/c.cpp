#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define int int64_t
const int maxn = 1e6 + 50;
const int inf = 1e18;
#define pop_count __builtin_popcountll

int a[maxn];
int f[maxn], max_b_pairs[maxn];
int l[maxn], r[maxn];

void solve() {
    int n, A, B;
    cin >> n >> A >> B;
    rep(i, 1, 2 * n) cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    rep(i, 2, 2 * n) max_b_pairs[i] = -inf;
    for (int i = 2; i <= 2 * n; i += 2) {
        if (a[i] - a[i - 1] > A) {
            cout << "-1\n";
            return;
        }
    }
    if (a[2] - a[1] <= B) {
        max_b_pairs[2] = 1;
        r[2] = -1;
    } else {
        max_b_pairs[2] = 0;
        r[2] = 1;
    }
    for (int i = 4; i <= 2 * n; i += 2) {
        if (r[i - 2] == -1) {
            // todo mundo ta pareado atras
            if (a[i] - a[i - 1] <= B) {
                max_b_pairs[i] = max_b_pairs[i - 2] + 1;
                r[i] = -1;
            } else {
                max_b_pairs[i] = max_b_pairs[i - 2];
                r[i] = i - 1;
            }
        // o [i - 2] e o r[i - 2] ainda nao tao pareados
        } else if (a[i - 1] - a[i - 2] <= B && a[i] - a[r[i - 2]] <= A) {
            // da pra fazer B-pair (i-1, i-2) e A-pair (i, r[i-2])
            max_b_pairs[i] = max_b_pairs[i - 2] + 1;
            r[i] = r[i - 2];
        } else if (a[i] - a[i - 1] <= B) {
            // da pra fazer B-pair (i-1, i)
            max_b_pairs[i] = max_b_pairs[i - 2] + 1;
            r[i] = -1;
        } else {
            max_b_pairs[i] = max_b_pairs[i - 2];
            r[i] = i - 1;
        }
    }
    cout << max_b_pairs[2 * n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int __ = 1;
    // srand((time(0)));

    cin >> __;

    while (__--) solve();
    return 0;
}
