#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define endl '\n'
const int MAX = 1e2+10;

int l,c;
ll M[MAX][MAX];
ll values[MAX];
int solved = 0;
map<int,int> sol;
int var = 1;

void solve(){
    cin >> l >> c;
    map<string,int> sti;
    map<int,string> its;
    for(int i = 0; i <= l; i++){
        for(int j = 0; j <= c; j++){
            if(j == c && i == l) break;
            if(j < c && i < l){
                string s; cin >> s;
                if(!sti[s]){
                    sti[s] = var;
                    its[var] = s;
                    var++;
                }
                M[i][j] = sti[s];
            } else {
                cin >> M[i][j];
            }
        }
    }
    var--;
    while(solved < var){
        map<int,set<int>> linhas;
        map<int,set<int>> colunas;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                if(!sol[M[i][j]]){
                    linhas[i].insert(M[i][j]);
                    colunas[j].insert(M[i][j]);
                }
            }
        }
        for(auto [k,s] : linhas){
            /* cout << "Linha: " << k << ' ' << s.size() << '\n'; */
            if(s.size() == 1){
                /* cout << "Linha " << k << endl; */
                ll lv = M[k][c];
                pi tosol;
                map<int,int> alsol;
                for(int j = 0; j < c; j++){
                    /* cout << "Valor " << M[k][j] << endl; */
                    if(!sol[M[k][j]]){
                        /* cout << "Valor pra calcular " << M[k][j] << endl; */
                        tosol.first = M[k][j];
                        tosol.second++;
                    } else {
                        alsol[M[k][j]]++;
                    }
                }
                for(auto [kk,v] : alsol){
                    lv -= values[kk]*v;
                }
                if(tosol.second){
                    values[tosol.first] = lv/tosol.second;
                    sol[tosol.first]++;
                    solved++;
                }
            }
        }
        /* cout << endl; */
        for(auto [k,s] : colunas){
            /* cout << "Coluna: " << k << ' ' << s.size() << '\n'; */
            if(s.size() == 1){
                /* cout << "Coluna " << k << endl; */
                ll cv = M[l][k];
                pi tosol;
                map<int,int> alsol;
                for(int i = 0; i < l; i++){
                    /* cout << "Valor " << M[i][k] << endl; */
                    if(!sol[M[i][k]]){
                        /* cout << "Valor pra calcular " << M[i][k] << endl; */
                        tosol.first = M[i][k];
                        tosol.second++;
                    } else {
                        alsol[M[i][k]]++;
                    }
                }
                for(auto [kk,v] : alsol){
                    cv -= values[kk]*v;
                }
                if(tosol.second){
                    values[tosol.first] = cv/tosol.second;
                    sol[tosol.first]++;
                    solved++;
                }
            }
        }
        /* cout << endl; */
        /* cout << "SOLVED " << solved << endl; */
    }
    vector<pair<string,int>> res;
    for(int i = 1; i <= var; i++){
        string vv = its[i];
        int vl = values[i];
        res.push_back({vv,vl});
    }
    sort(res.begin(), res.end());
    for(auto [v,vl] : res){
        cout << v << ' ' << vl << endl;
    }
}

int main(){
    solve();
    return 0;
}

