#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
template <typename T> using pql = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define pb push_back
#define eb emplace_back
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define ROF(i, x, y) for (int i = x; i >= y; i--)
#define FO(x) FOR(i, 0, x)
#define OF(x) ROF(i, x, 0)
#define endl '\n'

const int MAX = 2e3;
int l, c;
char m[MAX][MAX];
int vis[MAX][MAX];

ii moves[] = {ii(0, 1), ii(1, 0), ii(-1, 0), ii(0, -1)};

/* VAI DAR TLE */

int dist[MAX][MAX];

void bfs(int i, int j) {
    /* priority_queue<pair<int,ii>, vector<pair<int,ii>>, greater<pair<int,ii>>> pq; */
    deque<pair<int, ii>> pq;
    pq.push_front({0, ii(i, j)});
    while (!pq.empty()) {
        auto [w, s] = pq.front();
        i = s.first, j = s.second;
        vis[i][j]++;
        pq.pop_front();
        if (dist[i][j] > w) {
            dist[i][j] = w;
            for (auto mv : moves) {
                auto [x, y] = mv;
                if ((i + x) < 0 || (j + y) < 0 || (i + x) == l || (j + y) == c || vis[i + x][j + y]) continue;
                if (m[i][j] == m[i + x][j + y]) {
                    pq.push_front({w, ii(i + x, j + y)});
                } else {
                    pq.push_back({w + 1, ii(i + x, j + y)});
                }
                /* cout << "Indo de " << i << ' ' << j << " (" << m[i][j] << ") pra " << i+x << ' ' << j+y << "(" <<
                 * m[i+x][j+y] << ") com peso " << w+d << endl; */
            }
        }
    }
}

void solve() {
    cin >> l >> c;
    for (int i = 0; i <= l + 1; i++)
        for (int j = 0; j <= c + 1; j++) m[i][j] = 0, vis[i][j] = 0, dist[i][j] = INT_MAX;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++) cin >> m[i][j];
    bfs(0, 0);
    cout << dist[l - 1][c - 1] << endl;
}

int main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
