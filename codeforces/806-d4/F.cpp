#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5;

int arr[MAX];

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> V;
    map<int,int> M;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        if(arr[i] < i) V.push_back({i,arr[i]});
    }
    int res = 0;
    for(int k = 0; k < V.size(); k++){
        auto [i,v] = V[k];

        for(int l = i+1; l < 1e5; l++){
            M[l]++;
        }
        res += M[v];
    }
    cout << res << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
