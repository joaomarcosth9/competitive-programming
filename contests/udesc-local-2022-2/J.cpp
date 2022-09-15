#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    string s;
    int n;
    cin >> s >> n;
    int st = 0; int fn = s.size()-1;
    while(n--){
        int a,b; cin >> a >> b;
        st += a;
        fn = st+b-1;
    }
    for(int i = st; i <= fn; i++){
        cout << s[i];
    }
    cout << endl;
}

int main(){ _
    solve();
    return 0;
}
