#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

const int N = 100;
ll n;
char res[N][N];

void solve() {
    cin >> n;

    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = '.';
        }
    }
    ll sq = 1;
    while ((sq + 1) * (sq + 1) <= n) {
        sq++;
    }
    n -= sq * sq;

    for (int i = N - 1; i >= (N - sq); i--) {
        for (int j = 0; j < sq; j++) {
            res[i][j] = 'o';
        }
    }

    ll K = 0;

    if (n & 1) {
        K = (n + 1) / 2;
        res[N - sq][sq - 1] = '.';
    } else {
        K = n / 2;
    }

    for (int j = 0; j < K; j++) {
        res[N - sq - 1 - j][0] = 'o';
    }
    for (int j = 0; j < K; j++) {
        res[N - 1][sq + j] = 'o';
    }

    cout << N << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
