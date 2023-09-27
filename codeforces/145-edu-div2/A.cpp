#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    string s; cin >> s;
    sort(begin(s), end(s));
    int res = 1;
    if(s[0] == s[3]){
        cout << -1 << endl;
        return;
    }
    set<char> st;
    map<char,int> f;
    for(int i = 0; i < 4; i++){
        st.insert(s[i]);
        f[s[i]]++;
    }
    vector<int> v;
    for(auto [_, ff] : f) v.push_back(ff);
    sort(rbegin(v), rend(v));
    int n = v.size();
    if(st.size() == 4){
        cout << 4 << endl;
        return;
    } else if (st.size() == 3){
        cout << 4 << endl;
        return;
    } else if (st.size() == 2){
        if(v[0] == 3){
            cout << 6 << endl;
            return;
        } else {
            cout << 4 << endl;
            return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

