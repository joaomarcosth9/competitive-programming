#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

struct node {
    int l, m, r;
    node() : l(0), m(0), r(0) {}
    node(int l, int m, int r) : l(l), m(m), r(r) {}
};

int res = 0;

void dfs(int u, int temp_res, vector<node>& tree, bool mid = 0){
    res = max(res, temp_res);
    if(!mid && tree[u].l != 0){
        dfs(tree[u].l, 1, tree, mid);
    }
    if(tree[u].m != 0){
        dfs(tree[u].m, temp_res+1, tree, mid);
    }
    if(!mid && tree[u].r != 0){
        dfs(tree[u].r, 1, tree, mid);
    }
}

void solve(){
    int n1, n2;
    cin >> n1;
    vector<node> tree1(n1+1);
    for(int i = 0; i < n1; i++){
        int u, l, m; cin >> u >> l >> m;
        assert(u != 0);
        tree1[u] = node(l, m, 0);
    }
    cin >> n2;
    vector<node> tree2(n2+1);
    for(int i = 0; i < n2; i++){
        int u, m, r; cin >> u >> m >> r;
        assert(u != 0);
        tree2[u] = node(0, m, r);
    }
    int res1 = 0, mid1 = 0, res2 = 0, mid2 = 0;
    dfs(1, 1, tree1);
    res1 = res; res = 0;
    dfs(1, 1, tree1, 1);
    mid1 = res; res = 0;
    dfs(1, 1, tree2);
    res2 = res; res = 0;
    dfs(1, 1, tree2, 1);
    mid2 = res; res = 0;
    db(res1, mid1);
    db(res2, mid2);
    int r1 = min(res2, mid1);
    int r2 = min(res1, mid2);
    cout << n1 + n2 - max(r1, r2) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
