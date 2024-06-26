#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int v; cin >> v;
    string r; cin >> r;
    int n = 0, s = 0, e = 0, w = 0;

    for (auto c: r) {
        if (c == 'N') n++;
        if (c == 'S') s++;
        if (c == 'E') e++;
        if (c == 'W') w++;
    }

    /* cout << "N -> " << n << endl; */
    /* cout << "s -> " << s << endl; */
    /* cout << "e -> " << e << endl; */
    /* cout << "w -> " << w << endl; */
    bool h1 = true;
    if (n > 0 || s > 0) h1 = (abs(n - s)%2 == 0 ? true : false);

    bool h2 = true;
    if (e > 0 || w > 0) h2 = (abs(w - e)%2 == 0 ? true : false);

    int k = n + s + e + w;
    bool flag = true;


    if (k == 2 && (((n == 1) && (s == 1)) || ((e == 1) && (w == 1)))) flag = false;

    if (h1 && h2 && flag) {
        int amn = n/2 + (n&1);
        int ams = s/2 + (s&1);
        int ame = e/2;
        int amw = w/2;

        /* cout << "amn -> " << amn << endl; */
        /* cout << "ams -> " << ams << endl; */
        /* cout << "ame -> " << ame << endl; */
        /* cout << "amw -> " << amw << endl; */
        string resp;
        for (int i=0; i < (int)r.size(); i++) {
            if (r[i] == 'N') {
                if (amn > 0) {
                    resp.push_back('H');
                    amn--;
                } else resp.push_back('R');
            }
            if (r[i] == 'S') {
                if (ams > 0) {
                    resp.push_back('H');
                    ams--;
                } else resp.push_back('R');
            }
            if (r[i] == 'E') {
                if (ame > 0) {
                    resp.push_back('H');
                    ame--;
                } else resp.push_back('R');
            }
            if (r[i] == 'W') {
                if (amw > 0) {
                    resp.push_back('H');
                    amw--;
                } else resp.push_back('R');
            }

        }
        cout << resp << endl;
    } else cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

