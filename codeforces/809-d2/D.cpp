#include <iostream>
#include <vector>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5+50;
int n, h[MAX];

void solve(){
    cin >> n; for(int i = 0; i < n; i++) cin >> h[i];
    int ccc = 0;
    vector<int> C(n);
    for(int i = 0; i < n; i++) cout << C[i] << ' ';
    cout << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
