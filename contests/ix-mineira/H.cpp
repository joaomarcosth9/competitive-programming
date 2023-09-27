#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

int n, m, mat[505][505];

pair<int,int> moves[] = { 
    {0,-1},{-1,-1},{-1,0},{-1,1},
    {0,1},{1,1},{1,0},{1,-1}
};

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int a, b; cin >> a >> b;
    a--, b--;
    for(int op = 0; op < (n + m); op++){
        int v = 0;
        for(auto [x, y] : moves){
            if(valid(a + x, b + y)) v++;
        }
        if(v == 0) break;

        int o = mat[a][b] / v;
        int r = mat[a][b] % v;
        mat[a][b] = r;

        int im = -1, jm = -1, mx = -1;
        for(auto [x, y] : moves){
            debug(a + x, b + y, valid(a + x, b + y), mat[a + x][b + y]);
            if(!valid(a + x, b + y)) continue;
            mat[a + x][b + y] += o;
            if(mat[a + x][b + y] > mx){
                mx = mat[a + x][b + y];
                im = a + x;
                jm = b + y;
            }
        }
        debug(a, b);
        a = im, b = jm;
    }
    int res = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res = max(res, mat[i][j]);
        }
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
