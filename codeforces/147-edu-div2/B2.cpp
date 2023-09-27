#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> a(n), as(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> as[i];
    }
    int first = 1;
    for(int i = 0; i < n; i++){
        if(a[i] != as[i]){
            first = i+1;
            break;
        }
    }
    /* db(first); */
    /* if(first == -1){ */
    /*     int curr = 1; */
    /*     int best = 1; */
    /*     int st = 1, en = 1; */
    /*     int cst = 1; */
    /*     for(int i = 1; i < n; i++){ */
    /*         if(as[i] >= as[i-1]){ */
    /*             curr++; */
    /*             if(curr > best){ */
    /*                 st = cst, en = i+1; */
    /*                 best = curr; */
    /*             } */
    /*         } else { */
    /*             curr = 1; */
    /*             cst = i+1; */
    /*         } */
    /*     } */
    /*     cout << st << " " << en << '\n'; */
    /*     return; */
    /* } */
    int last = n;
    for(int i = n-1; i >= 0; i--){
        if(a[i] != as[i]){
            last = i+1;
            break;
        }
    }
    for(int i = first-1; i >= 0; i--){
        if(as[i] == a[i] && as[i+1] >= as[i]){
            first = i+1;
        } else break;
    }
    for(int i = last+1; i < n; i++){
        if(as[i] == a[i] && as[i] >= as[i-1]){
            last = i+1;
        } else break;
    }
    cout << first << " " << last << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
