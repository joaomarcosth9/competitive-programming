#include <bits/stdc++.h>

using namespace std;

struct node {
    node *l = nullptr, *r = nullptr;
    int sum;

    node(int val) : sum(val) {}

    node(node *L, node *R){
        l = L, r = R, sum = 0;
        if(l) sum += l->sum;
        if(r) sum += r->sum;
    }
};

node* build(vector<int>& v, int l, int r){
    if(l == r){
        return new node(v[l]);
    }
    int mid = (l + r) / 2;
    return new node(build(v, l, mid), build(v, mid+1, r));
}
int query(node* nodo, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R){
        return nodo -> sum;
    }
    int mid = (l + r) / 2;
    int ql = query(nodo->l, l, mid, L, R);
    int qr = query(nodo->r, mid+1, r, L, R);
    return ql + qr;
}
node* update(node* nodo, int l, int r, int i, int val){
    if(l == r){
        return new node(nodo->sum+val);
    }
    int mid = (l + r) / 2;
    if(i <= mid){
        return new node(update(nodo->l, l, mid, i, val), nodo->r);
    } else {
        return new node(nodo->l, update(nodo->r, mid+1, r, i, val));
    }
}

const int MAX = 3e5+10;
int arr[MAX];

void solve(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++) scanf("%d", arr+i);
    int size = *max_element(arr, arr+n);
    vector<node*> seg(n+1);
    vector<int> v(size+1, 0);
    seg[0] = build(v, 1, size);
    for(int i = 1; i <= n; i++){
        seg[i] = update(seg[i-1], 1, size, arr[i-1], 1);
    }
    while(q--){
        int l, p, a, r;
        scanf("%d%d%d", &l, &p, &a);
        if(p <= arr[l-1]){
            printf("0\n"); continue;
        }
        r = l + a;
        int fr = query(seg[r], 1, size, p, size);
        int fl = query(seg[l], 1, size, p, size);
        printf("%d\n", fr - fl);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

