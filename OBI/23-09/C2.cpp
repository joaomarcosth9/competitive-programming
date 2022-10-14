#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

class segtree {
private:
    int lc(int a) { return 2*a+1; }
    int rc(int a) { return 2*a+2; }
    int segn;
    pair<int,int> tree[4*maxn];
    void build(int n, int l, int r, vector<int>& v){
        if(l == r){
            tree[n] = make_pair(v[l], l);
        } else {
            int mid = l+(r-l)/2;
            build(lc(n), l, mid, v);
            build(rc(n), mid+1, r, v);
            tree[n] = min(tree[lc(n)], tree[rc(n)]);
        }
    }
    pair<int,int> query(int n, int l, int r, int ll, int rr){
        if(r < ll || l > rr) return make_pair(INT_MAX,INT_MAX);
        if(l >= ll && r <= rr) return tree[n];
        int mid = l+(r-l)/2;
        return min( query(lc(n), l, mid, ll, rr), query(rc(n), mid+1, r, ll, rr) );
    }
    void update(int n, int l, int r, int i, int v){
        if(l == r) tree[n].first = v;
        else {
            int mid = l + (r-l)/2;
            if(i <= mid){
                update(lc(n), l, mid, i, v);
            } else {
                update(rc(n), mid+1, r, i, v);
            }
            tree[n] = min(tree[lc(n)], tree[rc(n)]);
        }
    }
public:
    void build(vector<int>& v) {
        segn = (int)v.size();
        build(0, 0, segn-1, v);
    }
    pair<int,int> query(int l, int r){
        return query(0, 0, segn-1, l, r);
    }
    void update(int i, int v){
        update(0, 0, segn-1, i, v);
    }
};

class segtreemx {
private:
    int lc(int a) { return 2*a+1; }
    int rc(int a) { return 2*a+2; }
    int segn;
    pair<int,int> tree[4*maxn];
    void build(int n, int l, int r, vector<int>& v){
        if(l == r){
            tree[n] = make_pair(v[l], l);
        } else {
            int mid = l+(r-l)/2;
            build(lc(n), l, mid, v);
            build(rc(n), mid+1, r, v);
            tree[n] = max(tree[lc(n)], tree[rc(n)]);
        }
    }
    pair<int,int> query(int n, int l, int r, int ll, int rr){
        if(r < ll || l > rr) return make_pair(INT_MIN,INT_MIN);
        if(l >= ll && r <= rr) return tree[n];
        int mid = l+(r-l)/2;
        return max( query(lc(n), l, mid, ll, rr), query(rc(n), mid+1, r, ll, rr) );
    }
    void update(int n, int l, int r, int i, int v){
        if(l == r) tree[n].first = v;
        else {
            int mid = l + (r-l)/2;
            if(i <= mid){
                update(lc(n), l, mid, i, v);
            } else {
                update(rc(n), mid+1, r, i, v);
            }
            tree[n] = max(tree[lc(n)], tree[rc(n)]);
        }
    }
public:
    void build(vector<int>& v) {
        segn = (int)v.size();
        build(0, 0, segn-1, v);
    }
    pair<int,int> query(int l, int r){
        return query(0, 0, segn-1, l, r);
    }
    void update(int i, int v){
        update(0, 0, segn-1, i, v);
    }
};

segtree seg;
segtreemx segmx;

int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    seg.build(v);
    segmx.build(v);
    for(int q = 0; q < m; q++){
        int a; cin >> a;
        if(a == 1){
            int p, i; cin >> p >> i;
            i--;
            pair<int,int> mxi = segmx.query(i,i);
            pair<int,int> mni = seg.query(i,i);
            if(p > mxi.first){
                segmx.update(i, p);
            } else if (p < mni.first){
                seg.update(i, p);
            }
        } else {
            int l, r; cin >> l >> r;
            l--, r--;
            pair<int,int> mx = segmx.query(l,r);
            pair<int,int> mn = seg.query(l,r);
            int res = mx.first - mn.first;
            if(mx.second == mn.second){
                int chgmin, chgmax;
                int oldmn = mn.first;
                int oldmx = mx.first;

                segmx.update(mx.second, INT_MIN);
                pair<int,int> temp = segmx.query(l,r);
                chgmax = temp.first - oldmn;
                segmx.update(mx.second, oldmx);

                seg.update(mn.second, INT_MAX);
                temp = seg.query(l,r);
                chgmin = oldmx - temp.first;
                seg.update(mn.second, oldmn);

                res = max(chgmax, chgmin);
            }
            cout << res << endl;
        }
    }
    return 0;
}
