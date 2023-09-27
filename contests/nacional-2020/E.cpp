#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

vector<int> bit;
int query(int i){
    int ans = 0;
    for(; i; i -= i & -i) ans += bit[i];
    return ans;
}

void update1(int i, int val){
    for(; i && i < (int)bit.size(); i += i & -i){
        bit[i] += val;
    }
}

void update(int l, int r){
    if(l > r) return;
    update1(l, 1);
    update1(r + 1, -1);
}

void solve() {
    int n; cin >> n;

    bit.resize(n + 1);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int,int> m;
    for(int i = 0; i < n; i++){
        m[a[i]] = 1;
    }
    int u = 0;
    for(auto& [k, v] : m) { v = u++; }
    for(int i = 0; i < n; i++) a[i] = m[a[i]]; 

    debug(a);

    vector<pair<int,int>> b;

    for(int i = 0; i < n; i++){
        b.emplace_back(a[i], i);
    }
    sort(rbegin(b), rend(b));
    debug(b);

    set<int> st;
    st.insert(0);
    st.insert(n + 1);

    for(int i = 0; i < n; i++){
        a[i] = b[i].second + 1;
    }
    debug(a);

    for(int i = 0; i < n; i++){
        auto ub = st.upper_bound(a[i]);
        auto llb = st.lower_bound(a[i]);
        llb--;
        int caras_ub  = *ub - a[i] - 1;
        if(*ub != n + 1) caras_ub /= 2;
        update(a[i] + 1, a[i] + caras_ub);
        int caras_lb = a[i] - *llb - 1;
        if(*llb != 0) caras_lb /= 2;
        update(a[i] - caras_lb, a[i] - 1);
        st.insert(a[i]);
    }
    
    for(int i = 1; i <= n; i++){
        cout << query(i) << " ";
    }
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
