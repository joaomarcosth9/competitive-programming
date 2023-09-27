#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const int maxn = 2e5+5;
vector<vector<int>> mergeMask(32, vector<int> (32));

bool contains(const string& s, const string& b){
    int pos = 0;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == b[pos]) pos++;
        if(pos == (int)b.size()) break;
    }
    return pos == (int)b.size();
}

vector<string> bits = {"a", "b", "c", "ab", "bc"};

struct node {
    int dp[32];
    node(){
        for(int i = 0; i < 32; i++) this->dp[i] = INF;
    }
    node(int bit){
        for(int i = 0; i < 32; i++) this->dp[i] = INF;
        this->dp[(1 << bit)] = 0;
        this->dp[0] = 1;
    }
};

node neutral_r = node('a'-'a');
node neutral_l = node('c'-'a');

node comp(const node& lnode, const node& rnode){
    node res;
    for(int mask1 = 0; mask1 < 32; mask1++){
        if(lnode.dp[mask1] == INF) continue;
        for(int mask2 = 0; mask2 < 32; mask2++){
            int mask3 = mergeMask[mask1][mask2];
            if(mask3 == -1) continue;
            res.dp[mask3] = min(res.dp[mask3], lnode.dp[mask1] + rnode.dp[mask2]);
        }
    }
    return res;
}

vector<node> tree(2*maxn);
char s[maxn];

void solve(){
    int n, q; 
    scanf("%d %d", &n, &q);
    scanf("%s", s);
    int pw = 1;
    while(pw < n) pw <<= 1;
    for(int i = n; i < pw; i++) s[i] = 'a';
    n = pw;
    for(int i = 0; i < n; i++){
        tree[i+n] = node(s[i]-'a');
    }
    for(int i = n-1; i; i--){
        tree[i] = comp(tree[i<<1], tree[i<<1|1]);
    }
    while(q--){
        int i; char c;
        scanf("%d %c", &i, &c);
        tree[i+=n-1] = node(c-'a');
        for(i >>= 1; i; i >>= 1) tree[i] = comp(tree[i<<1], tree[i<<1|1]); 
        int res = INF;
        for(int mask = 0; mask < 32; mask++){
            res = min(res, tree[1].dp[mask]);
        }
        printf("%d\n", res);
    }
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    auto resultingMask = [&] (vector<string>& m1, vector<string>& m2){
        int merged = 0;
        for(string& s : m1){
            for(string& t : m2){
                string smerged = s + t;
                if(contains(smerged, "abc")){
                    return -1;
                }
                for(int i = 0; i < 5; i++){
                    if(contains(smerged, bits[i])){
                        merged |= (1 << i);
                    }
                }
            }
        }
        return merged;
    };
    for(int mask1 = 0; mask1 < 32; mask1++){
        for(int mask2 = 0; mask2 < 32; mask2++){
            vector<string> smask1, smask2;
            for(int i = 0; i < 5; i++){
                if(mask1 & (1 << i)) smask1.push_back(bits[i]);
                if(mask2 & (1 << i)) smask2.push_back(bits[i]);
            }
            smask1.push_back("");
            smask2.push_back("");
            int merged = resultingMask(smask1, smask2);
            mergeMask[mask1][mask2] = merged;
        }
    }
    int tsts = 1;
    /* if(testcases) cin >> tsts; */
    while(tsts--) solve();
    return 0;
}
