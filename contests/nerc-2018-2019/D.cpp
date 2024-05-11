#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
#define int ll

vector<ll> m(2); 

const ll p = 29; 
struct H {
    ll v1, v2; 
    H(ll _v1, ll _v2) : v1(_v1), v2(_v2) {}
    H& operator+=(const H& o) {
        v1 = (v1 + o.v1)%m[0]; 
        v2 = (v2 + o.v2)%m[1]; 
        return *this; 
    } 
    H operator *(const H& o) {
        H ret{v1*o.v1%m[0], v2*o.v2%m[1]}; 
        return ret; 
    } 
    H operator *(const int c) {
        H ret{v1*c%m[0], v2*c%m[1]}; 
        return ret; 
    } 
    bool operator<(const H& o) const {
        if (v1 == o.v1) return v2 < o.v2; 
        return v1 < o.v1; 
    } 
};  

int cnt(string s) {
    set<H> seta; 
    int n = s.size(); 
    for (int l = 0; l < n; l++) {
        H pref{0, 0}; 
        H cp{1, 1}; 
        H P{p, p}; 
        for (int r = l; r < n; r++) {
            pref += cp * (s[r] - 'a' + 1); 
            cp = cp * P;
            seta.emplace(pref); 
        } 
    } 
    return (int)seta.size(); 
} 

// accaa | accaa | accaa

void solve() {
    string s; cin >> s; 
    int n; cin >> n;

    int k = s.size(); 

    ll ans = cnt(s); 

    int c1 = cnt(s + s); 
    int c2 = cnt(s + s + s); 
    ll dif = c2 - c1; 

    ans += dif * (n / k - 1); 

    string suf = s; 
    while (suf.size() > (n%k)) suf.pop_back(); 
    int c3 = cnt(s + suf); 
    ans += c3 - cnt(s); 
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int cnt = 0; 
    for (int i = 1e9 + 45045;; i++) {
        bool ok = 1; 
        for (int j = 2; j * j <= i; j++) {
            ok &= i%j > 0; 
            if (!ok) break; 
        } 
        if (ok) m[cnt++] = i; 
        if (cnt == 2) break; 
    } 

    solve();


}
