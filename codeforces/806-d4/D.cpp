#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
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

const int MAX = 1e5;
int number = 97, n;
string strs[MAX];
int res[MAX];

ll strhash(string s) {
    int len = s.size();
    ll hash = 0;
    for (int i = 0; i < len; i++) {
        hash += s[i] * pow(number, i);
    }
    return hash;
}

void solve() {
    memset(res, 0, sizeof(res));
    cin >> n;
    map<ll, int> M;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        M[strhash(strs[i])] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int k = 1; k < (int)strs[i].size(); k++) {
            string str1 = strs[i].substr(0, k);
            string str2 = strs[i].substr(k, (int)strs[i].size());
            if (M[strhash(str1)] && M[strhash(str2)]) {
                res[i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
    cout << endl;
}

int main() {
    _ int tsts;
    cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        clog << db(Testcase) << endl;
        solve();
    }
    return 0;
}
