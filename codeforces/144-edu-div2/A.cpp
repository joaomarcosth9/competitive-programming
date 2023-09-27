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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// FBFFBFFBFFFFFB
// mmc(3,5) = 15
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string res = "";
    for(int i = 1; i <= 15; i++){
        if((i % 3) == 0){
            res.push_back('F');
        }
        if((i % 5) == 0){
            res.push_back('B');
        }
    } 
    res += res + res;
    string bomba = s + "#" + res;
    auto bombastico = z_function(bomba);
    bool a = 0;
    for(auto i : bombastico){
        if(i == (int)s.size()) a = 1;
    }
    cout << (a ? "YES" : "NO") << endl;
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
