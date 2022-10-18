#include <bits/stdc++.h>
using namespace std;
int temtestcase = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

vector<ll> w;
vector<ll> v;

const int maxn = 1e2+5;
const int maxw = 1e5+5;

ll dp[maxn][maxw];

// recursive
ll dpp(ll n, ll cap){
    if(dp[n][cap] != -1) return dp[n][cap];
    if(n == 0 || cap == 0) return dp[n][cap] = 0;
    else if (w[n] > cap) return dp[n][cap] = dpp(n-1,cap);
    else return dp[n][cap] = max(dpp(n-1,cap), v[n]+dpp(n-1,cap-w[n]));
}

ll N, W;

void solve(){
    cin >> N >> W;
    for(int i = 0; i <= N; i++) for(int j = 0; j <= W; j++){
        dp[i][j] = -1;
    }
    w.push_back(0LL);
    v.push_back(0LL);
    for(int i = 0; i < N; i++){
        int w1, v1; cin >> w1 >> v1;
        w.push_back(w1);
        v.push_back(v1);
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if(w[i] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j - w[i]]);
            }
        }
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << dp[N][W] << endl;
}

signed main(){
#ifdef LOCAL_DEBUG
    freopen("/tmp/input.txt", "r", stdin);
    freopen("/tmp/output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
    return 0;
}
