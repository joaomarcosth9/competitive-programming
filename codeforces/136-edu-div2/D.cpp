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

const int MAX = 2.1e5;
int n, k;
int pai[MAX];
vi chi[MAX];
int levels[MAX];

void dfs(int u, int l){
    levels[l]++;
    for(auto v : chi[u]){
        dfs(v, l+1);
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i <= n+5; i++) { pai[i] = -1; chi[i].clear(); }
    for(int i = 2; i <= n; i++){
        int a; cin >> a;
        pai[i] = a;
        chi[a].pb(i);
    }
    dfs(1, 0);
    int res = INT_MAX;
    for(int i = n; i >= 0; i--){
        if(k >= levels[i]){
            k -= levels[i];
        } else {
            res = min(res, i);
            break;
        }
    }
    cout << res << endl;
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
