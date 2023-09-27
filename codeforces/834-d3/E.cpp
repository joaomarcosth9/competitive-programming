#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

const int MAX = 2.1e5;
int n, arr[MAX];

long long dpp(int i, long long h, int g, int b){
    if(i == n) return 0;
    if(g < 0 || b < 0) return -INFLL;
    if(arr[i] < h){
        return 1 + dpp(i+1, h + arr[i]/2, g, b);
    }
    return max(max(dpp(i, h * 2, g-1, b), dpp(i, h * 3, g, b-1)), 0LL);
}

void solve(){
    long long h; cin >> n >> h;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << dpp(0, h, 2, 1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
