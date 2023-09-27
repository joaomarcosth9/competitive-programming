#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int n, m;
const int maxn = 2004;
int grid[maxn][maxn];
int szl[maxn], szc[maxn], freql[maxn][30], freqc[maxn][30];
set<int> l, c;

bool simulate() {
    vector<ii> toerasel;
    bool done = 0;

    debug(l);
    debug(c);

    for (int i : l) {
        if (c.empty()) break;
        int first = *begin(c);
        int pattern = grid[i][first];

        int freq = freql[i][pattern];
        bool all = freq == szl[i];

        if (all && freq > 1) {
            done = 1;
            toerasel.emplace_back(i, pattern);
        }
    }

    vector<ii> toerasec;

    for (int j : c) {
        if (l.empty()) break;
        int first = *begin(l);
        int pattern = grid[first][j];

        int freq = freqc[j][pattern];
        bool all = freq == szc[j];

        if (all && freq > 1) {
            done = 1;
            toerasec.emplace_back(j, pattern);
        }
    }

    for (auto j : c) {
        szc[j] -= toerasel.size();
    }
    for (auto i : l) {
        szl[i] -= toerasec.size();
    }

    for (auto [i, p] : toerasel) {
        szl[i] = 0;
        for (int j : c) {
            freqc[j][p] -= 1;
        }
        l.erase(i);
    }
    for (auto [j, p] : toerasec) {
        szc[j] = 0;
        for (int i : l) {
            freql[i][p] -= 1;
        }
        c.erase(j);
    }

    return done;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char cc; cin >> cc;
        grid[i][j] = cc;
        grid[i][j] -= 'a';
        int u = grid[i][j];
        szl[i] = m, szc[j] = n;
        freql[i][u] += 1;
        freqc[j][u] += 1;
    }
    for (int i = 0; i < n; i++) {
        l.emplace(i);
    }
    for (int j = 0; j < m; j++) {
        c.emplace(j);
    }

    while(simulate());

    int r = 0;
    for (int i : l) for (int j : c) r++;
    cout << r << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) { cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration <double, milli> (diff).count() << " ms" << endl;
#endif
}

