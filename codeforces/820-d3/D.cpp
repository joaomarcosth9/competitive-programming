#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define print_op(...) ostream &operator<<(ostream &out, const __VA_ARGS__ &u)
#define db(val) "[" #val " = " << (val) << "] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG
#define _
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define DB() debug_block CONCAT(dbbl, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() {
        clog << "{" << endl;
        ++__db_level;
    }
    ~debug_block() {
        --__db_level;
        clog << "}" << endl;
    }
};
#else
#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#define clog                                                                                                           \
    if (0) cerr
#define DB(...)
#endif
template <class U, class V> print_op(pair<U, V>) { return out << "(" << u.first << ", " << u.second << ")"; }
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream &>::type operator<<(ostream &out, const Con &con) {
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it) out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template <size_t i, class T> ostream &print_tuple_utils(ostream &out, const T &tup) {
    if constexpr (i == tuple_size<T>::value)
        return out << ")";
    else
        return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template <class... U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }

void solve() {
    int n;
    cin >> n;
    vi x(n);
    vi y(n);
    for (auto &a : x) cin >> a;
    for (auto &a : y) cin >> a;
    vi d(n);
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        d[i] = y[i] - x[i];
        zeros += (d[i] == 0);
    }
    sor(d);
    reverse(all(d));
    int l = 0, r = n - 1, res = 0;
    while (l < r) {
        if ((d[l] + d[r]) >= 0) {
            res++;
            l++;
            r--;
        } else {
            r--;
        }
    }
    /* for(auto a : d){ */
    /*     cout << a << ' '; */
    /* } */
    /* cout << endl; */
    cout << res << endl;
}

int main() {
    _ int tsts;
    cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
