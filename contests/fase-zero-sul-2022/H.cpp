#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using ull = unsigned long long;
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

ull ak(ull k){
    return 5 + 3*k;
}

ull sk(ull k){
    return (5 + ak(k)) * (k+1)/2;
}

void solve(){
    ull n; cin >> n;
    n -= 2;
    ull l = 1, r = 1e9;
    while( l < r ){
        ull k = l + (r-l)/2;
        if(sk(k) > n){
            r = k;
        } else {
            l = k+1;
        }
        /* cout << l << ' ' << r << ' '; */
        /* cout << sk(k) << endl; */
    }
    if( n < 5 ) l--;
    cout << (l + 1) << endl;
}

int main(){
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
