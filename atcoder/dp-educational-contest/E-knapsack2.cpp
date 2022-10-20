#include <bits/stdc++.h>
using namespace std;
int temtestcase = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

vector<pair<ll,ll>> vw;

const int maxn = 1e2+5;
const int maxv = 1e3+5;

ll dp[maxn][maxv];

ll N, W;

void solve(){
    cin >> N >> W;
    for(int i = 0; i <= N; i++) for(int j = 0; j <= maxv; j++){
        dp[i][j] = -1;
    }
    vw.emplace_back(0LL, 0LL);
    for(int i = 0; i < N; i++){
        int w1, v1; cin >> w1 >> v1;
        vw.emplace_back(v1,w1);
    }
    sort(begin(vw), end(vw));

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= 1e3; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if(w[i] > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j - w[i]]);
            }
        }
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
