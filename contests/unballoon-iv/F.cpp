#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

#define maxn 4000005

int l[maxn], r[maxn], cnt = 0;

struct XorTrie {
    int digits = 0, root, ans, limit;
    int newnode() {
        l[cnt] = r[cnt] = -1, cnt++;
        return cnt - 1;
    }
    bool search(int u, int h, int num, int cur) {
        if (u == -1 || cur > limit) return false;
        if (h == -1) {
            ans = cur;
            return true;
        }
        if (num & (1 << h)) {
            if (search(l[u], h - 1, num, cur)) return true;
            if (search(r[u], h - 1, num, cur | (1 << h))) return true;
        } else {
            if (search(r[u], h - 1, num, cur | (1 << h))) return true;
            if (search(l[u], h - 1, num, cur)) return true;
        }
        return false;
    }
    XorTrie(int _digits = 20) : digits(_digits) { root = newnode(); }
    void insert(int num) {
        int u = root;
        for (int i = digits - 1; i >= 0; i--) {
            if (num & (1 << i)) {
                if (r[u] == -1) r[u] = newnode();
                u = r[u];
            } else {
                if (l[u] == -1) l[u] = newnode();
                u = l[u];
            }
        }
    }
    int search(int _limit, int num) {
        limit = _limit, ans = -1;
        if (!search(root, digits - 1, num, 0)) return -1;
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    XorTrie trie(32);
    int _xor = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        trie.insert(a);
        _xor ^= a;

        // trie.search(_xor) -> numero que maximiza xor com _xor
        // trie.search(notxor) -> numero que minimiza xor com _xor

        int notxor = ~_xor;

        int u = trie.search(2e9, notxor);

        cout << (_xor ^ u) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
