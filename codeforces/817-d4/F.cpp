#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e2;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

pair<int, int> moves[] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
vector<vector<char>> v(MAX + 10, vector<char>(MAX + 10));
vector<vector<int>> vis(MAX + 10, vector<int>(MAX + 10));
int dr;
int nn;

void check_l(int i, int j, int ii, int jj, int n) {
    vis[i][j]++;
    for (auto [a, b] : moves) {
        if (v[i + a][j + b] == '*') {
            if (!vis[i + a][j + b]) {
                // cout << "chamando pra " << i+a << ' ' << j+b << ' ' << ii << ' ' << jj << ' ' << n + 1 << endl;
                check_l(i + a, j + b, ii, jj, n + 1);
                nn++;
            }
        }
    }
    if (abs(ii - i) > 1 || abs(jj - j) > 1) {
        nn = 1e9;
    }
}

void solve() {
    dr = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) {
            v[i][j] = 0;
            vis[i][j] = 0;
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    /* for(int i = 1; i <= n; i++){ */
    /*     for(int j = 1; j <= m; j++){ */
    /*         cout << v[i][j] << ' '; */
    /*     } */
    /*     cout << endl; */
    /* } */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v[i][j] == '*') {
                // cout << "Aqui tem " << i << ' ' << j << endl;
                if (!vis[i][j]) {
                    nn = 1;
                    check_l(i, j, i, j, 1);
                    if (nn != 3) {
                        dr++;
                    }
                }
            }
        }
    }
    cout << (dr ? "NO\n" : "YES\n");
}

int main() {
    //_
    int testcase;
    cin >> testcase;
    for (int Testcase = 1; Testcase <= testcase; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
