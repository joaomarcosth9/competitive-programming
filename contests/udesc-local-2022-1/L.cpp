#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    long long n, m, c, d; cin >> n >> m >> c >> d;
    vector<pair<long long, long long>> seg;
    for(int i = 0; i < m; i++){
        long long a, b; cin >> a >> b;
        seg.emplace_back(a, b);
    }
    auto test = [&] (long long val){
        long long f = c, curr = val*d;
        db(f, curr);
        for(int i = 0; i < m; i++){
            auto [l, r] = seg[i];
            db(l, r, curr, f);
            if(r-l > curr){
                f--;
                curr = val*d;
                if(f == 0){
                    return 0;
                }
                i--; continue;
            }
            curr -= r-l;
        }
        return 1;
    };
    long long l = 1, r = n;
    long long res = -1;
    while(l <= r){
        long long mid = l+(r-l)/2;
        db(mid, test(mid));
        if(test(mid)){
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    assert(res != -1);
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
