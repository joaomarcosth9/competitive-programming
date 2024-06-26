#include <bits/stdc++.h>

using namespace std;

struct prefixsum {
    vector<int> a;
    prefixsum(vector<int> &b){
        a.resize(b.size() + 10);
        partial_sum(b.begin(), b.end(), a.begin());
    }
    int query(int l, int r){
        if(l == 0) return a[r];
        return a[r] - a[l-1];
    }
};

int main(){
    vector<int> a = {1, 2, 3, 4, 5};
    prefixsum p(a);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < a.size(); i++){
        cout << p.query(0, i) << endl;
    }
    cout << p.query(0, 2) << endl;
    cout << p.query(1, 3) << endl;
    cout << p.query(2, 4) << endl;
    cout << p.query(3, 4) << endl;
}

