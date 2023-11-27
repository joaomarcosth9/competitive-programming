#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

template<class T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
using ii = pair<int, int>;
using ll = long long;
using i3 = tuple<int, int, int>;
 
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define loop(ii, n) for (int ii = 0; ii < (n); ii++)
#define cond(c, t, f) ((c) ? (t) : (f))
#define mem(a, b) memset((a), (b), sizeof(a))
#define inbounds(x, l, r) ((l) <= (x) && (x) <= (r))
#define L1(res...) [&](auto x){ return res; }
#define L2(res...) [&](auto x, auto y){ return res; }
 
template<class T, class U> auto &operator>>(istream &is, pair<T, U> &p) { return is >> p.ff >> p.ss; }
template<class T, class U> auto &operator<<(ostream &os, pair<T, U> const& p) { return os << '(' << p.first << ' ' << p.second << ')'; }
 
const string ES = "", SEP = " ";
template<class T> auto &operator>>(istream& is, vector<T> &c) { for (auto &x : c) is >> x; return is; }
template<class T> auto &operator<<(ostream& os, vector<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, multiset<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, unordered_set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, deque<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class K, class V> auto &operator<<(ostream& os, map<K,V> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class K, class V> auto &operator<<(ostream& os, unordered_map<K,V> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
 
template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { auto sep = ES; ((cout << sep << a, sep = SEP), ...); cout << '\n'; }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
#define var(x) "[", #x, " ", x, "] "
template<class... A> void db(A const&... a) { ((cout << (a)), ...); cout << endl; }
//}}}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll integer(ll l, ll r) {
    uniform_int_distribution<ll> uid(l, r);
    return uid(rng);
}

const int SIEVE_SIZE = 1e6 + 5;
vector<int> primes;
int spf[SIEVE_SIZE];
bool prime[SIEVE_SIZE];
void linear_sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i < SIEVE_SIZE; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.emplace_back(i);
            prime[i] = true;
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] < SIEVE_SIZE && primes[j] <= spf[i]; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

vector<ll> random_array(ll n, ll l, ll r) {
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        a[i] = integer(l, r);
    }
    return a;
}

vector<ll> random_permutation(ll n) {
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) a[i] = i + 1;
    shuffle(all(a), rng);
    return a;
}

void print_random_tree(ll n, bool weighted = false) {
    int root = 1;
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        p[i] = integer(1, i - 1);
        int w = weighted ? integer(1, 1000) : 0;
        if (w) out(p[i], i, w);
        else out(p[i], i);
    }
}

void print_random_graph(ll n, ll m, bool weighted = false) {
    m = max(m, n - 1);
    m = min(m, n * (n - 1) / 2);
    vector<i3> edges;
    vector<map<int, bool>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p = integer(1, i - 1);
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(p, i, w);
        adj[p][i] = adj[i][p] = true;
    }
    for (int i = 0; i < m - (n - 1); i++) {
        int u = integer(1, n), v = integer(1, n);
        while (u == v || adj[u][v]) {
            u = integer(1, n), v = integer(1, n);
        }
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(u, v, w);
        adj[u][v] = adj[v][u] = true;
    }
    shuffle(all(edges), rng);
    out(n, m);
    for (auto [u, v, w] : edges) {
        if (weighted) out(u, v, w);
        else out(u, v);
    }
}

void print_random_directed_graph(ll n, ll m, bool weighted = false) {
    m = max(m, n - 1);
    m = min(m, n * (n - 1));
    vector<i3> edges;
    vector<map<int, bool>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p = integer(1, i - 1);
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(p, i, w);
        adj[p][i] = true;
    }
    for (int i = 0; i < m - (n - 1); i++) {
        int u = integer(1, n), v = integer(1, n);
        while (u == v || adj[u][v]) {
            u = integer(1, n), v = integer(1, n);
        }
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(u, v, w);
        adj[u][v] = true;
    }
    shuffle(all(edges), rng);
    out(n, m);
    for (auto [u, v, w] : edges) {
        if (weighted) out(u, v, w);
        else out(u, v);
    }
}

void print_random_functional_graph(ll n, ll m, bool weighted = false) {
    m = max(m, n - 1);
    m = min(m, n * (n - 1) / 2);
    vector<i3> edges;
    vector<bool> used(n + 1);
    for (int i = 2; i <= n; i++) {
        int p = integer(1, i - 1);
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(p, i, w);
        used[p] = true;
    }
    for (int i = 0; i < m - (n - 1); i++) {
        int u = integer(1, n), v = integer(1, n);
        while (u == v || used[u]) {
            u = integer(1, n), v = integer(1, n);
        }
        int w = weighted ? integer(1, 1000) : 0;
        edges.eb(u, v, w);
        used[u] = true;
    }
    shuffle(all(edges), rng);
    out(n, m);
    for (auto [u, v, w] : edges) {
        if (weighted) out(u, v, w);
        else out(u, v);
    }
}

void print_random_string(ll n, string alphabet) {
    string s;
    for (int i = 0; i < n; i++) {
        s += alphabet[integer(0, alphabet.size() - 1)];
    }
    out(s);
}

void print_random_string(ll n, int sigma) {
    string s;
    for (int i = 0; i < n; i++) {
        s += char(integer(0, sigma - 1) + 'a');
    }
    out(s);
}

void print_random_string(ll n, char l, char r) {
    string s;
    for (int i = 0; i < n; i++) {
        s += char(integer(l, r));
    }
    out(s);
}

ll random_prime(ll l, ll r) {
    if (primes.empty()) linear_sieve();
    int i = lower_bound(all(primes), l) - primes.begin();
    int j = upper_bound(all(primes), r) - primes.begin();
    i = max(i, 0), j = min(j, (int)primes.size() - 1);

    return primes[integer(i, j - 1)];
}

void random_lr_queries(ll q, ll l, ll r) {
    for (int i = 0; i < q; i++) {
        int L = integer(l, r), R = integer(l, r);
        if (L > R) swap(L, R);
        out(L, R);
    }
}

void test_case() {
    int t = 1000;
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        ll n = integer(1, 100);
        print_random_string(n, 26);
        cout << integer(1, (n * (n + 1)) / 2) << endl;
    }
}

int main(int argc, char* argv[]) {
    int TC = 0;
    /* if (TC) { cin >> TC; */ 
    /*     while (TC--) test_case(stoi(argv[1])); */
    /* } else test_case(stoi(argv[1])); */
    test_case();
}
