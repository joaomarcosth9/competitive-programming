#include <bits/stdc++.h>
using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<int,int>;
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
#define FOR(x,y) for(int i = x; i < y; i++)
#define ROF(x,y) for(int i = x; i >= y; i--)
#define FO(x) FOR(0,x)
#define OF(x) ROF(x,0)
#define endl '\n'
#ifdef LOCAL_DEBUG   
#   define _   
#else
#   define _ ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const int MAX = 1e5+500;
int n,m;
int diametro = INF;
vi adj[MAX];
/* int vis[MAX]; */
int pai[MAX];
int dis[MAX];

void dfs(int u, int p, int l){
    pai[u] = p;
    dis[u] = l;
    for(auto v : adj[u]){
        if(v != p) dfs(v, u, l+1);
    }
}

void solve(){
    cin >> n >> m;
    FOR(1,n){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 0, 1);
    int p1 = 0;
    FOR(1,n+1){
        if(dis[i] > dis[p1]) p1 = i;
    }
    dfs(p1, 0, 1);
    int p2 = 0;
    FOR(1,n+1){
        if(dis[i] > dis[p2]) p2 = i;
    }
    vi path;
    int cara = p2;
    while(cara != 0){
        path.pb(cara);
        cara = pai[cara];
    }

    int centro1 = path[path.size() >> 1];

    FOR(0, n+1){
        adj[i].clear();
    }
    path.clear();
    p1 = 0;
    p2 = 0;

    FOR(1,m){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0, 1);
    FOR(1,m+1){
        if(dis[i] > dis[p1]) p1 = i;
    }
    dfs(p1, 0, 1);
    FOR(1,m+1){
        if(dis[i] > dis[p2]) p2 = i;
    }
    cara = p2;
    while(cara != 0){
        path.pb(cara);
        cara = pai[cara];
    }

    int centro2 = path[path.size() >> 1];

    cout << centro1 << ' ' << centro2 << endl;
}

int main(){ _
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
