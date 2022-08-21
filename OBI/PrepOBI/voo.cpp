#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int dia = 24*60;
    vector<int> V(4);
    for(auto& t : V) {
        char c;
        int a,b; cin >> a >> c >> b;
        t = a*60+b;
    }
    vector<int> Id;
    vector<int> Vl;
    for(int i = -12; i <= 12; i++){
        int ii = -i;
        int df = i*60;
        int dff = ii*60;
        int d1 = (((V[1] - df - V[0]))+dia)%dia;
        int d2 = (((V[3] - dff - V[2]))+dia)%dia;
        if(d1 == d2 && d1 < 720){
            cout << d1 << ' ' << (i == -12 ? 12 : i) << endl;
            break;
        }
    }
}

int main(){ _
    solve();
    return 0;
}
