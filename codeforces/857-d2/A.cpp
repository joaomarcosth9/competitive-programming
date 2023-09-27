#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    map<int,bool> fq;
    for(auto& a : v) {
        cin >> a;
        fq[a] = 1;
    }
    vector<int> v2;
    sort(rbegin(v), rend(v));
    int f = 0;
    for(int i = 0, j = 1; i < n; i++){
        if(v[i] > 0) cout << j++ << " ";
        else {
            if(f == 0) f = 1, j--;
            cout << --j << " ";
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        if(fq[i] && fq[-i]){
            v2.push_back(i);
            v2.push_back(-i);
        }
    }
    for(int i = 1; i <= n; i++){
        if(fq[i] && !fq[-i]){
            v2.push_back(i);
        }
    }
    for(int i = 0, j = 1; i < n; i++){
        if(i < n-1 && v2[i+1] < 0){
            cout << 1 << " ";
        } else if(v2[i] < 0){
            cout << 0 << " ";
        } else {
            cout << j++ << " ";
        }
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
