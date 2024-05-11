#include <bits/stdc++.h> 
#define int ll
#define endl '\n'

using namespace std; 
using ll = long long;

const int maxn = 1e6 + 500; 
int sieve[maxn], divs[maxn]; 
vector<int> primes;

vector<int> factorize(int n) {
	vector<int> ret; 
	while (n > 1) {
		ret.emplace_back(divs[n]); 
		n /= divs[n]; 
	} 
	return ret; 
} 

void get_divs(int pos, vector<pair<int, int>>& facts, vector<int>& divs, int cur = 1) {
	if (pos == (int)facts.size()) {
		divs.emplace_back(cur); 
		return; 
	} 

	int tm = 1; 
	for (int j = 0; j <= facts[pos].second; j++) {
		get_divs(pos+1, facts, divs, cur * tm); 
		tm = tm * facts[pos].first; 
	} 
} 
vector<int> get_divs(int n) {
	vector<int> facts = factorize(n); 
	//reverse(facts.begin(), facts.end()); 
	vector<pair<int, int>> F; 
	int last = -1; 
	for (int i = 0; i < (int)facts.size(); i++) {
		if (last == facts[i]) F.back().second++; 
		else F.emplace_back(facts[i], 1); 
		last = facts[i]; 
	} 
	vector<int> divs; 
	get_divs(0, F, divs, 1); 
	return divs; 
} 

const int INF = 2e9;
struct frac {
	int n, d; 
	frac(int _n, int _d) : n(_n), d(_d) {}
	bool operator<(const frac& o) const {
		return 1ll * n * o.d < 1ll * d * o.n; 
	} 
};  

frac solve(int n, vector<int> &a, int d) {
	frac ret = {INF, 0};
	if (d == 1) return ret;

	vector<int> g(d);
	int group = 1;
	for (int i = 1; i < n; i++) {
		g[group] += a[i];
		group++;
		if (group == d) group = 0;
	}
	//cout << "n & d: " << n << " " << d << endl;
    multiset<pair<int, int>> st;
	for (int i = 0; i < d; i++) {
		//cout << g[i] << " ";
        st.insert({g[i], i});
	}
	//cout << endl;

	int next = 0;
    
	for (int i = 0; i < n; i++) {
        st.erase(st.find({g[next], next}));
        auto mx = st.rbegin()->first;
        auto mn = st.begin()->first;

		frac now = {max(mx, g[next] + a[0]), min(mn, g[next] + a[0])};
		ret = min(ret, now);

		int nnext = next + 1;
		if (nnext == d) nnext = 0;
		if (i < n - 1) {
			g[next] += a[i + 1];
            st.erase(st.find({g[nnext], nnext}));
			g[nnext] -= a[i + 1];
            st.insert({g[nnext], nnext});
		}
        st.insert({g[next], next});

		next = nnext;
	}

	return ret;
}

void solve() {
	int n; cin >> n;
	int a0; cin >> a0;
	vector<int> a(n); 
	for (int i = 1; i < n; i++) cin >> a[i];

	auto D = factorize(n); 
    sort(D.begin(), D.end());
    D.erase(unique(D.begin(), D.end()), D.end());

	frac best = {INF, 0};

	a[0] = a0;
	for (int d : D) {
		best = min(best, solve(n, a, d));
	} 
	int g = gcd(best.n, best.d);
	cout << best.n / g << " " << best.d / g << endl;
} 

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

    for (int i = 2; i < maxn; i++) {
        if (sieve[i]) continue;
        for (int j = i; j < maxn; j += i) {
            sieve[j] = i;
            if (divs[j] == 0) divs[j] = i;
        }
    }

	int tt; cin >> tt; while (tt--) solve(); 
} 
