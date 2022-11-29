#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, w; cin >> n >> w;
    vector<long long> tempv(n), v(n), tempsq(w), sq(w);
    for(auto& a : tempv) cin >> a;
    for(auto& a : tempsq) cin >> a;
    for(int i = 1; i < n; i++){
        v[i] = tempv[i] - tempv[i-1];
    }
    for(int i = 1; i < w; i++){
        sq[i] = tempsq[i] - tempsq[i-1];
    }
    for(auto& a : v) cout << a << ' ';
    cout << endl;
    for(auto& a : sq) cout << a << ' ';
    cout << endl;

    long long P = 257, MOD = 1'000'000'007, H = 0, CH = 0, exp = 1;
    for(int i = w-1; i > 0; i--){
        H += (sq[i] * exp) % MOD;
        exp *= P;
        /* exp %= MOD; */
    }
    exp = 1;
    for(int i = w-1; i > 0; i--){
        CH += (v[i] * exp) % MOD;
        exp *= P;
        /* exp %= MOD; */
    }
    cout << "Expoente " << exp << endl;
    cout << H << ' ' << CH << endl;
    int res = 0;
    res += CH == H;
    w--;
    for(int i = 2; i <= n-w; i++){
        CH *= P;
        cout << i << ": " << H << ' ' << CH << endl;
        cout << "Tirando " << v[i-1] << endl;
        CH -= (exp) * v[i-1];
        cout << "Botando " << v[i+w-1] << endl;
        CH += v[i+w-1];
        CH %= MOD;
        if(CH < 0) CH += MOD;
        cout << i << ".1: " << H << ' ' << CH << endl;
        res += CH == H;
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
