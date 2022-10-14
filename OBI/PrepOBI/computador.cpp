#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int long long

struct fenwick {
    vector<int> bit;
    int n;
    fenwick(int a){
        n = a;
        bit.assign(n+1, 0);
    }
    int query(int i){
        int res = 0;
        for(; i > 0; i -= (i & -i)){
            res += bit[i];
        }
        return res;
    }
    int query(int l, int r){
        return query(r) - query(l-1);
    }
    void pt(){
        for(int i = 1; i <= n; i++) cout << query(i,i) << ' ';
        cout << endl;
    }
    void update(int i, int v){
        for(; i <= n; i += (i & -i)){
            bit[i] += v;
        }
    }
    void rangeupdate(int l, int r, int v){
        update(l, v);
        update(r+1, -v);
    }
};

void solve(){
    int n; cin >> n;
    fenwick ft(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        ft.update(i+1, v);
    }
    int q; cin >> q; while(q--){
        int tq; cin >> tq;
        if(tq == 1){
            int l; cin >> l;
            cout << ft.query(l) << endl;
        } else if (tq == 2){
            int i, v; cin >> i >> v;
            ft.pt();
            ft.update(i,v);
            ft.pt();
        } else if (tq == 3){
            int l, r, v; cin >> l >> r >> v;
            ft.pt();
            ft.rangeupdate(l,r,v);
            ft.pt();
        }
    }
}

signed main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
