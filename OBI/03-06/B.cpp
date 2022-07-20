#include <bits/stdc++.h>

using namespace std;

int arr[1010];

void solve(){
    int n; cin >> n;
    int pequenas = 0;
    int medias = 0; 
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        if (temp == 1){
            pequenas++;
        } else {
            medias++;
        }
    }
    int p, m; cin >> p >> m;
    if (pequenas >= p && medias >= m){
        cout << 'S' << '\n';
    } else {
        cout << 'N' << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
