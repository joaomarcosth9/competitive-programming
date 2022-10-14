#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
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
#define FOR(i,x,y) for(int i = x; i < y; i++)
#define ROF(i,x,y) for(int i = x-1; i >= y; i--)
#define FO(x) FOR(i,0,x)
#define OF(x) ROF(i,x,0)
#define endl '\n'

void solve(){
    vector<vector<char>> v(8, vector<char>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> v[i][j];
        }
    }
    int db = 0;
    char res = 0;
    for(int i = 0; i < 8; i++){
        char lc;
        if(v[i][0] == 'R') db = 1, lc = 'R';
        else continue;
        for(int j = 0; j < 8; j++){
            db &= (v[i][j] == 'R');
        }
        if(db){
            res = 'R';
            break;
        }
    }
    if(db == 0){
        for(int i = 0; i < 8; i++){
            char lc;
            db = 1;
            if(v[0][i] == 'B') db = 1, lc = 'B';
            else continue;
            for(int j = 0; j < 8; j++){
                db &= (v[j][i] == 'B');
            }
            if(db){
                res = 'B';
                break;
            }
        }
    }
    cout << res << endl;
}

int main(){
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* cout << "test: " << Testcase << endl; */
        solve();
    }
    return 0;
}
