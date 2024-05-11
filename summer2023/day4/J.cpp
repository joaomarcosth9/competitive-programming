#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

#define int long long
#define num first
#define den second
const int INF = 1e14;
typedef pair<int, int> frac;
// m, Y, X
typedef tuple<frac, frac, frac> line;

void simplify(frac &a) {
    if (a.den == 0) {
        a.num = INF;
    } else if (a.num == 0) {
        a.den = INF;
    } else {
        int g = gcd(a.num, a.den);
        a.num /= g, a.den /= g;
        if (a.den < 0) {
            a.num = -a.num, a.den = -a.den;
        }
    }
}

frac mul(frac a, frac b) {
    if (a.num == INF || a.den == INF)
        return a;
    else if (b.num == INF || b.den == INF)
        return b;
    a.num *= b.num;
    a.den *= b.den;
    simplify(a);
    return a;
}

frac mul(frac a, int b) { return mul(a, {b, 1}); }

frac add(frac a, frac b) {
    if (a.num == INF || b.den == INF)
        return a;
    else if (b.num == INF || a.den == INF)
        return b;
    b.num *= a.den;
    a.num *= b.den;
    a.den *= b.den;
    a.num += b.num;
    return a;
}

frac add(frac a, int b) { return add(a, {b, 1}); }

frac inv(frac a) {
    if (a.num == INF || a.den == INF) {
        return {a.den, a.num};
    }
    auto ret = frac(a.den, a.num);
    simplify(ret);
    return ret;
}

line create(int x, int y, int xx, int yy) {
    frac m = frac(y - yy, x - xx);
    simplify(m);
    frac Y = add(mul(m, -x), y);
    simplify(Y);
    frac X = (m.num != INF ? mul(mul(Y, -1), inv(m)) : frac(x, 1));
    return {m, Y, X};
}

void solve() {
    int n;
    cin >> n;
    set<line> lines;
    for (int i = 0; i < n; i++) {
        int x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        auto l = create(x, y, xx, yy);
        db(x, y, xx, yy);
        db(l);
        lines.insert(l);
    }
    db(lines.size());
    for (auto l : lines) {
        db(l);
    }
    map<frac, int> freq;
    long long res = 0;
    for (auto l : lines) {
        auto [m, _, __] = l;
        res += freq[mul(inv(m), -1)];
        freq[m] += 1;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
