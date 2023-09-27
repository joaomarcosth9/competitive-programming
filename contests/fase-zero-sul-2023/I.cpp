#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

pair<int,int> moves[] = { {0,1}, {1,0}, {0,-1}, {-1,0}, {-1,-1}, {1,1} };

vector<vector<int>> mat {
    {10},
    {8,9},
    {5,6,7},
    {1,2,3,4}
};

bool valid(int i, int j){
    return i >= 0 && i < (int)mat.size() && j >= 0 && j < (int)mat[i].size();
}

void solve() {
    vector<int> v(10);
    for(int i = 0; i < 10; i++){
        cin >> v[i];
    }
    vector<int> ress;

    for(int msk = 0; msk < (1 << 10); msk++){
        auto vv = v;
        for(int i = 0; i < (int)mat.size(); i++){
            for(int j = 0; j < (int)mat[i].size(); j++){
                if(msk & (1 << (mat[i][j] - 1))) {
                    for(auto [x, y] : moves){
                        auto ni = i + x, nj = j + y;
                        if(valid(ni, nj)){
                            vv[mat[ni][nj] - 1] ^= 1;
                        }
                    }
                }
            }
        }
        if(accumulate(begin(vv), end(vv), 0) == 10){
            ress.emplace_back(msk);
        }
    }
    if(ress.empty()){
        cout << -1 << endl;
        return;
    }
    int bpp = 10, bnum = (1 << 10) - 1;
    for(int i = 0; i < (int)ress.size(); i++){
        int pp = __builtin_popcount(ress[i]);
        int num = ress[i];
        if(pp < bpp){
            bnum = num, bpp = pp;
        } else if (pp == bpp){
            for (int j = 0; j < 10; j++) {
                if ((bnum & (1 << j)) == (num & (1 << j))) continue;
                if (num & (1 << j)) {
                    bnum = num;
                }
                break;
            }
        }
    }
    cout << bpp << '\n';
    int couted = 0;
    for(int i = 0; i < 10; i++){
        if(bnum & (1 << i)){
            couted++;
            cout << i + 1 << " \n"[couted == bpp];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
