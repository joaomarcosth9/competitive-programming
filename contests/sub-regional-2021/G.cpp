#include <bits/stdc++.h>
using namespace std;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

#define fibs 90

ll fib[fibs];

vector<ll> ft;

ll fibn(ll n, ll it){
    ll res = -1;
    for(int i = it; i < fibs; i++, it++){
        if(n % fib[i] == 0){
            if(n / fib[i] == 1){
                ft.emplace_back(fib[i]);
                return fib[i];
            } else {
                ll db = fibn(n/fib[i], it);
                if(db != -1){
                    ft.emplace_back(fib[i]);
                    return fib[i];
                }
            }
        }
    }
    return res;
}

void solve(){
    ll n; cin >> n;
    ll res = fibn(n, 1);
    sort(rbegin(ft), rend(ft));
    reverse(begin(fib), end(fib));
    if(ft.size()){
        for(int i = 0; i < (int)ft.size(); i++){
            ll num = (lower_bound(begin(fib), end(fib), ft[i]) - fib)+1;
            while(num-- > 0) cout << "A";
            cout << "B";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
} 

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    fib[0] = 2LL;
    fib[1] = 3LL;
    for(int i = 2; i < fibs; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    sort(rbegin(fib), rend(fib));
    solve();
    return 0;
}
