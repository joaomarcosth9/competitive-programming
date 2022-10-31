#include <bits/stdc++.h>
using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;

void solve(){
    string a, b; cin >> a >> b;
    int la = a.size(), lb = b.size();
    char lca = a[la-1], lcb = b[lb-1];
    bool maior = 0;
    if(a == b){
        cout << "=" << endl;
        return;
    }
    if(lca == 'M' && lcb == 'S'){
        maior = 1;
    } else if(lca == 'M' && lcb == 'L'){
        maior = 0;
    } else if(lcb == 'M' && lca == 'S'){
        maior = 0;
    } else if(lcb == 'M' && lca == 'L'){
        maior = 1;
    } else if(lca == 'L' && lcb == 'S'){
        maior = 1;
    } else if (lca == 'S' && lcb == 'L'){
        maior = 0;
    } else if (lca == 'S' && lcb == 'S'){
        maior = (la < lb);
    } else if (lca == 'L' && lcb == 'L'){
        maior = (la > lb);
    }
    cout << (maior ? ">" : "<") << endl;
} 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
