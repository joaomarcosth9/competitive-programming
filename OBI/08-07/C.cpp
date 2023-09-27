#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

int n;
double p, g;

int main() {
    cin >> n;
    n--;
    cin >> p >> g;
    double res = p * (1000 / g);
    while (n--) {
        cin >> p >> g;
        double temp = p * (1000 / g);
        if (temp < res) {
            res = temp;
        }
    }
    printf("%.2lf", res);
    return 0;
}
