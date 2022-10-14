#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int n, q;

void solve(){
    cin >> n >> q;
    vi v(n);
    vi qq(q);
    FO(n) cin >> v[i];
    FO(q) cin >> qq[i];

    vi pref(n);
    vi prefsum(n);
    pref[0] = v[0];
    prefsum[0] = v[0];
    for(int i = 1; i < n; i++) pref[i] = max(v[i], pref[i-1]);
    for(int i = 1; i < n; i++) prefsum[i] = v[i]+prefsum[i-1];

    for(int i = 0; i < q; i++){
        int leg = qq[i];
        int res = -1;
        if(leg != 0){
            auto upper = upper_bound(pref.begin(), pref.end(), leg);
            res = upper - pref.begin() - 1;
        }
        cout << (res != -1 ? prefsum[res] : 0) << ' ';
    }
    cout << endl;
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
