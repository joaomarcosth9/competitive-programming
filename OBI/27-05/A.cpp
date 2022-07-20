#include <bits/stdc++.h>

using namespace std;

int n;
int arr[505];

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int melhor = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int achados = 0;
            if(i==j) continue;
            int find1 = 0;
            int find2 = 1;
            for (int k = 0; k < n; k++){
                if(find2 == 1 && arr[k] == i){
                    find1 = 1;
                    find2 = 0;
                    achados++;
                }
                if (find1 == 1 && arr[k] == j){
                    find2 = 1;
                    find1 = 0;
                    achados++;
                }
            }
            if (achados > melhor)
                melhor = achados;
        }
    }
    cout << melhor << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
