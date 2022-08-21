#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define endl '\n'

vi divs(int n){
    vi v;
    for(int i = 1; i <= n/2; i++){
        if(n % i == 0) v.push_back(i);
    }
    return v;
}

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vi di = divs(n);
    int db = INF;
    for(int i = 0; i < (int)di.size(); i++){
        ll soma = 0;
        int dr = 0;
        for(int j = 0; j < di[i]; j++){
            soma+=pow(s[j],2);
        }
        for(int j = di[i]; j < n; j+=di[i]){
            ll somat = 0;
            for(int k = j; k < j+di[i] && k < n; k++){
                somat+=pow(s[k],2);
            }
            if(somat != soma){
                dr++;
                break;
            }
        }
        if(!dr){
            db = di[i];
            break;
        }
    }
    cout << (db == INF ? "*" : s.substr(0, db)) << endl;
}

int main(){
    solve();
    return 0;
}

