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
#define eb emplace_backond
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii; 
const int MAX = 10;

int l,c,p,nb;

int g[MAX][MAX];

void solve(){
    cin >> l >> c >> p;
    for(int i = 0; i < p; i++){
        int a,b; cin >> a >> b;
        g[a][b] = 1;
    }
}

int main(){ _
    solve();
    return 0;
}
