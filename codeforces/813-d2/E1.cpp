#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;

int resolve(int n){
    int res = 0;
    int div = 0;
    for(int i = 1; i*i <= n; i++){
        div += (n % i == 0);
    }
    int fat2 = 1;
    int nn = n;
    while((nn & 1) == 0){
        fat2 *= 2;
        nn >>= 1;
    }
}

void solve(){
    int l, r; cin >> l >> r;
    for(int i = l; i <= r; i++){
        cout << resolve(i) << endl;
    }
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        solve();
    }
    return 0;
}

