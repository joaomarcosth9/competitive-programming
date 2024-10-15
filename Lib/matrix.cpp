template<typename T> struct matrix {
    int n, m;
    vector<vector<T>> a;
    matrix(int n, int m) : n(n), m(m), a(n, vector<T>(m)) {}
    matrix(int n) : matrix(n, n) {}
    matrix(const vector<vector<T>>& a) : n(a.size()), m(a[0].size()), a(a) {}
    matrix(const matrix& o) : matrix(o.a) {}
    matrix& operator=(const matrix& o) { a = o.a; n = o.n; m = o.m; return *this; }
    matrix& operator=(const vector<vector<T>>& o) { a = o; n = o.size(); m = o[0].size(); return *this; }
    vector<T>& operator[](int i) { return a[i]; }
    const vector<T>& operator[](int i) const { return a[i]; }
    matrix operator+(const matrix& o) const {
        assert(n == o.n && m == o.m);
        matrix res(n, m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = a[i][j] + o[i][j];
        return res;
    }
    matrix operator-(const matrix& o) const {
        assert(n == o.n && m == o.m);
        matrix res(n, m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = a[i][j] - o[i][j];
        return res;
    }
    matrix operator*(const matrix& o) const {
        assert(m == o.n);
        matrix res(n, o.m);
        for (int i = 0; i < n; i++) for (int j = 0; j < o.m; j++) for (int k = 0; k < m; k++) res[i][j] += a[i][k] * o[k][j];
        return res;
    }
    matrix operator*(const T& o) const {
        matrix res(n, m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = a[i][j] * o;
        return res;
    }
    matrix operator/(const T& o) const {
        matrix res(n, m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) res[i][j] = a[i][j] / o;
        return res;
    }
    matrix& operator+=(const matrix& o) { return *this = *this + o; }
    matrix& operator-=(const matrix& o) { return *this = *this - o; }
    matrix& operator*=(const matrix& o) { return *this = *this * o; }
    matrix& operator*=(const T& o) { return *this = *this * o; }
    matrix& operator/=(const T& o) { return *this = *this / o; }
    matrix operator^(ll p) const {
        assert(n == m);
        matrix res(n);
        matrix b = *this;
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while (p) {
            if (p & 1) res *= b;
            b *= b;
            p >>= 1;
        }
        return res;
    }
    matrix& operator^=(ll p) { return *this = *this ^ p; }
    matrix operator-() const { return *this * -1; }
    matrix operator+() const { return *this; }
    friend ostream& operator<<(ostream& os, const matrix& o) {
        for (int i = 0; i < o.n; i++) {
            for (int j = 0; j < o.m; j++) os << o[i][j] << " \n"[j + 1 == o.m];
        }
        return os;
    }
    friend istream& operator>>(istream& is, matrix& o) {
        for (int i = 0; i < o.n; i++) for (int j = 0; j < o.m; j++) is >> o[i][j];
        return is;
    }
    friend bool operator==(const matrix& u, const matrix& v) { return u.a == v.a; }
    friend bool operator!=(const matrix& u, const matrix& v) { return u.a != v.a; }
    friend matrix transpose(const matrix& o) {
        matrix res(o.m, o.n);
        for (int i = 0; i < o.n; i++) for (int j = 0; j < o.m; j++) res[j][i] = o[i][j];
        return res;
    }
    friend matrix pow(const matrix& o, ll p) { return o ^ p; }
    friend T det2(const matrix& o) { // only for 2x2
        assert(o.n == 2 && o.m == 2);
        return o[0][0] * o[1][1] - o[0][1] * o[1][0];
    }
    friend T det3(const matrix& o) { // only for 3x3
        assert(o.n == 3 && o.m == 3);
        return o[0][0] * o[1][1] * o[2][2] + o[0][1] * o[1][2] * o[2][0] + o[0][2] * o[1][0] * o[2][1] - o[0][0] * o[1][2] * o[2][1] - o[0][1] * o[1][0] * o[2][2] - o[0][2] * o[1][1] * o[2][0];
    }
    friend matrix inv2(const matrix& o) { // only for 2x2
        assert(o.n == 2 && o.m == 2);
        matrix res = o;
        T det = det2(o);
        /* assert(det != 0); */
        res[0][0] = o[1][1] / det;
        res[1][1] = o[0][0] / det;
        res[0][1] = -o[0][1] / det;
        res[1][0] = -o[1][0] / det;
        return res;
    }
    friend matrix inv3(const matrix& o) { // only for 3x3
        assert(o.n == 3 && o.m == 3);
        matrix res = o;
        T det = det3(o);
        /* assert(det != 0); */
        res[0][0] = (o[1][1] * o[2][2] - o[1][2] * o[2][1]) / det;
        res[0][1] = (o[0][2] * o[2][1] - o[0][1] * o[2][2]) / det;
        res[0][2] = (o[0][1] * o[1][2] - o[0][2] * o[1][1]) / det;
        res[1][0] = (o[1][2] * o[2][0] - o[1][0] * o[2][2]) / det;
        res[1][1] = (o[0][0] * o[2][2] - o[0][2] * o[2][0]) / det;
        res[1][2] = (o[0][2] * o[1][0] - o[0][0] * o[1][2]) / det;
        res[2][0] = (o[1][0] * o[2][1] - o[1][1] * o[2][0]) / det;
        res[2][1] = (o[0][1] * o[2][0] - o[0][0] * o[2][1]) / det;
        res[2][2] = (o[0][0] * o[1][1] - o[0][1] * o[1][0]) / det;
        return res;
    }
    friend T det(const matrix& o) {
        assert(o.n == o.m);
        if (o.n == 1) return o[0][0];
        if (o.n == 2) return det2(o);
        if (o.n == 3) return det3(o);
        assert(false);
    }
    friend matrix inv(const matrix& o) {
        assert(o.n == o.m);
        if (o.n == 1) return vector<vector<T>> {{1 / o[0][0]}};
        if (o.n == 2) return inv2(o);
        if (o.n == 3) return inv3(o);
        assert(false);
    }
};
