#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<int> X(n), C(n);
    for(int i = 0; i < k; i++){
        cin >> X[i];
    }
    for(int i = 0; i < k; i++){
        cin >> C[i];
    }

    for(int i = 0; i < k; i++){
        if((X[i] <= 3 && C[i] != X[i]) || C[i] > X[i] || (i >= 1 && (C[i] < C[i-1] || C[i] - C[i-1] > X[i] - X[i-1]))){
            cout << "NO" << '\n';
            return;
        }
    }

    if(n == 1){
        cout << "a" << '\n';
        return;
    } else if(n == 2){
        cout << "ab" << '\n';
        return;
    }

    string s = "abc";

    char f = 'd';

    int curr = 3, last = 3;
    int index = 0;

    for(int idx = 0; idx < k; idx++){
        auto x = X[idx], c = C[idx];
        if(x <= 3) continue;

        int add = c - curr;

        for(int i = last+1; i <= x-add; i++){
            s += "abc"[index++ % 3];
        }
        while(add--){
            s += f;
        }

        last = x;
        curr = c;
        f++;

    }

    cout << "YES" << '\n';
    cout << s << '\n';

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
