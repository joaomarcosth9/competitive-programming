#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

const int MAX = 2e5+5;
long long arr[MAX];

void solve(){
    int n, k; cin >> n >> k; k--;
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<long long> v;
    for(int i = 0; i < n; i++){
        if(v.size() && ((v.back() > 0 && arr[i] >= 0) || (v.back() < 0 && arr[i] < 0))){
            v.back() += arr[i];
        } else {
            v.push_back(arr[i]);
        }
        if(i == k){
            k = v.size()-1;
        }
    }
    int idx;
    for(idx = 0; idx+1 < k; idx++){
        if(v[idx] < 0) break;
    }
    v.erase(v.begin(), v.begin()+idx);
    k -= idx;
    idx = v.size()-1;
    while(idx > k && v[idx] > 0){
        v.pop_back();
        idx--;
    }
    n = v.size();
    vector<long long> left;
    vector<long long> right;
    for(int i = k-1; i >= 0; i--){
        left.push_back(v[i]);
    }
    for(int i = k+1; i < n; i++){
        right.push_back(v[i]);
    }
    left.push_back(0);
    right.push_back(0);
    cout << "Meu cara: " << v[k] << endl;
    for(auto a : left) cout << a << ' ';
    cout << endl;
    for(auto a : right) cout << a << ' ';
    cout << endl;
    cout << "----------\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
