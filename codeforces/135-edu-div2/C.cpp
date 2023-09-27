#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
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

int dl(int n) { return (int)log10(n) + 1; }

void printpq(priority_queue<ii> pq) {
    while (!pq.empty()) {
        cout << "(" << pq.top().first << ',' << pq.top().second << ")"
             << " ";
        pq.pop();
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vi v1(n);
    vi v2(n);
    for (auto &a : v1) cin >> a;
    for (auto &a : v2) cin >> a;
    map<int, int> m1;
    map<int, int> m2;
    for (auto a : v1) m1[a]++;
    for (auto a : v2) m2[a]++;
    for (auto a : v1) {
        if (m2[a]) {
            m1[a]--;
            m2[a]--;
        }
    }
    vi nv1;
    vi nv2;
    for (auto [k, v] : m1) {
        for (int i = 0; i < v; i++) {
            nv1.push_back(k);
        }
    }
    for (auto [k, v] : m2) {
        for (int i = 0; i < v; i++) {
            nv2.push_back(k);
        }
    }
    priority_queue<ii> pq;
    for (int i = 0; i < (int)nv1.size(); i++) {
        pq.emplace(nv1[i], 1);
    }
    for (int i = 0; i < (int)nv2.size(); i++) {
        pq.emplace(nv2[i], 2);
    }
    /* printpq(pq); */
    map<ii, int> trm;
    int nop = 0;
    while (!pq.empty()) {
        if (trm[pq.top()]) {
            trm[pq.top()]--;
            pq.pop();
            continue;
        }
        auto [v, o] = pq.top();
        if (v == 1) {
            break;
        }
        nop++;
        if (o == 1) {
            m1[v]--;
            v = dl(v);
            if (!m2[v]) {
                pq.emplace(v, 1);
                m1[v]++;
            } else {
                m2[v]--;
                pair<int, int> trmm = {v, 2};
                trm[trmm]++;
            }
        } else {
            m2[v]--;
            v = dl(v);
            if (!m1[v]) {
                pq.emplace(v, 2);
                m2[v]++;
            } else {
                m1[v]--;
                pair<int, int> trmm = {v, 1};
                trm[trmm]++;
            }
        }
        /* printpq(pq); */
        pq.pop();
    }
    cout << nop << endl;
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
