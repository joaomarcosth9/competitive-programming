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
    int n;
    cin >> n;
    
    vector<int64_t> a(n);
    
    for (auto &x : a)
        cin >> x;
        
    int64_t sum = accumulate(a.begin(), a.end() - 2, 0LL);
    
    cout << a.back() - a[n - 2] + sum << endl;
    
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int tt;
    cin >> tt;
    
    while (tt--) solve();
}
