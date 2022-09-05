#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
const int MAX = 1e5;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
    int n; cin >> n; string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < (int) s.size(); i++){
        if(s[i] == 'L'){
            v[i] = i;
        } else if (s[i] == 'R'){
            v[i] = n - i - 1;
        }
    }
    ll sum = 0;
    for(auto i : v){
        sum += i;
    }
    vector<int> ch(n);
    for(int i = 0; i < n/2; i++){
        if(s[i] == 'L'){
            ch[i] = (n - i - 1) - i;
        }
    }
    for(int i = n/2; i < n; i++){
        if(s[i] == 'R'){
            ch[i] = i - (n - i - 1);
        }
    }
    clog << db(s) << endl;
    clog << db(v) << endl;
    clog << db(ch) << endl;
    sort(ch.begin(), ch.end());
    for(int i = n-1; i >= 0; i--){
        cout << sum + ch[i] << ' ';
        sum += ch[i];
    }
    cout << endl;
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        clog << db(Testcase) << endl;
        solve();
    }
    return 0;
}

