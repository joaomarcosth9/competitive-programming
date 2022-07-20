#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;

int n, final[MAX];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> final[i];
    for(int i = 0; i < n; i++){
        int nn; cin >> nn;
        for(int j = 0; j < nn; j++){
            char op; cin >> op;
            if(op == 'D'){
                final[i]++;
                if(final[i] == 10) final[i] = 0;
            } else {
                final[i]--;
                if(final[i] == -1) final[i] = 9;
            }
        } 
    }
    for(int i = 0; i < n; i++) cout << final[i] << ' ';
    cout << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
