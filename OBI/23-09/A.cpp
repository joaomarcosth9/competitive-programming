#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int t = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 5 == 0 && t == -1) {
            t = i;
        }
    }
    if (t != -1) {
        swap(v[t], v[n - 1]);
        for (int i = 0; i < n; i++) cout << v[i] << ' ';
        cout << endl;
    } else {
        cout << t << endl;
    }
}
