#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[500005];

void solve(){
    int size;
    ll sum; cin >> size >> sum;
    ll count = 0;

    for (int i = 0; i < size; i++)
        cin >> A[i]; 

    for (int i = 0; i < size; i++){
        ll summ = A[i];
        int j = 1;
        while (summ <= sum && (i+j-1) != size){
            if (summ == sum){
                count++;
            }
            summ += A[i+j];
            j++;
        }
    }

    cout << count << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
