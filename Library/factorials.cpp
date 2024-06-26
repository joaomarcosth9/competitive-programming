template<typename T = mint> struct Factorials {
    vector<T> fact, ifact;
    Factorials(int n): fact(n + 1), ifact(n + 1) {
        fact[0] = T(1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = T(1) / fact[n];
        for (int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    T operator()(int n) const { return fact[n]; }
    T inv(int n) const { return ifact[n]; }
};

const int N = 1e6 + 5;
Factorials<mint> Fact(N);
