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
#define double long double

int n;

double ternarysearch(double l, double r, vector<int>& x, vector<int>& t){
    double delta = 1e-7;
    while(r - l > delta){
        double m1 = l + (r-l) / 3;
        double m2 = r - (r-l) / 3;

        double f1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            f1 = max(f1, abs((double)x[i]-m1) + t[i]); 
        } 
        double f2 = INT_MIN;
        for (int i = 0; i < n; i++) {
            f2 = max(f2, abs((double)x[i]-m2) + t[i]); 
        }
        if(f2 < f1){
            l = m1;
        } else {
            r = m2;
        }
    }
    return l;
}

void solve(){
    cin >> n;
    vi x(n);
    vi t(n);
    int tudozero = 1;
    int tudoigual = 1;
    FO(n){
        int xx; cin >> xx;
        x[i] = xx;
        tudoigual &= (xx == x[0]);
    }
    FO(n){
        int tt; cin >> tt;
        tudozero &= (!tt);
        t[i] = tt;
    }
    if(n == 1 || tudoigual){
        cout << x[0] << endl;
        return;
    }
    double l = 0, r = 1e8;
    cout << setprecision(10) << fixed << ternarysearch(l, r, x, t) << endl;
}

int main(){
#ifndef LOCAL_DEBUG   
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        solve();
    }
    return 0;
}
