#include <bits/stdc++.h>

using namespace std;

int is_palindrome(int a, int b){
    int fsb = b / 10;
    int snb = b % 10;
    if(a == (fsb+snb)){
        return 1;
    }
    return 0;
}

int horas[2];
int gap;

void solve(){
    string s; cin >> s;
    horas[0] = 0; horas[1] = 0;
    cin >> gap;
    horas[0] += (s[0]-48) * 10;
    cout << horas[0] << ' ';
    horas[0] += (s[1]-48);
    cout << horas[0] << ' ';
    horas[1] += (s[3]-48) * 10;
    cout << horas[1] << ' ';
    horas[1] += (s[4]-48);
    cout << horas[1] << ' ';
    cout << endl;
    cout << "Horas: " << horas[0] << ' ' << horas[1] << endl;
    cout << is_palindrome(horas[0], horas[1]) << endl;
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
