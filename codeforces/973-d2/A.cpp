#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

void _print() { }
template<typename T, typename... U>
void _print(T a, U... b) {
    if (sizeof...(b)) {
        cerr << a << ", ";
        _print(b...);
    } else cerr << a;
}

#ifdef BRUTE
#define debug(x...) cerr << "[" << #x << "] = [", _print(x), cerr << "]" << endl
#else
#define debug(...)
#endif

// -------- END OF TEMPLATE --------

void solve() {
    int64_t n, x, y;
    cin >> n >> x >> y;
    x = min(x, y);
    n += x - 1;
    n /= x;
    cout << n << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt;
    cin >> tt;
    
    while (tt--) solve();
}
