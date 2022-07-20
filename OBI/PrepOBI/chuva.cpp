#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

const int MAX = 1e5+50;
int arr[MAX], pref[MAX], res;
map<int,int> freq;

void solve(){
    int n, s; cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pref[i] = pref[i-1] + arr[i];
    }
    freq[0] = 1;
    for(int i = 1; i <= n; i++){
        res+=freq[pref[i]-s];
        freq[pref[i]]++;
    }

    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
