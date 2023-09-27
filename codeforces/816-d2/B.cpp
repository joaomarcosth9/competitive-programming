#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define endl '\n'

void solve(){
    ll n,k,b,s; cin >> n >> k >> b >> s;
    if(s/k < b || (s-(n-1)*(k-1))/k > b || (n == 1 && (s/k != b))){
        cout << -1 << endl;
    } else {
        vector<ll> res(n);
        res[n-1] = s;
        int j = n-2;
        while(res[n-1]/k != b){
            if(res[n-1] > b){
                res[n-1] -= k-1;
                res[j] = k-1;
                j--;
            } else {
                res[n-1]++;
                res[j]--;
            }
        }
        for(int i = 0; i < n; i++) cout << res[i] << " \n"[i == n-1];
    }
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        clog << db(Testcase) << endl;
        solve();
    }
    return 0;
}

