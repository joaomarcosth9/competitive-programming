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

int LCSubStr(string s, string t, int n, int m) {
   
    // Create DP table
    vector<vector<int>> dp(2, vector<int> (m+1));
    int res = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                if (dp[i % 2][j] > res)
                    res = dp[i % 2][j];
            }
            else
                dp[i % 2][j] = 0;
        }
    }
    return res;
}

void solve(){
    string a, b; cin >> a >> b;
    vector<int> fa(26), fb(26);
    int m = a.size();
    int n = b.size();
    int lo = LCSubStr(a, b, m, n);
    int ida = -1;
    db(m, n, lo);
    if(lo == 0){
        cout << "NO" << endl;
        return;
    }
    if(lo == 1){
        if(a[0] == b[0]){
            cout << "YES" << endl;
            cout << a[0];
            cout << "*" << endl;
        } else if(a[m-1] == b[n-1]){
            cout << "YES" << endl;
            cout << "*";
            cout << a[m-1] << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    for(int i = 0; i < m; i++){
        bool db = 0;
        /* db(i); */
        if(i + lo > m) break;
        for(int j = 0; j < n; j++){
            db = 1;
            /* db(i, j); */
            if(j + lo > n) {
                db = 0;
                break;
            }
            for(int k = 0; k < lo; k++){
                db &= a[i+k] == b[j+k];
            }
            if(db){
                ida = i;
            }
        }
    }

    cout << "YES" << endl;
    cout << "*";
    for(int i = ida; i < ida+lo; i++) cout << a[i];
    cout << "*" << endl;
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
