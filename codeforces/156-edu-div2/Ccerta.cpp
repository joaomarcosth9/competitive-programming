#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define int long long

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

using ll = long long;
using pi = pair<ll,ll>;
using pl = pair<ll,ll>;
using vi = vector<ll>;
using vl = vector<ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MAXN = 2e5 + 5;
const ll MOD = 1e9+7; //998244353;
const ll INF = 0x3f3f3f3f;
const ll INF64 = ll(4e18) + 5;

void solve(){
	string s;
	cin >> s;
	ll pos;
	cin >> pos;
	ll n = s.size();
	ll tam = n;
	ll ite = 0;
	while(pos > tam){
		ite++;
		pos -= tam;
		tam--;
	}
	ll rem = ite;
	string t;
	for(ll i = 0; i < n; i++){
		while(!t.empty() && t.back() > s[i] && rem){
			rem--;
			t.pop_back();
		}
		t += s[i];
	}
	pos--;
	cout << t[pos];

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    ll t = 1;
    cin >> t;
    for(ll i = 0; i < t; i++){
		solve();
    }
	cout << '\n';

    return 0;
}

/*
Makefile:
CXXFLAGS=-Wall -Wextra -Wshadow -g -pedantic -fsanitize=address,undefined -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUGPEDANTIC -std=gnu++17
*/

