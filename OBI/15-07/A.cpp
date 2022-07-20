#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

int n;
vector<vector<int>> V(5);

void solve(){
    cin >> n;
    for(int i = 0; i < 5; i++){
        V[i].push_back((i+1)%5);
        V[i].push_back((i+2)%5);
    }
    int d = 0, x =0;
    while(n--){
        int jd, jx;
        cin >> jd >> jx;
        for(int i = 0; i < 2; i++){
            if(V[jd][i] == jx){
                d++;
            } else if (V[jx][i] == jd){
                x++;
            }
        }
    }
    cout << (x>d?"xerxes":"dario") << endl;
}

int main(){ _
    solve();
    return 0;
}
