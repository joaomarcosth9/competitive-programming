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

int f(int x) {
    return (x * (x - 1)) / 2;
}

void solve() {
    int n; cin >> n;
    int N = f(n);
    vector<int> b(N);
    for (int &i : b) cin >> i;
    vector<int> a;
    map<int,int,greater<int>> freq;
    for (auto i : b) freq[i]++;
    debug(freq);
    int added = 0;
    for (auto [k, gt] : freq) {
        a.emplace_back(k);
        int me = 1;
        int delta = 1;
        while (gt - f(me) - (added * me)) {
            a.emplace_back(k);
            me += 1;
            delta += 1;
        }
        added += delta;
    }
    for (auto u : a) cout << u << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
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
