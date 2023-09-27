#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif


void solve(){
    vector<int> arr(4);
    for(int i = 1; i <= 3; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j != 0 && j == i) continue;
            for(int k = 0; k < 4; k++){
                if((k == i || k == j)) continue;
                if(arr[i] + arr[j] == arr[k]){
                    cout << "S" << endl;
                    return;
                }
            }
        }
    }
    cout << "N" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
