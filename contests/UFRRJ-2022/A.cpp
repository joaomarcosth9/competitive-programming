#include <bits/stdc++.h>
using namespace std;
#define int long long

int testcases = 0;
const int INF = 1.05e9;
const int INFLL = 4.5e18;

const int MAXN = 3e5+5;
int arr[MAXN], n;

const int MOD = 1e9+7, p = 2;

int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int inv_mod(int a){
    int x, y;
    int g = extended_euclidean(a, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

void add(int &a, int b){
    a = (a + b) % MOD;
    if(a < 0) a += MOD;
}
void mult(int &a, int b){
    a = (a * b) % MOD;
    if(a < 0) a += MOD;
}

int bin_pow(int b, int e){
    int v = b;
    int res = 1;
    while(e){
        if(e & 1){
            mult(res, v);
        }
        mult(v, v);
        e >>= 1;
    }
    return res;
}

int ft[MAXN], ft2[MAXN];

int query(int ftt[], int i){
    int res = 0;
    for(; i; i -= (i & -i)){
        add(res, ftt[i]);
    }
    return res;
}

int query(int ftt[], int l, int r){
    int res = query(ftt, r) - query(ftt, l-1);
    int inv = inv_mod(bin_pow(p, l));
    mult(res, inv);
    return res;
}

void update(int ftt[], int i){
    int val = bin_pow(p, i);
    for(; i <= MAXN - 3; i += (i & -i)){
        add(ftt[i], val);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    auto rev = [&] (int i){
        return n - i + 1;
    };
    for(int i = 0; i < n; i++){
        update(ft, arr[i]);
        update(ft2, rev(arr[i]));
        int k = min(arr[i] - 1, n - arr[i]);
        int l = arr[i] - k, r = arr[i] + k;
        if(query(ft, l, arr[i]-1) != query(ft2, rev(r), rev(arr[i]+1))){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
