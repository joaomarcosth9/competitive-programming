#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 1e5+5, B = 1 << (32-__builtin_clz(maxn)), maxU = 5e6 + 10;
int n, q, arr[maxn], phi[maxU];
typedef pair<int,int> ii;
typedef vector<ii> node;
node t[2*B];

node build(node& a, node& b){
    if(b.empty()) return a;
    if(a.empty()) return b;
    node ret;
    int i = a.size()-1, j = b.size() -1;
    while(i >= 0 && j >= 0){
        if(a[i].first == b[j].first){
            ret.emplace_back(a[i].first, a[i].second + b[j].second);
            i--, j--;
        } else if(a[i] > b[j]) i--;
        else j--;
    }
    reverse(begin(ret), end(ret));
    return ret;
}

void solve(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++){
        node nodo(1, {arr[i], 0});
        int op = 1, u = arr[i];
        while (u != 1){
            u = phi[u];
            nodo.emplace_back(u, op++);
        }
        reverse(begin(nodo), end(nodo));
        t[i+B] = nodo;
    }
    for(int i = B-1; i > 0; i--){
        t[i] = build(t[i<<1], t[i<<1|1]);
    }

    set<int> valids;
    for(int i = 0; i < n; i++) if(arr[i] != 1) valids.insert(i);

    while(q--){
        int op, l, r; cin >> op >> l >> r;
        l--, r--;
        if(op == 1){
            // update [l,r]
            for(auto u = valids.lower_bound(l); u != valids.end() && *u <= r;){
                int i = *u + B;
                auto cara = t[i].back().first;
                if(t[i].size() == 2) u = valids.erase(u);
                else u++;
                for(; i > 0; i >>= 1){
                    if(t[i].back().first == cara) t[i].pop_back();
                    for(auto& [_, k] : t[i]) k--;
                }
            }
        } else {
            // query [l,r]
            node ans;
            for(l += B, r += B+1; l < r; l >>= 1, r >>= 1){
                if(l & 1) ans = build(ans, t[l++]);
                if(r & 1) ans = build(t[--r], ans);
            }
            cout << ans.back().second << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i = 0; i < maxU; i++) phi[i] = i;
    for (int i = 2; i < maxU; i++) if (phi[i] == i) {
        for (int j = i; j < maxU; j += i)
            phi[j] -= phi[j] / i;
    }
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
