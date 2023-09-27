#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 505;
int mat1[maxn][maxn];
int mat2[maxn][maxn];
int pref1[maxn][maxn];
int pref2[maxn][maxn];

void solve(){
    int n, p; cin >> n >> p;
    for(int i = 0; i < p; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        mat1[x][y] = 1;
    }
    for(int i = 0; i < p; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        mat2[x][y] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref1[i][j] = mat1[i-1][j-1] + pref1[i-1][j] + pref1[i][j-1] - pref1[i-1][j-1];
        } 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            pref2[i][j] = mat2[i-1][j-1] + pref2[i-1][j] + pref2[i][j-1] - pref2[i-1][j-1];
        } 
    }
    /* db("mat1"); */
    /* for(int i = 0; i < n; i++){ */
    /*     for(int j = 0; j < n; j++){ */
    /*         cout << mat1[i][j] << " "; */
    /*     } */ 
    /*     cout << endl; */
    /* } */
    /* db("mat2"); */
    /* for(int i = 0; i < n; i++){ */
    /*     for(int j = 0; j < n; j++){ */
    /*         cout << mat2[i][j] << " "; */
    /*     } */ 
    /*     cout << endl; */
    /* } */
    auto query1 = [] (int i, int j, int ii, int jj){
        return pref1[ii][jj] - pref1[ii][j-1] - pref1[i-1][jj] + pref1[i-1][j-1];
    };
    auto query2 = [] (int i, int j, int ii, int jj){
        return pref2[ii][jj] - pref2[ii][j-1] - pref2[i-1][jj] + pref2[i-1][j-1];
    };
    long long r1 = 0, r2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            bool db1 = 0, db2 = 0;
            for(int s = 0; i+s <= n && j+s <= n; s++){
                int x = i+s, y = j+s;
                bool h1 = 0, h2 = 0;
                h1 |= query1(x, j, x, y);
                h2 |= query2(x, j, x, y);
                /* for(int k = j; k <= y; k++){ */
                /*     h1 |= mat[x][k] == 1; */
                /*     h2 |= mat[x][k] == 2; */
                /* } */
                /* for(int k = i; k < x; k++){ */
                /*     h1 |= mat[k][y] == 1; */
                /*     h2 |= mat[k][y] == 2; */
                /* } */
                h1 |= query1(i, y, x, y);
                h2 |= query2(i, y, x, y);
                if(db1){
                    if(!h2) r1++;
                    else break;
                } else if(db2){
                    if(!h1) r2++;
                    else break;
                } else {
                    if(h1 && h2) break;
                    if(h1){
                        r1++;
                        db1 = 1;
                    } else if(h2){
                        r2++;
                        db2 = 1;
                    }
                }
            }
        }
    }
    cout << r1 << " " << r2 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
