#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int len;
    cin >> len;
    vector<int> A(len);
    deque<int> B;

    for (int i = 0; i < len; i++) {
        cin >> A[i];
    }

    int j = len - 1;
    int i = 0;

    if (len == 1) {
        cout << A[0] << endl;
        return;
    }

    if (A[0] != len && A[len - 1] != len) {
        cout << -1 << endl;
        return;
    }

    for (int it = len; it > 0; it--) {
        int num = max(A[i], A[j]);
        if (j == i) {
            B.push_back(num);
            break;
        } else if (num == A[i]) {
            B.push_front(num);
            i++;
        } else if (num == A[j]) {
            B.push_back(num);
            j--;
        }
    }

    for (int k = 0; k < B.size(); k++) {
        cout << B[k] << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
