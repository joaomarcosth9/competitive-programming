#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 2e5 + 2;
const int INF = 1.05e9;
const int INFM = -1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
//vector<int> adj[MAX];

void solve(){
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(auto &u : v) cin >> u;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    /* for(auto &u : v) cout << u; */
    for(int i = 0; i < n-1; i++){
        if(v[i] > v[i+1]){
            if(x >= abs(v[i] - v[i+1]) * (i+1)){
                x -= abs(v[i] - v[i+1]) * (i+1);
            }else{
                int a = x/(i+1);
                cout << v[i] - a << endl;
                return;
            }
        }
    }
    int a = x/n;
    cout << max(0,v[n-1] - a) << endl;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool tttt = 0;
    if(tttt){
        int testcase; cin >> testcase;
        while (testcase--){
            solve();
        }
    }else solve();

    return 0;
}

