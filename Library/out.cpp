#include <bits/stdc++.h>

using namespace std;

string to_string(const string& s);
string to_string(const char* s);
string to_string(const char c);
string to_string(bool b);
string to_string(__int128_t i);
template<size_t TAM> string to_string(bitset<TAM> v);
string bin(long long number, int bits);
template<typename A> string to_string(A v);
template<typename T> string to_string(queue<T> q);
template<typename T> string to_string(priority_queue<T> pq);
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);

string to_rev_string(const string& s);
string to_rev_string(const char* s);
template<size_t TAM> string to_rev_string(bitset<TAM> v);
string bin(long long number, int bits);
template<typename A> string to_rev_string(A v);
template<typename T> string to_rev_string(queue<T> q);
template<typename T> string to_rev_string(priority_queue<T> pq);
template <typename A, typename B> string to_rev_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_rev_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_rev_string(tuple<A, B, C, D> p);

string to_string(bool b) { return (b ? "YES" : "NO"); }
string to_string(__int128_t i){ return to_string((long long)(i)); }
template<typename A> string to_string(A v) { bool first = true; string res; for (const auto &x : v) { if (!first) { res += " "; } first = false; res += to_string(x); } return res; }
template<size_t TAM> string to_string(bitset<TAM> v) { string res = ""; for(size_t i = 0; i < TAM; i++) res += char('0' + v[i]); return res; }
template<typename T> string to_string(queue<T> q){ string res; while(!q.empty()){ res += to_string(q.front()); q.pop(); if(!q.empty()) res += " "; }; return res; }
template<typename T> string to_string(priority_queue<T> pq){ string res; while(!pq.empty()){ res += to_string(pq.top()); pq.pop(); if(!pq.empty()) res += " "; }; return res; }
template <typename A, typename B> string to_string(pair<A, B> p) { return to_string(p.first) + " " + to_string(p.second); }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return to_string(get<0>(p)) + " " + to_string(get<1>(p)) + " " + to_string(get<2>(p)); }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return to_string(get<0>(p)) + " " + to_string(get<1>(p)) + " " + to_string(get<2>(p)) + " " + to_string(get<3>(p)); }

template<typename A> string to_rev_string(A v) { bool first = true; string res; for (auto it = v.rbegin(); it != v.rend(); it++) { if (!first) { res += " "; } first = false; res += to_string(*it); } return res; }
template<size_t TAM> string to_rev_string(bitset<TAM> v) { string res = to_string(v); reverse(begin(res), end(res)); return res; }
template<typename T> string to_rev_string(queue<T> q){ string res; vector<T> v; while(!q.empty()){ v.push_back(q.front()); q.pop(); }; reverse(begin(v), end(v)); for(auto x : v){ res += to_string(x); if(x != v.back()) res += " "; }; return res; }
template<typename T> string to_rev_string(priority_queue<T> pq){ string res; vector<T> v; while(!pq.empty()){ v.push_back(pq.top()); pq.pop(); }; reverse(begin(v), end(v)); for(auto x : v){ res += to_string(x); if(x != v.back()) res += " "; }; return res; }
template <typename A, typename B> string to_rev_string(pair<A, B> p) { return to_string(p.second) + " " + to_string(p.first); }
template <typename A, typename B, typename C> string to_rev_string(tuple<A, B, C> p) { return to_string(get<2>(p)) + " " + to_string(get<1>(p)) + " " + to_string(get<0>(p)); }
template <typename A, typename B, typename C, typename D> string to_rev_string(tuple<A, B, C, D> p) { return to_string(get<3>(p)) + " " + to_string(get<2>(p)) + " " + to_string(get<1>(p)) + " " + to_string(get<0>(p)); }

void _out() { }
template <typename X, typename... Y>
void _out(X first, Y... last) { cout << to_string(first) << "\n"; _out(last...); }
void _rout() { }
template <typename X, typename... Y>
void _rout(X first, Y... last) { cout << to_rev_string(first) << "\n"; _rout(last...); }
#define out(...) _out(__VA_ARGS__)
#define rout(...) _rout(__VA_ARGS__)
