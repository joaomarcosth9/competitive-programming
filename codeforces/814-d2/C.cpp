#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5 + 500;
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

int n, q, arr[MAX], pref[MAX];

void solve() {
    cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        pref[i] = 0;
    }
    int maior = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > arr[maior]) maior = i;
    }
    int ganhador = (arr[0] > arr[1] ? 0 : 1);
    // pref diz quanto cada lutador ganhou nas primeiras n-1 rodadas;
    pref[ganhador]++;
    for (int i = 2; i < n; i++) {
        ganhador = (arr[i] > arr[ganhador] ? i : ganhador);
        pref[ganhador]++;
    }
    /* se um jogador X (!= 0) ganhou n rodadas, com ctz foram as rodadas X, X+1,...X+n */
    /* se o jogador X = 0 ganhou n rodadas, com ctz foram as rodadas X+1, X+2,...X+n+1 */
    /* quando chegar o lutador i (indexando em 0), estamos na i-esima luta */
    /* se quero saber do lutador i ate a luta n, se n >= i, ele lutou n-i+1 */
    /* Exemplos: lutador 0 lutou a 1, e a 2 = 2, lutador 0 lutou a 1, a 2, a 3 = 3 */
    /* Exemplos: lutador 1 lutou a 1, e a 2 = 2, lutador 1 lutou a 1, a 2, a 3 e a 4 = 4 */
    /* Exemplos: lutador 2 lutou a 2, e a 3 = 2, lutador 1 lutou a 1, a 2, a 3 e a 4 = 4 */
    /* Exemplos: lutador 3 lutou a 3, e a 4 = 2, lutador 3 lutou a 3, a 4, a 5 e a 6 = 4 */
    for (int i = 0; i < q; i++) {
        int p, nr;
        cin >> p >> nr;
        p--;
        int rd = nr - p + 1;
        if (p == 0) {
            rd--;
        }
        if (p == maior) {
            cout << max(0, rd) << endl;
        } else {
            cout << max(0, (rd >= pref[p] ? pref[p] : rd)) << endl;
        }
    }
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
