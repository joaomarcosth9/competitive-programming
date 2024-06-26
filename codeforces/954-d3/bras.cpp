#include <bits/stdc++.h>
using namespace std;


signed main(){
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a;
        if(n == 2){
            if(s[0] != '0'){
                cout << s << '\n';
                continue;
            }else{
                cout << s[1] << '\n';
                continue;
            }
        }
        int soma = 1e8;
        for(int j = 0; j < n-1; j++){
            int m = int(s[j] - '0')*10 + int(s[j+1]-'0');
            vector<int> a;
            for(int i = 0; i < n; i++){
                if(i == j){
                    a.emplace_back(m);
                    i++;
                }else{
                    a.emplace_back(int(s[i] - '0'));
                }
            }
            
            int somac = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] == 1){
                    if(i == 0){
                        somac = 1;
                    }
                }else if(somac == 1){
                    somac = a[i];
                }
                else if((somac == 0  && i != 0) || a[i] == 0){
                    somac = 0;
                }
                else{
                    somac += a[i];
                }            
            }
            if(somac < soma){
                soma = somac;
            }
        }
        cout << soma << '\n';
    }

}
