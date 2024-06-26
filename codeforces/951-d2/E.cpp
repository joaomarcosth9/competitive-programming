#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

template <typename T> struct point {
    T x, y;
    int id;
    point(T _x = 0, T _y = 0, int _id = -1) : x(_x), y(_y), id(_id) { }

    using p = point;

    p operator*(const T o) { return p(o * x, o * y); }
    p operator-(const p o) { return p(x - o.x, y - o.y); }
    p operator+(const p o) { return p(x + o.x, y + o.y); }
    T operator*(const p o) { return x * o.x + y * o.y; }
    T operator^(const p o) { return x * o.y - y * o.x; }
    bool operator<(const p o) const { return (x == o.x) ? y < o.y : x < o.x; }
    bool operator==(const p o) const { return (x == o.x) and (y == o.y); }
    bool operator!=(const p o) const { return (x != o.x) or (y != o.y); }

    T dist2(const p o) {
        T dx = x - o.x, dy = y - o.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, const p &a) {
        return out << "(" << a.x << "," << a.y << ")";
    }
    friend istream &operator>>(istream &in, p &a) { return in >> a.x >> a.y; }
};

using pt = point<int>;

bool solve(vector<pt> a, int d) {
    int n = (int)a.size();

    map<int, int> mapa;

    set<pt> pts(a.begin(), a.end());

    for (auto [x, y, id] : a) {
        mapa[x + y] = 1;
    }

    int it = 0;
    for (auto &[sum, idsum] : mapa) {
        idsum = it++;
    }

    debug(mapa);

    vector<set<pt>> all(it);

    for (int i = 0; i < n; i++) {
        auto [x, y, id] = a[i];
        int sum = x + y;
        int idsum = mapa[sum];
        pt need = {x + d / 2, y - d / 2, -1};
        auto lb = pts.lower_bound(need);
        if (lb != pts.end()) {
            auto [nx, ny, nid] = *lb;
            if (nx == x + d / 2 && ny == y - d / 2) {
                all[idsum].emplace(a[i]);
            }
        }
    }

    debug(all);

    for (int i = 0; i < n; i++) {
        auto [x, y, id] = a[i];
        int sum = x + y;
        if (!mapa.count(sum - d)) {
            continue;
        }
        int idsum = mapa[sum - d];
        debug(a[i], idsum);
        // vou olhar os pontos que xj + yj = sum
        // so quero olhar os pontos com x - d <= xj <= x - (d / 2);
        pt need = {x - d, INT_MIN, -1};
        debug(x - d, x - (d / 2));
        auto lb = all[idsum].lower_bound(need);
        if (lb != all[idsum].end()) {
            auto [px, py, pid] = *lb;
            debug(*lb);
            if (x - d <= px && px <= x - (d / 2)) {
                pt need = {px + d / 2, py - d / 2, -1};
                auto lb = pts.lower_bound(need);
                auto [nx, ny, oid] = *lb;
                cout << id << " " << pid << " " << oid << endl;
                return true;
            }
        }
    }

    return false;
}

void solve() {
    int n, d; cin >> n >> d;
    vector<pt> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i].id = i + 1;
    }

    for (int i = 0; i < 4; i++) {

        debug(a);
        if (solve(a, d)) {
            return;
        }

        for (auto &[x, y, id] : a) {
            swap(x, y);
            x *= -1;
        }
    }

    cout << "0 0 0\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
