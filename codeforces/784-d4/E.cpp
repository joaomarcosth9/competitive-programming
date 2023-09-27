#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool diffbyone(string arr1, string arr2) {
    bool p1 = (arr1[0] == arr2[0]);
    bool p2 = (arr1[1] == arr2[1]);

    if ((p1 && !(p2))) {
        return 1;
    } else if (p2 && !(p1)) {
        return 1;
    } else {
        return 0;
    }
}

string v[(int)1.1e5];

void solve() {
    int num;
    cin >> num;
    map<string, int> mp;
    for (int i = 0; i < num; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }

    ll count = 0;

    for (auto [s1, v1] : mp) {
        for (auto [s2, v2] : mp) {
            if (diffbyone(s1, s2)) {
                count += (ll)v1 * (ll)v2;
            }
        }
    }

    cout << count / 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
