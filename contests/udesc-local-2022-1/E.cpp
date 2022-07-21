#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    double n; cin >> n;
    n *= 10;
    int aaa = round(n);
    // mf = (ms*6 + ne*4)/10
    // 5.0 = (ms*6 + ne*4)/10
    // 50 = (ms*6 + ne*4)
    // (50 - 6*ms)4 = ne
    double ne = (500-6*aaa)/4;
    cout << setprecision(1) << fixed;
    cout << ne/10 << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
