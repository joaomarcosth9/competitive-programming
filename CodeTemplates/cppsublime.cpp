#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve(){
}

signed main(){
#ifdef SUBLIME
    freopen("/inp-out/input.txt", "r", stdin);
    freopen("/inp-out/output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
