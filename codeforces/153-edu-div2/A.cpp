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

void solve() {
    string s; cin >> s;
    if (s == "()") {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int n = size(s);
    string res;
    for (int i = 0; i < n; i++) res += "(";
    for (int i = 0; i < n; i++) res += ")";

    int spos = 0, sneg = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '(') {
            j = i;
            break;
        }
        spos += 1;
    }
    for (; j < n; j++) {
        if (s[j] != ')') {
            break;
        }
        sneg += 1;
    }

    debug(s, spos, sneg);

    if (spos + sneg < n) {
        cout << res << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "()";
    }
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
