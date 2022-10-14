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
int diametroq = INF, diametroc = INF;
int resq = -1, resc = -1;
vi adjq[MAX];
vi adjc[MAX];

int vis[MAX];
int paiq[MAX];
int paic[MAX];

ii maxl = {-1,-1};

void dfsq(int u, int l){
    if(maxl.fst < l){
        maxl.fst = l;
        maxl.snd = u;
    }
    vis[u]++;
    for(auto v : adjq[u]){
        if(!vis[v]){
            paiq[v] = u;
            dfsq(v, l+1);
        }
    }
}

void dfsc(int u, int l){
    if(maxl.fst < l){
        maxl.fst = l;
        maxl.snd = u;
    }
    vis[u]++;
    for(auto v : adjc[u]){
        if(!vis[v]){
            paic[v] = u;
            dfsc(v, l+1);
        }
    }
}

void dfsq2(int u, int l){
    if(diametroq % 2){
        if(l == diametroq/2+1){
            resq = u;
        }
    } else {
        if(l == diametroq/2){
            resq = max(resq,u);
        }
    }
    vis[u]++;
    for(auto v : adjq[u]){
        if(!vis[v]) dfsq2(v, l+1);
    }
}

void dfsc2(int u, int l){
    if(diametroc % 2){
        if(l == diametroc/2+1){
            resc = u;
        }
    } else {
        if(l == diametroc/2){
            resc = max(resc,u);
        }
    }
    vis[u]++;
    for(auto v : adjc[u]){
        if(!vis[v]) dfsc2(v, l+1);
    }
}

void solve(){
    cin >> n >> m;
    FOR(1,n) {
        int a,b; cin >> a >> b;
        adjq[a].pb(b);
        adjq[b].pb(a);
    }
    FOR(1,m) {
        int a,b; cin >> a >> b;
        adjc[a].pb(b);
        adjc[b].pb(a);
    }
    dfsq(1,1);
    maxl.fst = -1;
    int ponta1q = maxl.snd;
    FO(MAX) vis[i] = 0;
    dfsq(maxl.snd,1);
    diametroq = maxl.fst;
    maxl.fst = -1;
    int ponta2q = maxl.snd;
    
    dfsc(1,1);
    FO(MAX) vis[i] = 0;
    int ponta1c = maxl.snd;
    maxl.fst = -1;
    FO(MAX) vis[i] = 0;
    dfsc(maxl.snd,1);
    diametroc = maxl.fst;
    int ponta2c = maxl.snd;

    /* FO(MAX) vis[i] = 0; */
    /* dfsq2(ponta1q, 1); */
    /* FO(MAX) vis[i] = 0; */
    /* dfsc2(ponta1c, 1); */
    if(diametroq % 2){
        int current = ponta2q;
        for(int i = 0; i <= diametroq/2+1; i++){
            current = paiq[current];
        }
    } else {
        int current = ponta2q;
        for(int i = 0; i <= diametroq/2; i++){
            current = paiq[current];
        }
    }

    if(diametroc % 2){
        int current = ponta2c;
        for(int i = 0; i <= diametroc/2+1; i++){
            current = paic[current];
        }
        resq = current;
    } else {
        int current = ponta2c;
        for(int i = 0; i <= diametroc/2; i++){
            current = paic[current];
        }
        resc = current;
    }

    cout << resq << ' ' << resc << endl;
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
