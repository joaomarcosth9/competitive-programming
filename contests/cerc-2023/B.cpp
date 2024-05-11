#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
using ld = long double;
#define int ll

const int N = 55;
string s;
int n;
int x[N], y[N];

template <typename T> struct hungarian {
    int n;
    vector<vector<T>> a;
    vector<T> u, v;
    vector<int> p, way;
    T inf;

    hungarian(int n_) : n(n_), u(n+1), v(n+1), p(n+1), way(n+1) {
        a = vector<vector<T>> (n, vector<T>(n));
        inf = numeric_limits<T>::max();
    }

    pair<T, vector<int>> assignment() {
        for (int i = 1; i <= n; i++) {
            p[0] = i;
            int j0 = 0;
            vector<T> minv(n+1, inf);
            vector<int> used(n+1, 0);
            do {
                used[j0] = true;
                int i0 = p[j0], j1 = -1;
                T delta = inf;
                for (int j = 1; j <= n; j++) if (!used[j]) {
                    T cur = a[i0-1][j-1] - u[i0] - v[j];
                    if (cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta) delta = minv[j], j1 = j;
                }
                for (int j = 0; j <= n; j++) {
                    if (used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }
        vector<int> ans(n);
        for (int j = 1; j <= n; j++) ans[p[j]-1] = j-1;
        return make_pair(-v[0], ans);
    }
};

void solve() {
    cout << setprecision(10) << fixed << endl;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<pair<int, int>> boys, girls;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            boys.emplace_back(x[i], y[i]);
        } else {
            girls.emplace_back(x[i], y[i]);
        }
    }

    int B = int(boys.size());
    int G = int(girls.size());

    auto dist = [] (pair<int, int> a, pair<int, int> b) {
        int dx = a.first - b.first;
        int dy = a.second - b.second;
        return sqrtl(ld(dx) * ld(dx) + ld(dy) * ld(dy));
    };

    hungarian<ld> hb(B), hg(G);

    for (int i = 0; i < B; i++) {
        for (int j = 0; j < B; j++) {
            if (i != j) hb.a[i][j] = -dist(boys[i], boys[j]);
            else if (i == j) hb.a[i][j] = 1e18;
        }
    }

    for (int i = 0; i < G; i++) {
        for (int j = 0; j < G; j++) {
            if (i != j) hg.a[i][j] = -dist(girls[i], girls[j]);
            else if (i == j) hg.a[i][j] = 1e18;
        }
    }

    //cout << "Boys" << endl;
    //for (int i = 0; i < B; i++) {
    //    for (int j = 0; j < B; j++) {
    //        cout << hb.a[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    //cout << "Girls" << endl;
    //for (int i = 0; i < G; i++) {
    //    for (int j = 0; j < G; j++) {
    //        cout << hg.a[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    cout << -(hb.assignment().first + hg.assignment().first) / 2 << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
