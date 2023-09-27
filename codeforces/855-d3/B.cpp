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
    string s; cin >> s;
    int delta = 'A' - 'a';
    ll res = 0;
    /* db(s); */
    map<char, int> f;
    for(int i = 0; i < n; i++){
        f[s[i]]++;
    }
    for(char c = 'a'; c <= 'z'; c++){
        int m = f[c], M = f[c+delta];
        /* db(c); */
        /* db(m, M); */
        res += min(m, M);
        if(k){
            int plu = abs(m - M) >> 1;
            if(k >= plu){
                k -= plu;
                res += plu;
            } else {
                k = 0;
                res += k;
            }
        }
    }
    cout << res << endl;
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
