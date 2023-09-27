#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k, x; cin >> n >> k >> x;
    if(x != 1){
        cout << "YES" << '\n';
        cout << n << '\n';
        for(int i = 0; i < n; i++) cout << 1 << " ";
        cout << '\n';
    } else {
        // x == 1
        if(k == 1){
            cout << "NO" << '\n';
        } else if (k == 2){
            if(n % 2 == 0){
                cout << "YES" << '\n';
                cout << n / 2 << '\n';
                for(int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cout << "YES" << '\n';
            if(n % 2 == 0){
                cout << n / 2 << '\n';
                for(int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << '\n';
            } else {
                n -= 3;
                int dois = n / 2;
                cout << 1 + dois << " ";
                cout << 3 << ' ';
                for(int i = 0; i < dois; i++) cout << 2 << " ";
                cout << '\n';
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
