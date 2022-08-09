#include <bits/stdc++.h>

using namespace std;
const int INF = 1.05e9;
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

const int MAX = 1e2+10;
int l,c;
ll M[MAX][MAX];
int mod = 31;

void solve(){
    cin >> l >> c;
    map<ll,int> Mp;
    for(int i = 0; i < l+1; i++){
        for(int j = 0; j < c+1; j++){
            if(j == c && i == l) break;
            if(j < c && i < l){
                string s; cin >> s;
                int a = s[0] - '0';
                int b = s[1] - '0';
                M[i][j] = a*(ll)pow(mod,0)+b*(ll)pow(mod,1);
            } else {
                cin >> M[i][j];
            }
        }
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            clog << M[i][j] << ' ';
        } 
        clog << endl;
    }
    for(int i = 0; i < n; i++){

    }
}

int main(){ _
    solve();
    return 0;
}

