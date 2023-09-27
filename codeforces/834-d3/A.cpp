#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;
string yes;

void solve(){
    string s; cin >> s;
    char f = s[0];
    int i;
    for(i = 0; i < 3; i++){
        if(yes[i] == f){
            break;
        }
    }
    int db = 1;
    for(char c : s){
        db &= c == yes[i++];
    }
    cout << (db ? "YES" : "NO") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    int a = 50;
    while(a--){
        yes.push_back('Y');
        yes.push_back('e');
        yes.push_back('s');
    }
    if(temtestcase) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
