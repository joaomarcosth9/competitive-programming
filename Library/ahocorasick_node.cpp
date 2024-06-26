struct AC {
    static const int SIGMA = 26;
    static const char norm = 'a';
    inline int get(int c) { return c - norm; }

    struct node {
        int link, out_link, par;
        char pch;
        vector<int> next;
        bool out;
        vector<int> output;
        node(int link = -1, int out_link = -1, int par = - 1, char pch = -1, bool out = 0) :
            link(link), out_link(out_link), par(par), pch(pch), next(SIGMA, -1), out(out) { }
    };

    vector<node> t = {node(0, 0, 0, -1, 0)};
    int T = 0;

    int insert(const string& s) {
        int u = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            auto v = t[u].next[get(s[i])];
            if (v == -1) {
                t.eb(-1, -1, u, s[i], 0);
                v = (int)t.size() - 1;
                t[u].next[get(s[i])] = v;
            }
            u = v;
        }
        t[u].out = 1;
        t[u].output.emplace_back(T);
        return T++;
    }

    int get_link(int u) {
        if (t[u].link == -1) {
            t[u].link = t[u].par ? go(get_link(t[u].par), t[u].pch) : 0;
        }
        return t[u].link;
    }

    int go(int u, char c) {
        if (t[u].next[get(c)] == -1) {
            t[u].next[get(c)] = u ? go(get_link(u), c) : 0;
        }
        return t[u].next[get(c)];
    }

    int exit(int u) {
        if (t[u].out_link == -1) {
            int v = get_link(u);
            t[u].out_link = (t[v].out || !v) ? v : exit(v);
        }
        return t[u].out_link;
    }

} aho;
