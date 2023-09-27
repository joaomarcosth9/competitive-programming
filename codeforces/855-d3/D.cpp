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
    int n; string s;
    cin >> n >> s;
    ll res = 1;
    map<pair<char,char>, int> f;
    db(s);
    db(s.substr(3, 2));
    vector<string> nova;
    for(int i = 0; i < n-2; i++){
        if(s[i] != s[i+2]){
            res++;
        }
    }
    /* for(int i = 1; i < n; i++){ */
    /*     nova.push_back(s.substr(i-1, 2)); */
    /* } */
    /* n = nova.size(); */
    /* db(nova); */
    /* for(int i = 1; i < n; i++){ */
    /*     if(nova[i] != nova[i-1]){ */
    /*         res++; */
    /*     } */
    /*     if(i > 1) if(nova[i-1][0] == nova[i][1]) res--; */
    /* } */
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
