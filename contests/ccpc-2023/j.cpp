#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define eb emplace_back
typedef long double ld;

const ld DINF = 1e18, eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return (abs(a - b) <= eps);
}

struct pt {
	ld x, y, z;
	pt(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) { }
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		if (!eq(z, p.z)) return z < p.z;
		return 0;
	}
	bool operator > (const pt p) const {
		if (!eq(x, p.x)) return x > p.x;
		if (!eq(y, p.y)) return y > p.y;
		if (!eq(z, p.z)) return z > p.z;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
	}
	pt operator + (const pt p) const {
		return pt(x + p.x, y + p.y, z + p.z);
	}
	pt operator - (const pt p) const {
		return pt(x - p.x, y - p.y, z - p.z);
	}
	pt operator * (const ld c) const {
		return pt(x * c, y * c, z * c);
	}
	pt operator / (const ld c) const {
		return pt(x / c, y / c, z / c);
	}
	ld operator * (const pt p) const {
		return x * p.x + y * p.y + z * p.z;
	}
	pt operator ^ (const pt p) const {
		return pt(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
	}
	friend istream& operator >> (istream &in, pt &p) {
		return in >> p.x >> p.y >> p.z;
	}
};

struct plane {
	array<pt, 3> p;
	array<ld, 4> eq;
	plane () { }
	plane (pt p_, pt q_, pt r_) {
		p[0] = p_;
		p[1] = q_;
		p[2] = r_;
		build();
	}
	void build () {
		pt dir = (p[1] - p[0]) ^ (p[2] - p[0]);
		eq = {dir.x, dir.y, dir.z, dir * p[0] * (-1)};
	}
};

ld sdist(pt p, plane P) {
	return P.eq[0] * p.x + P.eq[1] * p.y + P.eq[2] * p.z + P.eq[3];
}

ld distp(pt p, pt q) {
	ld dx = p.x - q.x;
	ld dy = p.y - q.y;
	ld dz = p.z - q.z;
	return sq(dx) + sq(dy) + sq(dz);
}

pt proj(pt p, plane P) {
	p = p - P.p[0];
	P.p[1] = P.p[1] - P.p[0];
	P.p[2] = P.p[2] - P.p[0];
	pt norm = P.p[1] ^ P.p[2];
	pt proj = p - (norm * (norm * p)) / (norm * norm);
	return proj + P.p[0];
}

ld dist(pt p, plane P) {
	return distp(p, proj(p, P));
}

pt proj(pt a, pt b) {
	return b * (a * b);
}

void solve() {
	cout << setprecision(12) << fixed;

	int n; cin >> n;
	vector<pt> p(n);

	for (int i = 0; i < n; i++) cin >> p[i];

	if (n <= 3) {
		cout << 0.0 << endl;
		return;
	}

	ld res = 2e9;

	bool done = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = k + 1; l < n; l++) {
					pt p1 = p[j] - p[i];
					pt p2 = p[l] - p[k];
					pt cross = p1 ^ p2;
					if (abs(cross.x) <= eps && abs(cross.y) <= eps && abs(cross.z) <= eps) continue;
					done = 1;
					cross = cross / sqrt(distp(cross, pt(0, 0, 0)));
					pt maximum(-2e9, -2e9, -2e9);
					pt minimum(2e9, 2e9, 2e9);
					for (int m = 0; m < n; m++) {
						pt Pro = proj(p[m], cross);
						if (Pro > maximum) maximum = Pro;
						if (Pro < minimum) minimum = Pro;
					}
					res = min(res, distp(maximum, minimum));
				}
			}
		}
	}
	if (done) cout << sqrt(res) << endl;
	else cout << 0.0 << endl;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}
