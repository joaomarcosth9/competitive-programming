#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[10] = {};
    int db = 1;
    for (int i = 0; i < 8; i++) {
        int a;
        cin >> a;
        arr[a]++;
        if (arr[a] > 4) {
            db = 0;
            break;
        }
    }
    cout << (db ? "S" : "N") << endl;

    return 0;
}
