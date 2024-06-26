#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            a[i][j] = (c == '+' ? 1 : -1);
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }

    vector<int> hint_l(n), hint_c(n);

    for (int i = 0; i < n; i++) {
        cin >> hint_l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> hint_c[i];
    }

    vector<int> need_l(n), need_c(n);

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += (a[i][j] == -1);
        }
        // cout << i << " " << hint_l[i] << " " << cnt << endl;
        need_l[i] = hint_l[i] + cnt;
        // cout << "need: " << need_l[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += (a[j][i] == -1);
        }
        need_c[i] = hint_c[i] + cnt;
    }

    vector<pair<int, int>> lines;

    vector<pair<int, int>> used;

    for (int i = 0; i < n; i++) {
        lines.emplace_back(need_l[i], i);
    }
    sort(lines.begin(), lines.end(), [&] (pair<int, int>& l, pair<int, int>& r) {
        return l.first > r.first;
    });
    while ((int)lines.size() > 0 && lines.back().first == 0) {
        lines.pop_back();
    }
    // cout << "lines: " << endl;
    // for (auto [free, line] : lines) {
    //     cout << free << " " << line << endl;
    // }
    // cout << endl;

    vector<int> ord_cols(n);
    iota(ord_cols.begin(), ord_cols.end(), 0);
    sort(ord_cols.begin(), ord_cols.end(), [&] (int i, int j) {
        return need_c[i] > need_c[j];
    });
    // cout << "ord_cols: " << endl;
    // for (auto col : ord_cols) {
    //     cout << col << " ";
    // }
    // cout << endl;
    // for (auto col : ord_cols) {
    //     cout << need_c[col] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++) {
        int col = ord_cols[i];
        if (need_c[col] == 0) break;
        for (int j = 0; j < (int)lines.size(); j++) {
            auto &[free, line] = lines[j];
            free--;
            used.emplace_back(line, col);
            need_c[col]--;
            if (need_c[col] == 0) break;
        }
        if (need_c[col] > 0) {
            cout << "No" << endl;
            return;
        }
        sort(lines.begin(), lines.end(), [&] (pair<int, int>& l, pair<int, int>& r) {
            return l.first > r.first;
        });
        while ((int)lines.size() > 0 && lines.back().first == 0) {
            lines.pop_back();
        }
    }

    if (lines.size()) {
        cout << "No" << endl;
        return;
    }

    vector res(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = (a[i][j] == 1 ? 0 : 1);
        }
    }

    // cout << "used: " << endl;
    for (auto [i, j] : used) {
        // cout << i << " " << j << endl;
        res[i][j] = (a[i][j] == 1 ? 1 : 0);
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}