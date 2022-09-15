#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int n;

void solve(){
    cin >> n;    
    // A - F
    // B - D
    // C - E
    vector<vector<ii>> v(n);
    for(int i = 0; i < n; i++){
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        v[i].pb({a,f});
        v[i].pb({b,d});
        v[i].pb({c,e});
    }
    int res = 0;
    for(int i = 1; i <= 6; i++){
        int tres = 0;
        int nx = i;
        for(int j = 0; j < n; j++){
            int mx = 0;
            for(auto [a,b] : v[j]){
                if(a != nx && b != nx){
                    mx = max(mx,max(a,b));
                } else {
                    nx = (a == nx ? b : a);
                }
            }
            tres += mx;
        }
        res = max(res, tres);
    }
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
