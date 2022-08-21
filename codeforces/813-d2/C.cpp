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

int n, arr[MAX];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    map<int,int> u;
    map<int,int> dfi;
    vi df(n);
    df[0] = 1;
    dfi[arr[0]]++;
    for(int i = 1; i < n; i++){
        if(!dfi[arr[i]]){
            dfi[arr[i]]++;
            df[i] = df[i-1] + 1;
        } else {
            df[i] = df[i-1];
        }
    }

    for(int i = n-1; i >= 1; i--){
        if(arr[i-1] > arr[i]){
            for(int j = i-1; j >= 0; j--){
                if(!u[arr[j]]){
                    u[arr[j]]++;
                }
            }
            break;
        }
    }
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        if(u[arr[i]]){
            res = df[i];
            break;
        }
    }
    cout << res << endl;
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        clog << db(Testcase) << endl;
        solve();
    }
    return 0;
}

