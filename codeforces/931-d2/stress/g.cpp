#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAX = 2e5 + 2;
const int MA = 1e4;
const int INF = 1.05e9;
const int INFM = -1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
//vector<int> adj[MAX];



void solve(){
    vector<vector<int>> arr(103, vector<int>(103,0));
    arr[1][2] = 0;
    arr[2][1] = 0;
    arr[0][0] = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(arr[i][j] == 0){
                for(int k = j+1; k <= 100; k++){
                    arr[i][k] = 1;
                }
                for(int k = j+1; k <= 100; k++){
                    arr[k][i] = 1;
                }
                for(int k = j+1, s = 1; k <= 100 && (i+s) <= 100; k++, s++){
                    arr[i+s][k] = 1;
                }
            }
        }
    }
    int n; cin >> n;
    int pp = 0, pg = 0, pgp = 0;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if(arr[x][y] == 0) pp++;
        else if(x == 1 && y == 3 || x == 3 && y == 1) pgp++;
        else pg++;
    }
    if((pgp + pg) % 2 == 1){
        cout << "Y" << endl;
        return;
    }
    if( (pgp + pg) == 0){
        cout << "N" << endl;
        return;
    }
    if(pg > 0){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }


    /* for(int i = 20; i > 0; i--){ */
    /*     for(int j = 1; j < 20; j++){ */
    /*         cout << arr[i][j] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << endl; */

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    bool tttt = 0;
    if(tttt){
        int testcase; cin >> testcase;
        while (testcase--){
            solve();
        }
    }else solve();

    return 0;
}


