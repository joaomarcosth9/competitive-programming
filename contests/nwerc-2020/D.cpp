#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const long long mx = 1e6+1;

void solve(){
    long long n; cin >> n;
    map<long long, long long> sq;
    for(long long i = 0; i <= mx; i++){
        sq[i * i] = i;
    }
    for(int i = 0; i < n; i++){
        cout << 0 << " " << 0 << endl;
        long long d; cin >> d;
        bool found = 0;
        if(d == 0){
            found = 1;
        }
        if(!found) for(long long x = 0; x <= mx; x++){
            long long ysq = d - (x * x);
            if(sq.count(ysq)){
                long long y = sq[ysq];
                if(y > 1e6) continue;
                assert(x <= 1e6);
                assert(y <= 1e6 && y >= 0);
                cout << x << " " << y << endl;
                long long res; cin >> res;
                if(res == 0){
                    found = 1;
                    break;
                }
                cout << y << " " << x << endl;
                cin >> res;
                if(res == 0){
                    found = 1;
                    break;
                }
            }
        }
        assert(found);
    }
}

signed main(){
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
