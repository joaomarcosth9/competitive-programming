#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    long long n, c; cin >> n >> c;
    vector<long long> v(n), first(n);
    vector<pair<int,int>> cost(n);
    for(auto& a : v) cin >> a;
    for(int i = 0; i < n; i++){
        first[i] = v[i] + i+1;
    }
    for(long long i = 0; i < n; i++){
        cost[i] = {v[i] + min(i+1, n-i), i};
    }
    sort(begin(cost), end(cost));

    vector<long long> pref(n+1);
    for(int i = 0; i < n; i++){
        pref[i+1] = pref[i] + cost[i].first;
    }

    vector<int> where(n);
    for(int i = 0; i < n; i++){
        where[cost[i].second] = i+1;
    }
    db(pref);
    int res = INT_MIN;
    auto test = [&] (int i){
        int temp = (first[i] <= c);
        int id = where[i];
        long long _cost = cost[id-1].first;
        int l = 1, r = n;
        int ans = 0;
        if(temp) while(l <= r){
            int mid = l + (r-l) / 2;
            long long val = pref[mid] - _cost * (mid >= id);
            if(val <= (c - first[i])){
                ans = mid - (mid >= id);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        temp += ans;
        return temp;
    };

    for(int i = 0; i < n; i++){
        res = max(res, test(i));
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

