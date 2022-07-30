#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int n, c; cin >> n >> c;
    map<int, priority_queue<int, vector<int>, greater<int>>> M;
    vector<int> O(n+1);
    vector<int> V(n+1);
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        M[b].push(a);
        O[i] = b;
    }
    for(int i = 1; i <= n; i++){
        V[i] = M[O[i]].top();
        M[O[i]].pop();
        if(V[i] < V[i-1]){
            cout << 'N' << endl;
            return;
        }
    }
    cout << 'Y' << endl;
}

int main(){ _
    //int tstcs; cin >> tstcs; while(tstcs--) solve();
    solve();
    return 0;
}


