#include <bits/stdc++.h>
using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<int,int>;
template <typename T> using pql = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(rall(x)) 
#define pb push_back
#define eb emplace_back
#ifdef LOCAL_DEBUG   
#define endl '\n'
#   define _   
#else
#   define _ ios_base::sync_with_stdio(0);cin.tie(0);
#endif

void solve(){
    ll n,t; cin >> n >> t;
    if(t != 2){
        cout << (t ? n*(n-1) : n) << endl;
    } else {
        ll res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < i; j++){
                res += i - j - 1;
            }
        }
        cout << res << endl;
    }
}

int main(){ _
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
