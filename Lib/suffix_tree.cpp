#include <bits/stdc++.h>

using namespace std;

#define fpos adla
const int inf = 1e9;
const int maxn = 1e4;
char s[maxn];
map<char, int> to[maxn];
int len[maxn], fpos[maxn], link[maxn];
int node, pos;
int sz = 1, n = 0;

int make_node(int _pos, int _len) {
    fpos[sz] = _pos;
    len [sz] = _len;
    return sz++;
}

void go_edge() {
    while(pos > len[to[node][s[n - pos]]]) {
        node = to[node][s[n - pos]];
        pos -= len[node];
    }
}

void add_letter(char c) {
    s[n++] = c;
    pos++;
    int last = 0;
    while (pos > 0) {
        go_edge();
        char edge = s[n - pos];
        int &v = to[node][edge];
        char t = s[fpos[v] + pos - 1];
        if(v == 0) {
            v = make_node(n - pos, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c) {
            link[last] = node;
            return;
        }
        else {
            int u = make_node(fpos[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += pos - 1;
            len [v] -= pos - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0) pos--;
        else node = link[node];
    }
}

void print_tree() {
    for(int i = 0; i < sz; i++) {
        cout << "Node " << i << ":\n";
        for(auto it : to[i]) {
            cout << "  " << it.first << " -> " << it.second << "\n";
        }
        cout << "  len = " << len[i] << "\n";
        cout << "  fpos = " << fpos[i] << "\n";
        cout << "  link = " << link[i] << "\n";
    }
}

int main() {
    len[0] = inf;
    string t;
    cin >> t;
    for(int i = 0; i < (int)t.size(); i++) {
        add_letter(t[i]);
    }
    print_tree();
}
