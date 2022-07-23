#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    string br; cin >> br;
    int len = (int)br.size();
    stack<int> st;

    int pending = 0;
    int op = 0;
    int cl = 0;

    for(int i = 0; i < len; i++){
        if(br[i] == '('){
            st.push(1);
            op++;
        } else if(br[i] == ')'){
            if(!st.empty()){ st.pop();cl++; }
        } else if(br[i] == '?' && st.empty()){
            br[i] = '(';
            op++;
            st.push(1);
        }
        else if(br[i] == '?' && !st.empty()){
            pending++;
        }
    }
    cout << op << ' ' << cl << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
