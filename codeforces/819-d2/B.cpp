#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define endl '\n'
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define _   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define _ ios_base::sync_with_stdio(0);cin.tie(0);
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define clog if (0) cerr
#   define DB(...)
#endif
template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}

void solve(){
    int n, m; cin >> n >> m;
    vi v(n);
    if(n == 1){
        cout << "Yes\n" << m << endl;
        return;
    } else if(m%n == 0){
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            cout << m/n << ' ';
        }
        cout << endl;
        return;
    } else if(n > m || n == 2){
        cout << "No\n";
        return;
    }
    if(n%2 == 0){
        if(m%2){
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for(int i = 0; i < n-2; i++){
                cout << 1 << ' ';
            }
            m -= (n-2);
            cout << (m/2) << ' ' << (m/2) << endl;
        }
    } else {
        cout << "Yes\n";
        for(int i = 0; i < n-1; i++){
            cout << 1 << ' ';
        }
        cout << (m-(n-1)) << endl;
    }
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}

