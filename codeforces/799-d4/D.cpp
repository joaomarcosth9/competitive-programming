#include <bits/stdc++.h>

using namespace std;

int is_palindrome(int hora){
    int h,m;
    h = hora / 60;
    m = hora % 60;
    return ((h % 10) == (m / 10) && (h / 10) == (m % 10));
}

void solve(){
    string s; cin >> s;
    for(int i = 0; i < 5; i++){
        s[i] -= '0';
    }
    int gap; cin >> gap;
    int horas = (10*s[0]+s[1])*60 + (10*s[3]+s[4]);
    map<int,bool> vis;
    int res = 0;
    while(!vis[horas]){
        vis[horas] = true;

        res += is_palindrome(horas);

        horas += gap;
        horas %= (24*60);

    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
