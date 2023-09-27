#include <bits/stdc++.h>
using namespace std;

const int neutral = INT_MIN;
#define comp(a,b) max(a,b)

class SegmentTree {
    vector<int> st;
    int size;
#define left(p) (p << 1)
#define right(p) (p << 1) + 1
    private:
    void build(int p, int l, int r, int* A) {
        if (l == r) { st[p] = A[l]; return; }
        int m = (l + r) >> 1; 
        build(left(p), l, m, A); 
        build(right(p), m+1, r, A); 
        st[p] = comp(st[left(p)], st[right(p)]); 
    } 
    void update(int p, int l, int r, int a, int b, int k){
        if(a > r || b < l) return;
        else if (l >= a && r <= b){
            st[p] = k; return;
        }
        update(left(p), l, (l+r) >> 1, a, b, k);
        update(right(p), ((l+r) >> 1) + 1, r, a, b, k);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    int query(int p, int l, int r, int a, int b) {
        if (a > r || b < l) return neutral; 
        if (l >= a && r <= b) return st[p]; 
        int m = (l + r) >> 1; 
        int p1 = query(left(p), l, m, a, b); 
        int p2 = query(right(p), m+1, r, a, b); 
        return comp(p1, p2); 
    } 
    public: 
    SegmentTree(int* bg, int* en) {
        size = (en-bg);
        st.assign(sizeof(int)*size, neutral); 
        build(1, 0, size-1, bg); 
    }
    int query(int a, int b) {
        return query(1, 0, size-1, a, b); 
    } 
    void update(int a, int k){
        update(1, 0, size-1, a, a, k); 
    }
};

const int maxn = 3.1e5;
int arr[maxn]; 

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int diff[n];
    diff[0] = neutral;
    for(int i = 1; i < n; i++){
        diff[i] = abs(arr[i] - arr[i-1]);
    }
    SegmentTree seg(diff, diff+n);
    /* cout << "[ "; */
    /* for(int i = 0; i < n; i++){ */
    /*     cout << diff[i] << " "; */
    /* } */
    /* cout << "]"; */
    /* cout << endl; */
    /* cout << "[ "; */
    /* for(int i = 0; i < n; i++){ */
    /*     cout << seg.query(i, i) << " "; */
    /* } */
    /* cout << "]"; */
    /* cout << endl; */
    while(q--){
        int t, i, h; cin >> t >> i >> h;
        i--;
        if(t == 1){
            // update
            // diff[i] = diferenca do i pro i-1
            arr[i] = h;
            if(i != 0){
                diff[i] = abs(arr[i] - arr[i-1]);
                seg.update(i, diff[i]);
            }
            if(i < n-1){
                diff[i+1] = abs(arr[i+1] - arr[i]);
                seg.update(i+1, diff[i+1]);
            }
            /* cout << "[ "; */
            /* for(int ii = 0; ii < n; ii++){ */
            /*     cout << seg.query(ii, ii) << " "; */
            /* } */
            /* cout << "]"; */
            /* cout << endl; */
            /* cout << "QUERY: " << seg.query(i, i).maxx << " " << seg.query(i,i).minn << endl; */
        } else if(t == 2){
            /* cout << "----------------------------" << endl; */
            // query
            // r?
            /* cout << "PRIMEIRA PARTE" << endl; */
            /* if(i == n-1){ */
            /*     /1* cout << "Caso base "; *1/ */
            /*     cout << 1 << endl; */
            /*     continue; */
            /* } */
            // i indexado em zero
            // diff[i] = diferenca do i pro i-1 (indexado em 0)
            int l = i+1, r = n-1;
            int mid;
            pair<int,int> res = {1,i};
            /* cout << "H: " << h << endl; */
            while( l <= r ){
                mid = (l + r) >> 1;
                int tres = seg.query(i+1, mid);
                /* cout << "i: " << i << " | mid: " << mid << endl; */
                /* cout << "Temp res: " << tres << endl; */
                if(tres > h){
                    /* cout << "Maximo deu " << tres << " portanto pulando." << endl; */
                    r = mid-1;
                } else {
                    /* cout << "Solucao atual MID: " << mid << " | res: " << tres << endl; */
                    res = {tres, mid};
                    l = mid+1;
                }
            }

            /* cout << "SEGUNDA PARTE" << endl; */
            l = 1, r = i;
            pair<int,int> res2 = {1,i};
            /* cout << "H: " << h << endl; */
            while( l <= r ){
                mid = (l + r) >> 1;
                int tres = seg.query(mid, i);
                /* cout << "i: " << i << " | mid: " << mid << endl; */
                /* cout << "Temp res: " << tres << endl; */
                if(tres > h){
                    /* cout << "Maximo deu " << tres << " portanto pulando." << endl; */
                    l = mid+1;
                } else {
                    /* cout << "Solucao atual MID: " << mid << " | res: " << tres << endl; */
                    res2 = {tres, mid-1};
                    r = mid-1;
                }
            }

            auto& [ress, idx] = res;
            auto& [ress2, idx2] = res2;
            /* cout << "IDX: " << idx << " | i: " << i << endl; */
            /* cout << "Res1: " << ress << " | idx1: " << idx << endl; */
            /* cout << "Resposta: " << idx - i + 1 << endl; */
            /* cout << "IDX2: " << idx2 << " | i: " << i << endl; */
            /* cout << "Res2: " << ress2 << " | idx2: " << idx2 << endl; */
            /* cout << "Resposta2: " << i - idx2 + 1 << endl; */
            /* cout << "RESPOSTA FINAL: " << idx - idx2 + 1 << endl; */
            cout << idx - idx2 + 1 << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
