#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+40;
int arr[MAX];
int sums[MAX];

void solve(){
    int n; cin >> n; 
    for (int i = 0; i < n; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        arr[t%10]++;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if((i+j+k) % 10 == 3){
                    if(i==j && j==k && arr[i]>=3){
                        cout << "YES\n";
                        return;
                    } else if(i==j && arr[i]>=2){
                        cout << "YES\n";
                        return;
                    } else if (i==k && arr[i]>=2){
                        cout << "YES\n";
                        return;
                    } else if (j==k && arr[j]>=2){
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
