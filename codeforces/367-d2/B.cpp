#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int n, q, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &n);
    vector<int> v(n);
    for(int& a : v) scanf("%d", &a);
    sort(v.begin(), v.end());
    scanf("%d", &q);
    while(q--){
        scanf("%d", &c);
        printf("%d\n", (int)(upper_bound(v.begin(), v.end(), c) - v.begin()));
    }
    return 0;
}

