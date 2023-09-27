#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
const int inf = 2e9;
int n;
string s;
const int maxn = 105;
array<array<int, maxn * maxn>, maxn> dp;
// n ^ 4 dp

void solve() {
	cin >> s; n = s.size();
	s = "#" + s;
	for (int i = 0; i <= n; i++) {
        fill(begin(dp[i]), end(dp[i]), inf);
    }
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
        auto new_dp = dp;
        for (int j = 0; j <= i; j++) {
            fill(begin(new_dp[j]), end(new_dp[j]), inf);
        }
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= (i - j) * j; k++) {
				if (j > 0) new_dp[j][k] = min(new_dp[j][k], dp[j - 1][k] + (s[i] != '0'));
				if (k >= j) new_dp[j][k] = min(new_dp[j][k], dp[j][k - j] + (s[i] != '1'));
			}
		}
        dp = new_dp;
	}
	int cnt0 = count(begin(s), end(s), '0');
	int cnt1 = n - cnt0;
	int need = (cnt0 * cnt1) / 2;
	cout << dp[cnt0][need] / 2 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
