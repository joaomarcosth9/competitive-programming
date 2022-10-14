#include <bits/stdc++.h>
#define endl '\n' 

using namespace std; 

typedef long long ll; 
typedef vector<int> vi; 
typedef priority_queue<int, vector<int>, greater<int>> pqg;  
typedef pair<int, int> pii; 

#define pb push_back
#define eb emplace_back
#define fill(arr, n) for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {arr[i] = n; } 
#define F0R(i, n) for(int i = 0; i < n; i++)
#define R0F(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, a, n) for (int i = a; i <= n; i++) 
#define ROF(i, a, n) for (int i = n; i>= a; i--)

int min(int x, int y, int z) { return min(min(x, y), z); }

int leve(string& str1, string& str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return leve(str1, str2, m - 1, n - 1);

    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
           + min(leve(str1, str2, m, n - 1), // Insert
                 leve(str1, str2, m - 1, n), // Remove
                 leve(str1, str2, m - 1,
                          n - 1) // Replace
             );
}


char s[25];
char a[25]; 
double res[10]; 

void solve() {
    int n; cin >> n;
    while (n--) {
        string ss; cin >> ss; 

        vector<string> A; 
        vector<int> ig; 
        for (int i = 0; i < 5; i++) {
            string sss; cin >> sss; 
            A.pb(sss); 
            if (sss == ss) {
                ig.pb(i); 
            } 
        } 
        if (ig.size()) {
            for (int ii : ig) {
                res[ii] += 1.0; 
            } 
        } 
        else {
            vector<int> dis; 
            for (int i = 0; i < (int)A.size(); i++) {
                dis.pb(leve(ss, A[i], (int)ss.size(), (int)A[i].size())); 
            } 

            int minn = INT_MAX; 
            for (int i = 0; i < (int)dis.size(); i++) {
                minn = min(minn, dis[i]); 
            } 

            vector<int> gg; 
            for (int i = 0; i < (int)dis.size(); i++) {
                if (dis[i] == minn) {
                    gg.pb(i); 
                } 
            } 
            for (int aa : gg) {
                res[aa] += 0.5; 
            } 
        } 
    } 

    double maxx = -1.0; 
    for (int i = 0; i < 5; i++) {
        maxx = max(maxx, res[i]); 
    } 

    printf("%.1lf\n", maxx); 
    vector<int> ress; 
    for (int i = 0; i < 5; i++) {
        if (res[i] == maxx) {
            ress.pb(i+1); 
        } 
    } 
    for (int i = 0; i < (int)ress.size(); i++) {
        cout << ress[i]; 
        if (i != (int)ress.size()-1) {
            cout << " "; 
        } 
    } 
    cout << endl;
}


int main() {
    solve(); 
    return 0; 
}

