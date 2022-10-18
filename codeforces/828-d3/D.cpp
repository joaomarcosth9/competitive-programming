#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long

void solve(){
    int n, nop = 0; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int c = 0;
    ll pot2 = (1LL << 40);
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++){
        c += log2((__gcd((ll)v[i], pot2)));
        pq.push(log2((__gcd((ll)i+1, pot2))));
    }
    int falta = max(n - c, 0LL);
    while(falta > 0 && !pq.empty()){
        falta -= pq.top(), nop++;
        pq.pop();
    }
    cout << (falta > 0 ? -1 : nop) << endl;
}

signed main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
