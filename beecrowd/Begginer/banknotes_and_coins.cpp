#include <bits/stdc++.h>

using namespace std;

int notas[] = {0,0,0,0,0,0};
int moedas[] = {0,0,0,0,0,0};
float arr[] = {10000,5000,2000,1000,500,200};
float arrm[] = {100,50,25,10,5,1};

void solve(){
    float n; cin >> n;
    float nu = n * 100;
    for(int i = 0; i < 6; i++){
        while(nu - arr[i] >= 0){
            nu -= arr[i];
            notas[i]++;
        }
    }
    for(int i = 0; i < 6; i++){
        while(nu - arrm[i] >= 0){
            nu -= arrm[i];
            moedas[i]++;
        }
    }
    cout << fixed;
    cout << setprecision(2);
    cout << "NOTAS:" << endl;
    for (int i = 0; i < 6; i++){
        cout << notas[i] << " nota(s) de R$ " << arr[i]/100 << endl;
    }
    cout << "MOEDAS:" << endl;
    for (int i = 0; i < 6; i++){
        cout << moedas[i] << " moeda(s) de R$ " << arrm[i]/100 << endl;
    }
}

int main(){
    solve();
    return 0;
}
