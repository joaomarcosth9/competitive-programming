template<typename T = mint> struct Power {
    vector<T> pow;
    Power(int n, T x) : pow(2 * n + 1) {
        pow[n] = T(1);
        pow[n + 1] = x;
        pow[n - 1] = T(1) / x;
        for (int i = n + 2; i < 2 * n + 1; i++) pow[i] = pow[i - 1] * pow[n + 1];
        for (int i = n - 2; i >= 0; i--) pow[i] = pow[i + 1] * pow[n - 1];
    }
    T operator()(int n) const { return pow[size(pow) / 2 + n]; }
    T inv(int n) const { return pow[size(pow) / 2 - n]; }
};

const int N = 1e6 + 5;
Power<mint> Pow(N, 2);
