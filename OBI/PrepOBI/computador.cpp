#include <bits/stdc++.h>
using namespace std;

struct node {
    long long st, r;
};

long long calculate(int i, node nodo, int l){
    return (nodo.st-(i-l)*nodo.r);
}

const int MAX = 2e5+5;
node tree_front[4*MAX];
node tree_back[4*MAX];

int le(int n){ return 2*n+1; }
int ri(int n){ return 2*n+2; }

void update(int n, int l, int r, int st, int en, int v, node tree[]){
    if(r < st || l > en){
        return;
    }
    if(l >= st && r <= en){
        tree[n].st += v, tree[n].r++;
        return;
    }
    int mid = (l+r)/2;
    if(st > mid){
        update(ri(n), mid+1, r, st, en, v, tree);
    } else if(en <= mid){
        update(le(n), l, mid, st, en, v, tree);
    } else {
        update(le(n), l, mid, st, mid, v, tree);
        update(ri(n), mid+1, r, mid+1, en, v-(mid-st+1), tree);
    }
}

long long query(int n, int l, int r, int i, node tree[]){
    if(l == r){
        return tree[n].st;
    }
    long long current = calculate(i, tree[n], l);
    int mid = (l+r)/2;
    if(i <= mid){
        return current + query(le(n), l, mid, i, tree);
    } else {
        return current + query(ri(n), mid+1, r, i, tree);
    }
}

int n,m;
void update(int i, int v, node tree[]) {
    int en = min(i+v-1, n-1);
    update(0, 0, n-1, i, en, v, tree);
}
long long query(int i, node tree[]) {
    return query(0, 0, n-1, i, tree);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    // clear(n);   
    auto rev = [&] (int i){
        return (n-(i+1));
    };
    while(m--){
        int t; cin >> t;
        if(t == 1){
            // frente
            int i, v; cin >> i >> v; 
            i--;
            update(i,v,tree_front);
        } else if (t == 2){
            // tras
            int i, v; cin >> i >> v; 
            i--;
            update(rev(i),v,tree_back);
        } else if (t == 3){
            // query
            int i; cin >> i;
            i--; 
            cout << query(i, tree_front) + query(rev(i), tree_back) << endl;
        }
    }
    return 0;
}
