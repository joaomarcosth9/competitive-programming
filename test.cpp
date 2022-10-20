#include <bits/stdc++.h>

using namespace std;

vector<int> ft;

int sum(int i) {
    int sum = 0;
    for(; i > 0; i -= (i & -i))
        sum = sum + ft[i];
    return sum;
}
int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
void update(int i, int v) {
    for(; i > 0 && i < (int)ft.size(); i += (i & -i))
        ft[i] = v + ft[i];
}

void solve(){
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        v[i].first = i+1;
    }
    for(int i = 0; i < n; i++){
        swap(v[i].first, v[i].second);
    }
    sort(v.begin(), v.end());

    ft.assign(n+1, 0);
    int operations = 0;

    for(int i = 0; i < n; i++){
        operations += sum(v[i].second, n);
        update(v[i].second, 1);
    }
    cout << operations << endl;
}

int main(){
    solve();
    return 0;
}
