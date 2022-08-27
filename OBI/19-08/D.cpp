#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define endl '\n'

int n, m, k, p;
string s;
vector<string> v;

vi base(int nu, int base){
    vi conv;
    while(nu){
        conv.push_back(nu%base);
        nu /= base;
    }
    reverse(begin(conv), end(conv));
    return conv;
}

void solve(){
    cin >> n >> m >> k >> s;
    ll totalposs = 1;
    for(int i = 0; i < m; i++){
        string psps; cin >> psps;
        totalposs *= psps.size();
        v.push_back(psps);
    }
    cin >> p;
    if(k == 1){
        int i = 0;
        for(auto& c : s){
            if(c == '#'){
                c = v[i][0];
                i++;
            }
            cout << c;
        }
        cout << endl;
        return;
    }
    vi conv = base(p-1, k);
    vector<char> res;
    for(int i = 0; i < (int)v.size(); i++){
        res.push_back(v[i][conv[i]]);
    }
    int i = 0;
    for(auto& c : s){
        if(c == '#'){
            c = res[i];
            i++;
        }
        cout << c;
    }
    cout << endl;
}

int main(){
    solve();
    return 0;
}

