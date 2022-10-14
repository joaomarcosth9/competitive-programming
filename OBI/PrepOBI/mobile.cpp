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
#ifdef LOCAL_DEBUG   
#define endl '\n'
#   define _   
#else
#   define _ ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const int MAX = 2e5;
int n; 
vector<int> adj[MAX];
int dr = 0;

int dfs(int u, int sum){
    if(dr) return -1;
    int started = 0;
    int last = -1;
    sum = adj[u].size();
    for(auto v : adj[u]){
        int thissum = dfs(v, 0);
        if(started && last != thissum){
            dr++;
            return -1;
        }
        started = 1;
        last = thissum;
        sum += thissum;
    }
    return sum;
}

void solve(){
    cin >> n;
    int root = -1;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        if(b == 0){
            root = max(a,b);
            continue;
        }
        adj[b].pb(a);
    }
    dfs(root, 0);
    cout << (dr ? "mal" : "bem") << endl;
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
