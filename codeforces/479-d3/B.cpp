#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int n; string s; cin >> n >> s;
    map<string,int> Freq;
    pair<string,int> res = {"..",0};
    for(int i = 0; i < (int)s.size()-1; i++){
        string tg;
        tg.push_back(s[i]);
        tg.push_back(s[i+1]);
        Freq[tg]++;
        if(Freq[tg] > res.second){
            res = {tg,Freq[tg]};
        }
    }
    cout << res.first << endl;
}

int main(){ _
    solve();
    return 0;
}
