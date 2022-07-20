#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+50;

int len;
int arr[MAX];
int ns;

void solve(){
    cin >> len >> ns; 
    int cs = 0;
    for(int i = 0; i < len; i++){
        cin >> arr[i];
        cs += arr[i];
    }
    int i = 0, j = len-1;
    int nop = 0;
    while(i!=j && cs!=ns){ 
        if(arr[i] == 1){
            cs--; i++; nop++;
        } else if (arr[j] == 1){
            cs--; j--; nop++;
        } else {
            int temp = 0;
            while(arr[i] != 1 && arr[j] != 1 && i!=j){
                temp++; i++; j--;
            }
            if(arr[i] == 1){
                j+=temp; nop+=temp;
            } else if(arr[j] == 1){
                i-=temp; nop+=temp;
            }
        }
        if(i>=j){
            break;
        }
    }
    if(cs == ns){
        cout << nop << endl;
        return;
    }
    cout << -1 << endl;
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
