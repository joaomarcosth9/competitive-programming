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
#define int ll
#define db(x...)
#define dbarr(x...)
#endif

const int mod = 998244353;

void solve(ll l, ll r){
    ll sz = 0;
    ll pw = 2;
    ll lt = l;
    ll fst = 0;
    ll maxpw = 2;
    while(lt <= r){
        maxpw = max(maxpw, pw);
        lt = l * pw;
        pw <<= 1;
        fst++;
    }
    maxpw >>= 1;
    cout << fst << " ";
    ll oth = 0;
    int first = l;
    int last = l;
    int oldr = r;
    db(maxpw);
    db(l, r);
    db(last, oldr);
    int mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(mid * maxpw > oldr){
            r = mid-1;
        } else {
            l = mid+1;
            last = mid;
        }
    }
    db(first, last);
    oth += last-first+1;
    l = first, r = last;
    last = first-1;
    while(l <= r){
        mid = (l + r) >> 1;
        int ult = mid * maxpw;
        ult >>= 1;
        ult *= 3;
        if(ult > oldr){
            r = mid-1;
        } else {
            l = mid+1;
            last = mid;
        }
    }
    oth += (fst-1)*(last-first+1);
    oth %= mod;
    cout << oth << endl;
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--){
        ll l, r; cin >> l >> r;
        solve(l, r);
    }
    return 0;
}
