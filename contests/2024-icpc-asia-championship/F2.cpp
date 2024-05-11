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

template<typename T, auto OP> struct op_queue {
	vector<pair<T, T>> st1, st2;
	T get() {
		if (st1.empty()) {
			return st2.back().first;
		}
		if (st2.empty()) {
			return st1.back().first;
		}
		return OP(st1.back().first, st2.back().first);
	}
	void add(T element) {
		if (st1.empty()) {
			st1.push_back({element, element});
		} else {
			st1.push_back({OP(element, st1.back().first), element});
		}
	}
	void remove() {
		if (st2.empty()) {
			while (!st1.empty()) {
				auto element = st1.back().second;
				if (st2.empty()) {
					st2.push_back({element, element});
				} else {
					st2.push_back({OP(element, st2.back().first), element});
				}
				st1.pop_back();
			}
		}
		st2.pop_back();
	}
};

frac solve(int n, vector<int> &a, int d) {
	frac ret = {INF, 0};
	if (d == 1) return ret;

	op_queue<int, [&] (int x, int y) { return min(x, y); }> q1;
	op_queue<int, [&] (int x, int y) { return max(x, y); }> q2;

	vector<int> g(d);
	int group = 1;
	for (int i = 1; i < n; i++) {
		g[group] += a[i];
		group++;
		if (group == d) group = 0;
	}
	//cout << "n & d: " << n << " " << d << endl;
	for (int i = 0; i < d; i++) {
		//cout << g[i] << " ";
		q1.add(g[i]);
		q2.add(g[i]);
	}
	//cout << endl;

	int next = 0;

	for (int i = 0; i < n; i++) {
		q1.remove();
		q2.remove();
		auto mn = q1.get();
		auto mx = q2.get();

		frac now = {max(mx, g[next] + a[0]), min(mn, g[next] + a[0])};
		ret = min(ret, now);

		int nnext = next + 1;
		if (nnext == d) nnext = 0;
		if (i < n - 1) {
			g[next] += a[i + 1];
			g[nnext] -= a[i + 1];
		}

		q1.add(g[next]);
		q2.add(g[next]);

		next = nnext;
	}

	return ret;
}

void solve() {
	int n; cin >> n;
	int a0; cin >> a0;
	vector<int> a(n); 
	for (int i = 1; i < n; i++) cin >> a[i];

	auto D = get_divs(n); 

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
        if (sieve[i] == 0) {
            primes.emplace_back(i);
            divs[i] = i;
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] < maxn; j++) {
            sieve[i * primes[j]] = 1;
            divs[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }

	int tt; cin >> tt; while (tt--) solve(); 
} 

