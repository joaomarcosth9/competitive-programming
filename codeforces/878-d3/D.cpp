#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(begin(a), end(a));
    /* vector<int> pref(n + 1); */
    /* for(int i = 1; i <= n; i++){ */
    /*     pref[i] = pref[i - 1] + a[i - 1]; */
    /* } */
    /* auto query = [&] (int l, int r){ */
    /*     if(l > r) return 0ll; */
    /*     if(l < 0 || r >= n) return 0ll; */
    /*     return pref[r + 1] - pref[l]; */
    /* }; */

    int res = INT_MAX;
    debug(a);

    auto test = [&] (int val) {
        bool ans = 1;
        int last = a[0];
        int troca = 0;
        debug(val);

        for(int i = 0; i < n; i++){
            int time = (a[i] - last + 1) / 2;
            debug(i, time);
            if(time <= val) continue;
            last = a[i];
            troca++;
        }

        debug(troca);

        return troca < 3;
        debug("FIM");
    };

    int L = 0, R = a.back() - a[0];
    int ans = INT_MAX;

    test(12);
    
    while(L <= R){
        int mid = (L + R) / 2;
        if(test(mid)){
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans << '\n';

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
