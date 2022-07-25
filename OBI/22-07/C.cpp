#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;
string s;

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
    }

    vector<int> V;
    for(int i = 1; i <= n; i++){
        V.push_back(i);
    }

    for(int j = 1; j <= (1 << (int)V.size())-1; j++){
        for(int i = 1; i <= (int)V.size(); i++){
            if(((1 << (i-1)) & j)) cout << V[i-1];
        }
    }

    //for(int k = 1; k <= 7; k++){
    //    int i = k;
    //    int j = 0;
    //    while(j < (int)s.size()){
    //        if(i%2){
    //            cout << s[j];
    //            i = (i >> 1);
    //            j++;
    //        } else {
    //            i = (i >> 1);
    //            j++;
    //        }
    //    }
    //    cout << endl;
    //}
}

int main(){ _
    solve();
    return 0;
}
