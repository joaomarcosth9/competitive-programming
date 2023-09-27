#include <bits/stdc++.h>

using namespace std;

char oi = 'a';
char *poi = &oi;
int arr[112345678];

int main() {
    int size = sizeof(poi) / sizeof(arr[0]);
    printf("%p", poi);
    return 0;
}
