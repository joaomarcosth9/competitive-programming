#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e2;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
    
    vector<pair<int,int>> Np;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        Np.push_back({a,b});
    }

    int res = (1 << n)-1;
    for(int j = 1; j <= (1 << n)-1; j++){
        vector<int> Pm;
        for(int i = 1; i <= n; i++){
            if((1 << (i-1)) & j) Pm.push_back(i);
        }

        clog << db(Pm) << endl;
        
        int dmr = 0;
        for(int k = 0; k < m; k++){
            int dr = 0;
            if(dmr) break;
            auto [a,b] = Np[k];
            for(int i = 0; i < (int)Pm.size(); i++){
                if(Pm[i] == a || Pm[i] == b){
                    dr++;
                    if(dr == 2){
                        dmr = 1;
                        res--;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
