#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

string round(string s) {
    s = "0" + s;
    debug(s);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= '5') {
            s[i] = '0';
            for (int j = i + 1; j < n; j++) s[j] = '0';
            int idx = i - 1;
            if (s[idx] != '9') s[idx] += 1;
            int j = idx;
            while (s[j] >= '5') {
                s[j] = '0';
                if (s[j - 1] != '9') s[j - 1] += 1;
                j--;
            }
            break;
        }
    }
    while (s[0] == '0') s.erase(begin(s));
    return s;
}

void solve() {
    string s;
    cin >> s;
    s = round(s);
    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
