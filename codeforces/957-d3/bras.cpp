#include <bits/stdc++.h>
using namespace std;


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        int n, m , k; cin >> n >> m >> k;
        string s;cin >> s;
        bool flag = 0;
        int p = -1;
        for(int i = m-1; i >= 0 ; i--){
            if(i >= n){
                p = n;
                flag = 1;
                break;
            }else if(s[i] == 'C'){
                continue;
            }else if(s[i] == 'L'){
                p = i;
                break;
            }
        }
        if(p == -1){
            for(int i = m-1; i >= 0; i--){
                if(i < n && s[i] == 'W'){
                    p = i;
                    break;
                }
            }
        }
        if(p == -1){
            p = n;
        }
        for(int i = p; i < n; i++){
            if(s[i] == 'L'){
                bool flag2 = 1;
                for(int j = i+m; j >= i+1; j--){
                    if(j >= n){
                        flag = 1;
                        flag2 = 0;
                        i = n+1;
                        break;
                    }else if(s[j] == 'L'){
                        i = j-1;
                        flag2 = 0;
                        break;
                    }
                }
                if(flag2){
                    for(int j = i+m; j >= i+1; j--){
                        if(s[j] == 'W'){
                            i = j-1;
                            flag2 = 0;
                            break;
                        }
                    }
            }
            if(flag2){
                break;
            }
            }
            else if(s[i] == 'W'){
                k--;
                if(i + 1 == n){
                    flag = 1;
                }
            }else if(s[i] == 'C'){
                break;
            }
        }
        if(flag && k >= 0){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
}
