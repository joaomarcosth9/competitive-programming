#define _GLIBCXX_DEBUG

string to_string(const string& s);
string to_string(const char* s);
string to_string(const char c);
string to_string(bool b);
string to_string(__int128_t i);
string bin(long long number, int bits);
template<typename A> string to_string(A v);
template<typename T> string to_string(queue<T> q);
template<typename T> string to_string(priority_queue<T> pq);
template<typename T> string to_string(priority_queue<T, vector<T>, greater<T>> pq);
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
template <typename A, typename B, typename C, typename D, typename E> string to_string(tuple<A, B, C, D, E> p);
template <typename A, typename B, typename C, typename D, typename E, typename F> string to_string(tuple<A, B, C, D, E, F> p);

// basics
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(const char c) { string u; u += c; return '\'' + u + '\''; }
string to_string(bool b) { return (b ? "True" : "False"); }
string to_string(__int128_t i) {
    string ret;
    while (i) {
        ret += char((i % 10) + '0');
        i /= 10;
    }
    reverse(begin(ret), end(ret));
    return ret;
}

// binario
string bin(long long number, int bits = 16){ string binary = ""; while(bits--){ binary.push_back((number & 1)+'0'); number >>= 1; } reverse(begin(binary), end(binary)); return binary; }

// iteravel
template<typename A> string to_string(A v) { bool first = true; string res = "{"; for (const auto &x : v) { if (!first) { res += ", "; } first = false; res += to_string(x); } res += "}"; return res; }

// queue
template<typename T> string to_string(queue<T> q){ string res = "{"; while(!q.empty()){ res += to_string(q.front()); q.pop(); if(!q.empty()) res += ", "; } res += "}"; return res; }

// priority_queue
template<typename T> string to_string(priority_queue<T> pq){ string res = "{"; while(!pq.empty()){ res += to_string(pq.top()); pq.pop(); if(!pq.empty()) res += ", "; } res += "}"; return res; }
template<typename T> string to_string(priority_queue<T, vector<T>, greater<T>> pq){ string res = "{"; while(!pq.empty()){ res += to_string(pq.top()); pq.pop(); if(!pq.empty()) res += ", "; } res += "}"; return res; }

// array
template<typename T> vector<T> vec(T* arr, int n = 10){ vector<T> temp; for(int it = 0; it < n; it++){ temp.emplace_back(arr[it]); } return temp; }

//pair
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

// tuplas
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
template <typename A, typename B, typename C, typename D, typename E> string to_string(tuple<A, B, C, D, E> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ")"; }
template <typename A, typename B, typename C, typename D, typename E, typename F> string to_string(tuple<A, B, C, D, E, F> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ", " + to_string(get<5>(p)) + ")"; }


void _debug() { }
template <typename X, typename... Y>
void _debug(X head, Y... tail) {
    if(sizeof...(tail)) {
        cerr << to_string(head); cerr << ", "; _debug(tail...);
    } else {
        cerr << to_string(head);
    }
}

#define debug(x...) cerr << "[" << #x << "] = [", _debug(x), cerr << "]" << endl
