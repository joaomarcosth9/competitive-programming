#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

const int maxn = 18;
const int maxx = 1 << 19;
int v[maxn];
long long dp[maxx][maxn];
int rule[maxn][maxn];

void solve(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < k; i++){
        int x, y, c; cin >> x >> y >> c;
        x--, y--;
        rule[x][y] = c;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < maxn; j++){
            dp[1 << i][j] = v[i];
        }
    }

    for(int mask = 1; mask < (1 << 19); mask++){
        for(int last = 0; last < n; last++){
            if(!(mask & (1 << last))) continue;
            for(int bit = 0; bit < 18; bit++){
                if(!(mask & (1 << bit))){
                    dp[mask | (1 << bit)][bit] = max(dp[mask | (1 << bit)][bit], dp[mask][last] + v[bit] + rule[last][bit]);
                }
            }
        }
    }

    long long res = 0;
    for(int mask = 1; mask < (1 << 19); mask++){
        if(__builtin_popcount(mask) == m){
            for(int last = 0; last < n; last++){
                res = max(res, dp[mask][last]);
            }
        }
    }
    
    cout << res << endl;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
