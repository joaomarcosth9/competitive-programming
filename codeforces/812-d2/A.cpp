#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
int n;

void solve(){
    cin >> n;
    ll res = 0;
    vector<int> V(4);
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        if(x > 0) V[0] = max(V[0],abs(x));
        else if(x < 0) V[1] = max(V[1],abs(x));
        else if(y > 0) V[2] = max(V[2],abs(y));
        else if(y < 0) V[3] = max(V[3],abs(y));
    }
    res = (V[0]+V[1]+V[2]+V[3])*2;
    cout << res << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
