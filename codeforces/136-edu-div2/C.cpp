#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
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
#define FOR(i,x,y) for(int i = x; i < y; i++)
#define ROF(i,x,y) for(int i = x-1; i >= y; i--)
#define FO(x) FOR(i,0,x)
#define OF(x) ROF(i,x,0)
#define endl '\n'
#define int long long

const int mod = 998244353;

int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int modinv(int n){
    int x, y;
    int g = extended_euclidean(n, mod, x, y);
    if (g != 1) {
        return -1;
    }
    else {
        x = (x % mod + mod) % mod;
        return x;
    }
}

void solve(){
    int n; cin >> n;
    int fatn = 1, fatn2 = 1;;
    for(int i = 2; i <= n; i++){
        fatn *= i;
        fatn %= mod;
    }
    for(int i = 2; i <= n/2; i++){
        fatn2 *= i;
        fatn2 %= mod;
    }
    int t = fatn;
    t *= (modinv(fatn2));
    t %= mod;
    t *= (modinv(fatn2));
    t %= mod;
    cout << "Total: " << t << endl;
    t--;
}

signed main(){
#ifndef LOCAL_DEBUG   
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
