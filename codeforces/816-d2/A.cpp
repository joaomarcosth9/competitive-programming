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
    int n, m; cin >> n >> m;
    cout << (n == 1 && m == 1 ? 0 : n+m-1 + (min(n,m))-1) << endl;
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}

