#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    string s; cin >> s;
    int tacerto = 1;
    int tdm = 1;
    for(int i = 0; i < (int)s.size(); i++){
        tdm &= (s[i] >= 65 && s[i] <= 90);
    }
    if(!tdm){
        if(s[0] >= 92 && s[0] <= 122){
            int tdm2 = 1;
            for(int i = 1; i < (int)s.size(); i++){
                tdm2 &= (s[i] >= 65 && s[i] <= 90);
            }
            if(tdm2){
                tacerto = 0;
            }
        }
    } else {
        tacerto = 0;
    }
    if(tacerto){
        cout << s << endl;
    } else {
        for(int i = 0; i < (int)s.size(); i++){
            s[i] = (s[i] >= 65 && s[i] <= 90 ? s[i] + 32 : s[i] - 32);
        }
        cout << s << endl;
    }
}

int main(){ _
    solve();
    return 0;
}
