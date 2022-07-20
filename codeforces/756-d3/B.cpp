#include <bits/stdc++.h>

using namespace std;

void solve(){
    unsigned int p, m; cin >> p >> m;
    unsigned int count = 0;
    unsigned int maior = max(p, m);
    unsigned int menor = min(p, m);
    while(1){
        if (maior+menor < 4)
            break;
        if(maior-menor <= 1){
            count += menor/2;
            break;
        } else if (maior >= 3*menor){
            count += menor;
            break;
        } else {
            unsigned int x = (maior-menor)/2;
            maior -= 3*x;
            menor -= x;
            count+=x;
        }
    }
    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
