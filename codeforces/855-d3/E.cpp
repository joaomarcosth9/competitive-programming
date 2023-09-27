#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 1;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    map<char, int> fs, ft;
    for(int i = 0; i < n; i++){
        fs[s[i]]++, ft[t[i]]++;
    }
    if(fs != ft){
        cout << "NO" << endl;
        return;
    } else if (k < ((n+1)>>1)){
        cout << "YES" << endl;
        return;
    }


    // k + 1 > (n+1 / 2)

    for(int i = n-k; i < k; i++){
        if(s[i] != t[i]){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}

