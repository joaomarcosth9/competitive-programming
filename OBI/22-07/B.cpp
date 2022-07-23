#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
const int MAX = 1e2+10;
int l,c;
ll M[MAX][MAX];
int mod = 31;

void solve(){
    cin >> l >> c;
    map<ll,int> Mp;
    map<int,set<int>> LC;
    map<int,set<int>> C;
    for(int i = 0; i < l+1; i++){
        for(int j = 0; j < c+1; j++){
            if(j == c && i == l) break;
            if(j < c && i < l){
                string s; cin >> s;
                int a = s[0];
                int b = s[1];
                M[i][j] = (int)a*pow(31,0)+(int)b*pow(31,1);
            } else {
                cin >> M[i][j];
            }
        }
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            L[i].insert(M[i][j]);
            C[j].insert(M[i][j]);
        } 
    }
    for(auto [k,v] : L){
        cout << "Linhas " << k << ": ";
        for(auto a : v) cout << a << ' ';
        cout << endl;
        if(v.size()==1){
            Mp[a] = 
        }
    }
    for(auto [k,v] : C){
        cout << "Colunas " << k << ": ";
        for(auto a : v) cout << a << ' ';
        cout << endl;
    }
}

int main(){ _
    solve();
    return 0;
}
