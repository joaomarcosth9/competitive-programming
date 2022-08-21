#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int s; cin >> s;
    int res = 0;
    for(int i = 9; i > 0; i--){
        if(res+i >= s){
            cout << s-res;
            for(int j = i+1; j <= 9; j++) cout << j;
            cout << endl;
            return;
        }
        res+=i;
    }
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}

