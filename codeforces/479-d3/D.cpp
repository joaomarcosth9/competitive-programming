#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e2;
typedef long long ll;

int n, root, Adj[MAX];
ll arr[MAX];
map<int, int> vis;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (arr[j] == arr[i] * 2) {
                Adj[i] = j;
                vis[j] = 1;
            } else if (arr[i] % 3 == 0 && arr[j] == arr[i] / 3) {
                Adj[i] = j;
                vis[j] = 1;
            }
        }

    for (int i = 1; i <= n; i++)
        if (!vis[i]) root = i;

    int next = root;
    int c = 0;
    while (1) {
        cout << arr[next] << ' ';
        next = Adj[next];
        c++;
        if (c == n) break;
    }
    cout << endl;
}

int main() {
    _ solve();
    return 0;
}
