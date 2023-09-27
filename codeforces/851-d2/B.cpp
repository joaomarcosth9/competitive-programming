#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 1;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

int sumd(int n){
    ll sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int test(int n, int casa){
    while(casa){
        n /= 10;
        casa--;
    }
    return (n % 10) == 0;
}

void solve(){
    int n; cin >> n;
    if(n & 1){
        if(abs(sumd((n >> 1) + 1) - sumd(n >> 1)) <= 1){
            cout << (n >> 1) + 1 << " " << (n >> 1) << endl;
        } else {
            int a = pow(10, (int)log10(n));
            int b = n - a;
            int c = 0;
            while(abs(sumd(a) - sumd(b)) > 1){
                a += pow(10, c);
                b -= pow(10, c);
                if(test(b, c)){
                    c++;
                }
            }
            cout << a << " " << b << endl;
        }
    } else {
        cout << (n >> 1) << " " << (n >> 1) << endl;
    }
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
