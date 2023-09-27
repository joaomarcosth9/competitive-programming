#include <bits/stdc++.h>

using namespace std;

int n;

const int MAX = 1e4 + 50;

int D[MAX];
int E[MAX];

int pairs;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        char pe;
        cin >> num >> pe;
        if (pe == 'D') {
            D[num]++;
        } else if (pe == 'E') {
            E[num]++;
        }
    }
    for (int i = 0; i < MAX; i++) {
        pairs += min(D[i], E[i]);
    }
    cout << pairs << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
