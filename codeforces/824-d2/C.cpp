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

int n, Testcase;
string s;

map<char,char> graph;
map<char,char> parent;

int valid(){
    int fechou = 0;
    int size = 0;
    for(int l = 'a'; l <= 'z'; l++){
        int tsize = 0;
        char source = l;
        char fs = source;
        while(graph[fs]){
            if(fs == source && tsize){
                fechou = 1;
                break;
            }
            fs = graph[fs];
            tsize++;
        }
        size = max(size,tsize);
    }
    return (!fechou || size == 26);
}

void solve(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        auto p = s[i];
        if(!graph[p]){
            char l = 'a';
            for(; l <= 'z'; l++){
                if(graph[l] == p || p == l || parent[l]) continue;
                graph[p] = l; parent[l] = p;
                if(valid()) break;
                graph[p] = 0; parent[l] = 0;
            }
        }
    }
    for(char c : s){
        cout << graph[c];
    }
    cout << endl;
    graph.clear();
    parent.clear();
}

int main(){
#ifndef LOCAL_DEBUG   
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}

