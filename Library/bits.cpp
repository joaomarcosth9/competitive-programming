int ppc(int x) {
    return __builtin_popcount(x);
}
int ppc(ll x) {
    return __builtin_popcountll(x);
}
int lg(int x) {
    return 31 - __builtin_clz(x);
}
int lg(ll x) {
    return 63 - __builtin_clzll(x);
}
int clz(int x) {
    return __builtin_clz(x);
}
int clz(ll x) {
    return __builtin_clzll(x);
}
int ctz(int x) {
    return __builtin_ctz(x);
}
int ctz(ll x) {
    return __builtin_ctzll(x);
}
int all(int n) {
    return (1 << (n - 1)) + ((1 << (n - 1)) - 1);
}
