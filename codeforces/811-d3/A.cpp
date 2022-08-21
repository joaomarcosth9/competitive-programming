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
;
const int MAX = 15;
pair<int,int> D[MAX];

pair<int,int> diff_time(pair<int,int> A, pair<int,int> B){
    pair<int,int> dff;
    auto [h,m] = A;
    auto [H,M] = B;
    int dm = M-m;
    if(H < h) H+=24;
    dff.first = (H-h)%24;
    if(dm >= 0){
        dff.second = dm;
    } else {
        dff.second = 60+dm;
        if (dff.first){
            dff.first--;
        } else {
            dff.first = 23;
        }
    }
    //cout << dff.first << ' ' << dff.second << endl;
    return dff;
}

void solve(){
    pair<int,int> res;
    vector<pair<int,int>> diffs;
    int n, h, m; cin >> n >> h >> m;
    pair<int,int> sl = {h,m};
    pair<int,int> next;
    for(int i = 0; i < n; i++){
        cin >> D[i].first >> D[i].second;
    }
    for(int i = 0; i < n; i++){
        diffs.push_back(diff_time(sl, D[i]));
    }
    sort(begin(diffs),end(diffs));
    cout << diffs[0].first << ' ' << diffs[0].second << endl;
}

int main(){ _
    int tsts; cin >> tsts;
    for(int Testcase = 1; Testcase <= tsts; Testcase++){
        //clog << db(Testcase) << endl;
        solve();
    }
    return 0;
}
