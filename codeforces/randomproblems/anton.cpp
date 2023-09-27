#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int fa = 0, fd = 0;
    for(char c : s){
        fa += c == 'A';
        fd += c != 'A';
    }
    if(fa == fd){
        cout << "Friendship" << endl;
    } else {
        cout << (fa > fd ? "Anton" : "Danik") << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
