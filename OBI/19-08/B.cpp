#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e6+100;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define endl '\n'

int arr[MAX];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    int i = 0, j = n-1;
    while(i <= j){
        int somal = arr[i], somar = arr[j];
        while(somal != somar && i < j){
            if(somal < somar){
                i++;
                somal+=arr[i];
                ans++;
            } else if (somar < somal){
                j--;
                somar+=arr[j];
                ans++;
            }
        }
        i++; j--;
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}

