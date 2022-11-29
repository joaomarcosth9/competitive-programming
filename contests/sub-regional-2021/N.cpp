#include <bits/stdc++.h>

using namespace std;

#define comp(a, b) ((a)+(b))

const int MAXS = 8e6+10, MAX = 3e5+10, MAXN = 3e5+10;
int st[MAXS], ls[MAXS], rs[MAXS];
int vroot[MAXN];
int sz, nds, nv;
int newnode() {
    ls[nds] = rs[nds] = -1;
    st[nds++] = 0;
    return nds-1;
}
void build(int p, int l, int r, int* A) {
    if (l == r) {
        st[p] = A ? A[l] : 0;
        return;
    }
    int m = (l + r) / 2;
    build(ls[p] = newnode(), l, m, A);
    build(rs[p] = newnode(), m+1, r, A);
    st[p] = comp(st[ls[p]], st[rs[p]]);
}
void update(int prv, int p, int l, int r, int i) {
    if (l == r) {
        st[p] = st[prv] + 1;
        return;
    }
    int m = (l + r) / 2;
    if (i <= m) {
        rs[p] = rs[prv];
        update(ls[prv], ls[p] = newnode(), l, m, i);
    }
    else {
        ls[p] = ls[prv];
        update(rs[prv], rs[p] = newnode(), m+1, r, i);
    }
    st[p] = comp(st[ls[p]], st[rs[p]]);
}
int query(int p, int l, int r, int a, int b) {
    if (a > r || b < l) return 0;
    if (l >= a && r <= b) return st[p];
    int m = (l + r) / 2;
    int p1 = query(ls[p], l, m, a, b);
    int p2 = query(rs[p], m + 1, r, a, b);
    return comp(p1, p2);
}
int query(int a, int b, int v) {
    return query(vroot[v], 0, sz-1, a, b);
}
int update(int i, int v) {
    vroot[nv++] = newnode();
    update(vroot[v], vroot[nv-1], 0, sz-1, i);
    return nv-1;
}
int nver() { return nv; }

int arr[MAX];
void solve(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", arr+i);
    sz = *max_element(arr, arr+n) + 10;
    nds = nv = 0;
    vroot[nv++] = newnode();
    build(vroot[0], 0, sz-1, NULL);
    for(int i = 0; i < n; i++){
        update(arr[i], i);
    }
    while(q--){
        int l, p, a, r, fr, fl;
        scanf("%d%d%d", &l, &p, &a);
        if(p <= arr[l-1]){
            printf("0\n"); continue;
        }
        r = l + a;
        fr = query(p, sz, r);
        fl = query(p, sz, l);
        printf("%d\n", fr - fl);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
