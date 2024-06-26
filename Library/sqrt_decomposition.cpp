// 0 - INDEXED
// sqrtdc<T> sq(*start, *end);
template <class T> class sqrt_decomp {
  private:
    int n, len;
    vector<T> v;
    vector<T> b;

  public:
    sqrt_decomp(T *st, T *en) {
        n = int(en - st);
        v.assign(n, 0);
        for (int i = 0; i < n; i++) v[i] = st[i];
        len = ceil(sqrt((double)n));
        b.assign(len, 0);
        for (int i = 0; i < n; i++) {
            b[i / len] += v[i];
        }
    }
    T sum(int l, int r) {
        T sum = 0;
        int l_block = l / len, r_block = r / len;
        if (l_block == r_block) {
            for (; l <= r; l++) sum += v[l];
        } else {
            for (int i = l, end = (l_block + 1) * len - 1; i <= end && (i % len != 0); i++) {
                sum += v[i];
            }
            for (int i = l_block + (l % len != 0); i <= r_block - (r != n - 1 && (r + 1) % len != 0); i++) {
                sum += b[i];
            }
            for (int i = r_block * len; i <= r && (r != n - 1 && (r + 1) % len != 0); i++) {
                sum += v[i];
            }
        }
        return sum;
    }
    void update(int i, int d) {
        b[i / len] -= v[i];
        v[i] += d;
        b[i / len] += v[i];
    }
};
