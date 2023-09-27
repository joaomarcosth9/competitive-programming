#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

bool valid(string &s) {
    stack<int> st;
    for (int i = 0; i < (int)s.size(); i++) {
        auto c = s[i];
        if (c == '(')
            st.push(1);
        else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return (st.empty());
}

void solve() {
    string s;
    cin >> s;
    int op, cl;
    cl = op = (int)s.size() / 2;
    vector<int> qm;
    for (int i = 0; i < (int)s.size(); i++) {
        auto c = s[i];
        if (c == '(')
            op--;
        else if (c == ')')
            cl--;
        else
            qm.push_back(i);
    }
    for (int i = 0; i < (int)qm.size(); i++) {
        if (i < op) {
            s[qm[i]] = '(';
        } else {
            s[qm[i]] = ')';
        }
    }
    bool res = true;
    if (cl && op) {
        swap(s[qm[op - 1]], s[qm[op]]);
        if (valid(s)) res = false;
    }
    cout << (res ? "YES" : "NO") << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
