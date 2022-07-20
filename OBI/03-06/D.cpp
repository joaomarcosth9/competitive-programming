#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s, an;
    cin >> s >> an;
    int size = s.size();
    map<char, int> S;
    map<char, int> An;
    int nc = 0;
    for (int i = 0; i < size; i++){ 
        S[s[i]]++;
        An[an[i]]++;
        if (an[i] == '*'){
            nc++;
        }
    }
    int difs = 0;
    map<char, int> Visit;
    for (int i = 0; i < size; i++){
        if (Visit[s[i]] == 1){
            continue;
        }
            Visit[s[i]] = 1;
        if(S[s[i]] < An[s[i]]){
            cout << 'N' << '\n';
            return;
        } else if (S[s[i]] > An[s[i]]){
            difs+= abs(S[s[i]]-An[s[i]]);
        }
    }
    if (difs == nc){
        cout << 'S' << '\n';
    } else {
        cout << 'N' << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
