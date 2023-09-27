#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; string s; cin >> n >> s;
    int res = 0;
    for(int i = 0; i < n; i++){
        vector<int> fq(10);
        int maxx = 0, dif = 0;
        for(int j = 0; j < 100; j++){
            if(i + j == n) break;
            int k = j + i;
            int c = s[k] - '0';
            if(!fq[c]) dif++;
            fq[c]++;
            maxx = max(fq[c], maxx);
            if(maxx > 10) break;
            res += (dif >= maxx);
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
