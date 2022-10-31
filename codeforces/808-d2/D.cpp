#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5;

void solve(){
    int n; cin >> n;
    vector<int> v;
    int zeros = 0;
    for(int i = 0; i < n; i++){
        int nu; cin >> nu;
        if(nu) v.push_back(nu);
        else zeros++;
    }
    while ((int)v.size() > 1) {
        vector<int> temp;
        if (zeros) {
            temp.push_back(v[0]);
            zeros--;
        }
        for (int i = 1; i < (int)v.size(); i++) {
            int nu = v[i] - v[i-1];
            if (nu) temp.push_back(nu);
            else zeros++;
        }
        v = temp;
        sort(v.begin(), v.end());
    }
    cout << ((int)v.size() ? v[0] : 0) << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
