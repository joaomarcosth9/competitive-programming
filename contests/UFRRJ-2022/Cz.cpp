#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

vector<long long> z_function(vector<long long> s) {
    int n = (int) s.size();
    vector<long long> z(n);
    for (long long i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

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

    v.erase(v.begin());
    sq.erase(sq.begin());

    debug(v);
    debug(sq);

    vector<long long> nw;
    for(auto u : sq) nw.push_back(u);
    nw.push_back(2e17);
    for(auto u : v) nw.push_back(u);

    vector<long long> res = z_function(nw);
    int ress = 0;

    debug(res);

    for(auto u : res){
        if(u == (int)sq.size()) ress++;
    }
    cout << ress << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
