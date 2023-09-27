#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }
#define int ll

int op = 0;

int ask(int i) {
    assert(op < 100);
    cout << "? " << i << endl;
    int y;
    cin >> y;
    op += 1;
    return y;
}

void solve() {
    op = 0;
    int n, k;
    cin >> n >> k;

    int i = 1;
    int X = 0;
    if (n % k == 0) {
        // gg
        while (i <= n) {
            int x = ask(i);
            X ^= x;
            i += k;
        }
        assert(i == n + 1);
        cout << "! " << X << endl;
        return;
    }

    i = 1;
    vector<int> XOR(n + 10);
    vector<int> XORK(n + 10);

    while (i + k <= n) {
        XOR[i] = ask(i);
        XOR[i] = ask(i);
        i += 1;
    }

    for (i = 1; i + k <= n; i++) {
        XORK[i] = XOR[i] ^ XOR[i + 1];
    }

    // XORK[i] = a[i] ^ a[i + k];

    vector<int> pref(n + 11);
    for (int j = 1; j + k <= n; j++) {
        pref[j] = pref[j - 1] ^ XORK[j];
    }
    auto query = [&](int l, int r) { return pref[r] ^ pref[l - 1]; };

    X = 0;
    i = 1;
    while (i + k <= n) {
        X ^= ask(i);
        i += k;
    }

    i -= k;

    int j = n - k + 1;
    int falta = n % k;
    int L = i - falta;
    int R = i - 1;

    int X2 = query(L, R);

    int X3 = XOR[L] ^ X2;
    X3 ^= XOR[i];
    int X2B = X3;

    // X3 eh o range dos dois blocos finais

    X3 ^= XOR[i];
    // X3 eh o bloco final com a bomba trocada

    X3 ^= XOR[j];

    int X4 = X3 ^ XOR[i];

    int XJ2 = X4 ^ X2B;
    XJ2 ^= XOR[i];

    int XF = XJ2 ^ X4;

    X ^= XF;

    cout << "! " << X << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
