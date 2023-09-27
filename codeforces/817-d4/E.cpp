#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;

typedef tuple<ll,ll,ll,ll> l4;

void solve(){
    int n, q; cin >> n >> q;
    vector<pair<ll,ll>> v(n);
    vector<vector<ll>> pref(1002, vector<ll> (1002));
    vector<vector<ll>> s(1002, vector<ll> (1002));
    for(int i = 0; i < n; i++){
        auto& [a,b] = v[i];
        cin >> a >> b;
        s[a][b] += a * b;
    }
    for(int i = 1; i < 1002; i++){
        for(int j = 1; j < 1002; j++){
            pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+s[i][j];
        }
    }
    for(int i = 0; i < q; i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a = min(a, c);
        b = min(b, d);
        cout << pref[c-1][d-1]-pref[c-1][b]-pref[a][d-1]+pref[a][b] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}

