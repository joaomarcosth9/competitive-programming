#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define eb emplace_back
typedef long double ld;
typedef long long ll;
const int maxn = 2005;
const ld pi = acos((ld)-1);
const ld eps = 1e-9, eps2 = 1e-6;

ll n, k;
ll f[maxn];

void out(pair<ld, ld> &p) {
	cout << p.first << " " << p.second << endl;
}

ld modulo(ld first, ld second) {
	return first * first + second * second;
}

pair<ld, ld> Ff[maxn];
pair<ld, ld> Fk[maxn];

// F[i] = Ff[i] + Fk[i];

void solve() {
	cout << setprecision(10) << fixed;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> f[i];
	f[k] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != k) {
				Ff[i].first += (ld)f[j] * cos(-2.0 * pi * i * j / (ld)n);
				Ff[i].second += (ld)f[j] * sin(-2.0 * pi * i * j / (ld)n);
			} else {
				assert(f[j] == 1);
				Fk[i].first += (ld)f[j] * cos(-2.0 * pi * i * j / (ld)n);
				Fk[i].second += (ld)f[j] * sin(-2.0 * pi * i * j / (ld)n);
			}
		}
	}

	auto res = [&] (ld x) {
		ld ret = -1e9;
		for (int i = 0; i < n; i++) {
			ret = max(ret, modulo(Ff[i].first + Fk[i].first * x, Ff[i].second + Fk[i].second * x));
		}
		return ret;
	};

	auto test = [&] (ld L) {
		ld resL = res(L);
		ld resR = res(L + eps2);
		//cout << "resL: " << resL << " | resR: " << resR << " | resL - eps: " << resL - eps2 << endl;
		if (resL - eps > resR) return 1;
		return 0;
	};

	ld l = -4e6, r = 4e6;
	while (r - l > eps) {
		ld mid = l + (r - l) / 2;
		if (test(mid) == 1) {
			l = mid;
		} else {
			r = mid;
		}
	}
	ll L = floor(l + eps);
	ll R = ceil(l - eps);
	cout << sqrt(min(res(L), res(R))) << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}
