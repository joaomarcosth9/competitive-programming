template<typename T = mint> struct Binomial {
    Factorials<T> f;
    Binomial(int n): f(n) {}
    T ncr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return f(n) * f.inv(r) * f.inv(n - r);
    }
    T npr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return f(n) * f.inv(n - r);
    }
    T sb(int n, int k) const {
        return ncr(n + k - 1, n);
        // same as f(n + k - 1) * f.inv(n) * f.inv(k - 1)
    }
};

const int N = 1e6 + 5;
Binomial<mint> C(N);
