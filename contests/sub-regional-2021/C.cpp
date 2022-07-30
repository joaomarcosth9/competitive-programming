#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;

void solve(){
    int b, a; cin >> b >> a;
    int d = b+1;
    vector<int> N(a);
    vector<int> M(a, b);
    for(int i = 0; i < a; i++){
        cin >> N[i];
    }
    for(int i = a-1; i >= 0; i-=2){
        M[i] = 1;
    }
    int modn = 0;
    for(int i = 0; i < a; i++){
        modn += (N[i]*M[i])%d;
        modn %= d;
    }
    if(modn == 0){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    int d2 = d-modn;
    for(int i = 0; i < a; i++){
        if(M[i] == 1){
            if(N[i] >= modn){
                cout << i+1 << ' ' << N[i]-modn << endl;
                return;
            }
        } else if (M[i] == b) {
            if(N[i] >= d2){
                cout << i+1 << ' ' << N[i]-d2 << endl;
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << endl;
}

int main(){ _
    solve();
    return 0;
}
