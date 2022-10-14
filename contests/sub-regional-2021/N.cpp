#include <bits/stdc++.h>
using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<int,int>;
template <typename T> using pql = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x)) 
#define rsor(x) sort(rall(x)) 
#define pb push_back
#define eb emplace_back
#define FOR(x,y) for(int i = x; i < y; i++)
#define FO(y) FOR(0,y)
#ifdef LOCAL_DEBUG   
#define endl '\n'
#   define _   
#else
#   define _ ios_base::sync_with_stdio(0);cin.tie(0);
#endif

const int neutral = 0;
#define comp(a, b) ((a)+(b))

class fenwick {
private:
	vector<int> ft;
public:
	fenwick(int n) { ft.assign(n + 1, 0); }
	int rsq(int i) { // returns RSQ(1, i)
		int sum = neutral;
		for(; i; i -= (i & -i))
			sum = comp(sum, ft[i]);
		return sum;
	}
	int rsq(int i, int j) {
		return rsq(j) - rsq(i - 1);
	}
	void update(int i, int v) {
		for(; i > 0 && i < (int)ft.size(); i += (i & -i))
			ft[i] = comp(v, ft[i]);
	}
};

const int MAX = 3e5+500;
fenwick ftl(MAX);
fenwick ftr(MAX);
int v[MAX];
int freq[MAX];



void solve(){
    int n, q; cin >> n >> q;
    vector<pair<ii,int>> queries;
    FO(n) cin >> v[i];
    FO(q){
        int s,r,o; cin >> s >> r >> o;
        queries.eb(mp(s, s+o-1), r);
    }
    sor(queries);
    FO(q){
        auto [a,b] = queries[i];
        auto [k,kk] = a;
        cout << k << '-' << kk << ',' << b << endl;
    }
    int j = 0;
    FO(n){
        freq[v[i]]++;
        ft.update(v[i], 1);
        /* int aaa; cin >> aaa; */
        /* cout << ft.rsq(aaa) << endl; */
    }
}

int main(){ _
    int tsts = 1;
    if(temtestcase) cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
