#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
typedef long long ll;

const int maxn = 2e5+5;
int v[maxn];

namespace PollardRho {
    typedef long long ll;
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int P = 1e6 + 9;
    ll seq[P];
    int primes[P], spf[P];
    inline ll add_mod(ll x, ll y, ll m) {
        return (x += y) < m ? x : x - m;
    }
    inline ll mul_mod(ll x, ll y, ll m) {
        ll res = __int128_t(x) * y % m;
        return res;
        // ll res = x * y - (ll)((long double)x * y / m + 0.5) * m;
        // return res < 0 ? res + m : res;
    }
    inline ll pow_mod(ll x, ll n, ll m) {
        ll res = 1 % m;
        for (; n; n >>= 1) {
            if (n & 1) res = mul_mod(res, x, m);
            x = mul_mod(x, x, m);
        }
        return res;
    }
    // O(it * (logn)^3), it = number of rounds performed
    inline bool miller_rabin(ll n) {
        if (n <= 2 || ((n & 1) ^ 1)) return (n == 2);
        if (n < P) return spf[n] == n;
        ll c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++) {}
        // each iteration is a round
        for (int i = 0; primes[i] < n && primes[i] < 32; i++) {
            c = pow_mod(primes[i], r, n);
            for (int j = 0; j < s; j++) {
                d = mul_mod(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1)) return false;
                c = d;
            }
            if (c != 1) return false;
        }
        return true;
    }
    void init() {
        int cnt = 0;
        for (int i = 2; i < P; i++) {
            if (!spf[i]) primes[cnt++] = spf[i] = i;
            for (int j = 0, k; (k = i * primes[j]) < P; j++) {
                spf[k] = primes[j];
                if (spf[i] == spf[k]) break;
            }
        }
    }
    // returns O(n^(1/4))
    ll pollard_rho(ll n) {
        while (1) {
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while (1) {
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if ((x = *px++) == y) break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if (!u) return gcd(v, n);
                if (++t == 32) {
                    t = 0;
                    if ((u = gcd(u, n)) > 1 && u < n) return u;
                }
            }
            if (t && (u = gcd(u, n)) > 1 && u < n) return u;
        }
    }
    vector<int> factorize(int n) {
        if (n == 1) return vector <int>();
        if (miller_rabin(n)) return vector<int> {n};
        vector <int> v, w;
        while (n > 1 && n < P) {
            v.push_back(spf[n]);
            n /= spf[n];
        }
        if (n >= P) {
            ll x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }
}

vector<int> get_divs(int n) {
    vector<int> facts = PollardRho::factorize(n);
    sort(facts.begin(), facts.end());
    vector<pair<int, int>> facts2;
    for (int x : facts) {
        if (facts2.empty() || facts2.back().first != x) {
            facts2.emplace_back(x, 1);
        } else {
            facts2.back().second++;
        }
    }
    for(auto& [_, e] : facts2) {
        e >>= 1;
    }
    vector<int> divs;
    function<void(int, int)> dfs = [&](int i, int cur) {
        if (i == (int)facts2.size()) {
            divs.push_back(cur);
            return;
        }
        int p = 1;
        for (int j = 0; j <= facts2[i].second; j++) {
            dfs(i + 1, cur * p);
            p *= facts2[i].first;
        }
    };
    dfs(0, 1);
    return divs;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    map<int,ll> freq;
    for(int i = 0; i < n; i++){
        freq[v[i]]++;
    }

    ll res = 0;


    for(auto [u, f] : freq){

        auto divs = get_divs(u);
        db(u, divs);

        if(f > 2) res += f * (f-1) * (f-2);

        for(auto b : divs){
            if(b == 1) continue;
            int sq = b * b;
            auto f1 = freq.find(u / b);
            auto f2 = freq.find(u / sq);
            if(f1 != freq.end() && f2 != freq.end()){
                res += f * (f1->second) * (f2->second);
            }
        }
    }

    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    PollardRho::init();
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
