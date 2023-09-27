#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

const int maxn = 2e5 + 5; 
int lg[maxn];
vector<int> arr1, arr2, rnk1, rnk2, lcp1, lcp2;
string s, pa; 

struct sparsetable {
    vector<vector<int>> st;
    int n;
    void build(vector<int> &v) {
        n = v.size();
        int LG = lg[n];
        st.resize(LG + 1);
        for (int i = 0; i <= LG; i++) {
            st[i].assign(n, INT_MAX);
        }
        st[0] = v;
        for (int i = 1; i <= LG; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int LG = lg[r - l + 1];
        return min(st[LG][l], st[LG][r - (1 << LG) + 1]);
    }
};
sparsetable st1, st2;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    lg[1] = 0;
    for (int i = 2; i < maxn; i++) 
        lg[i] = lg[i >> 1] + 1;

    int n, m; cin >> n >> m;
    cin >> s >> pa;
    string ss = s + "B" + pa;
    arr1 = suffix_array(ss);
    arr2 = suffix_array(pa);
    rnk1.resize(n + m + 1);
    rnk2.resize(m);

    debug(arr1, arr1.size());
    debug(arr2);
    for (int i = 0; i < n + m + 1; i++)
        rnk1[arr1[i]] = i;
    for (int i = 0; i < m; i++)
        rnk2[arr2[i]] = i;

    lcp1 = kasai(ss, arr1);
    lcp2 = kasai(pa, arr2);

    debug(arr1.size(), arr1);
    debug(rnk1.size(), rnk1);
    debug(lcp1.size(), lcp1);

    debug(arr2.size(), arr2);
    debug(rnk2.size(), rnk2);
    debug(lcp2.size(), lcp2);

    st1.build(lcp1);
    st2.build(lcp2);

    auto count1 = [&] (int l, int r) {
        int where = rnk1[n + 1 + l];
        int len = r - l + 1;
        // lcp1[i] = lcp(sa[i], sa[i + 1]);
        int a = where, b = n + m - 1;
        int L = where, R = where;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (st1.query(L, mid) >= len) {
                R = mid + 1;
                a = mid + 1;
            } else {
                b = mid - 1;
            }
        }
        int RR = where - 1;
        a = 0, b = where - 1;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (st1.query(mid, RR) >= len) {
                L = mid;
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }
        debug(L, R);
        return (R - L + 1);
    };

    auto count2 = [&] (int l, int r) {
        int where = rnk2[l];
        int len = r - l + 1;
        // lcp2[i] = lcp(sa[i], sa[i + 1]);
        int a = where, b = m - 2;
        int L = where, R = where;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (st2.query(L, mid) >= len) {
                R = mid + 1;
                a = mid + 1;
            } else {
                b = mid - 1;
            }
        }
        int RR = where - 1;
        a = 0, b = where - 1;
        while (a <= b) {
            int mid = (a + b) / 2;
            if (st2.query(mid, RR) >= len) {
                L = mid;
                b = mid - 1;
            } else {
                a = mid + 1;
            }
        }
        debug(2, L, R);
        return (R - L + 1);
    };

    int q; cin >> q; 
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << count1(l, r) - count2(l, r) << endl;
    }

}
