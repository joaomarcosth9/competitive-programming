#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+5, mod = 1e9+7;

struct SparseMax {
    ll m[20][maxn];
    int n;
	void build(int n2, ll* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i+1];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	ll query(int a, int b) {
        a--, b--;
        int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(m[j][a], m[j][b-(1<<j)+1]);
    }
};

struct SparseMin {
    ll m[20][maxn];
    int n;
	void build(int n2, ll* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i+1];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	ll query(int a, int b) {
        a--, b--;
        int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return min(m[j][a], m[j][b-(1<<j)+1]);
    }
};

ll dp[maxn], arr[maxn];
SparseMax stmax;
SparseMin stmin;

ll query(int i){
    ll ans = 0;
    for(; i > 0; i -= (i & -i)){
        ans = (ans + dp[i]) % mod;
    }
    return ans;
}

ll query(int l, int r){
    return (query(r) - query(l-1) + mod) % mod;
}

int n, l, r, k;

void update(int i, ll x){
    for(; i <= n; i += (i & -i)){
        dp[i] = (dp[i] + x) % mod;
    }
}


void solve(){
    cin >> n >> l >> r >> k;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    stmax.build(n, arr);
    stmin.build(n, arr);

    for(int i = 1; i <= n; i++){
        int L = i - r + 1;
        int R = i - l + 1;
        if(R < 1) continue;
        int ans = R+1;
        L = max(L, 1);
        int LL = L, RR = R;
        while(LL <= RR){
            int M = (LL + RR) / 2;
            ll maxx = stmax.query(M, i);
            ll minn = stmin.query(M, i);
            if(maxx - minn <= k){
                ans = M;
                RR = M-1;
            } else {
                LL = M+1;
            }
        }
        // somo sum(dp[ans-1], dp[R-1]);
        if(ans == 1){
            update(i, 1);
        }
        auto q = query(ans-1, R-1);
        update(i, q);
    }
    cout << query(n, n) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
