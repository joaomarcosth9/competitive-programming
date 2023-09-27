#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define endl '\n'

int s, a, b;

int sd(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

void solve() {
    cin >> s >> a >> b;
    vector<int> v;
    for (int i = a; i <= b; i++) {
        if (sd(i) == s) v.push_back(i);
    }
    cout << v[0] << endl << v[v.size() - 1] << endl;
}

int main() {
    solve();
    return 0;
}
