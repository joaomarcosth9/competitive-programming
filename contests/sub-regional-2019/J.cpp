#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> freq(n, vector<int>(13));
    map<char, int> conv;
    string CARDS = "A23456789DQJK";
    for(int i = 0; i < 13; i++){
        conv[CARDS[i]] = i;
    }
    vector<int> total(n, 4);
    for(int i = 0; i < n; i++){
        string cards; cin >> cards;
        for(int j = 0; j < 4; j++)
            freq[i][conv[cards[j]]]++;
    }
    k--;
    int wc = k, pode = 0;
    total[k]++;
    auto check = [&] (int p){
        int maxx = INT_MIN;
        for(auto a : freq[p]){
            maxx = max(a, maxx);
        }
        return maxx == 4;
    };
    auto valid = [&] (int p){
        int df = 0;
        for(auto a : freq[p]){
            df += (a > 0);
        }
        return df <= n;
    };
    int winner = -1;
    for(int p = 0; p < n; p++){
        if(wc != p && total[p] == 4 && check(p)){
            cout << p+1 << endl;
            return;
        }
    }
    for(int p = k, nx;; p = nx){
        assert(valid(p));
        if(wc != p && total[p] == 4 && check(p)){
            winner = p+1;
            break;
        }
        nx = (p + 1) % n;
        if(wc == p && pode){
            total[p]--, total[nx]++;
            wc = nx;
            pode = 0;
        } else {
            if(wc == p) pode = 1;
            pair<int,int> res = {INT_MIN, INT_MAX};
            for(int i = 0; i < 13; i++){
                if(freq[p][i] != 0 && freq[p][i] < res.second){
                    res = {i, freq[p][i]};
                }
            }
            assert(res.second != INT_MAX);
            freq[p][res.first]--, freq[nx][res.first]++;
            total[p]--, total[nx]++;
        }
        if(nx == 0 && wc != 0 && total[0] == 4 && check(0)){
            winner = 1;
            break;
        }
        if(wc != p && total[p] == 4 && check(p)){
            winner = p+1;
            break;
        }
        assert(valid(p));
    }
    assert(winner != -1);
    cout << winner << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

