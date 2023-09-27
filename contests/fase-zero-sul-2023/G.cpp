#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

vector<char> SEP { ',', ' ', '.' };

bool sep(char c){
    for(auto u : SEP) {
        if(u == c) return 1;
    }
    return 0;
}

bool num(char c){
    for(char u = '1'; u <= '9'; u++){
        if(u == c) return 1;
    }
    return 0;
}

void tokenize(std::string const &str, const char delim, 
            std::vector<std::string> &out) { 
    // construct a stream from the string 
    std::stringstream ss(str); 
 
    std::string s; 
    while (std::getline(ss, s, delim)) { 
        out.push_back(s); 
    } 
}

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool can_be_alone(const string& s){
    string t;
    int n = s.size();
    map<char,int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
        if(i < n - 1 && s[i] == '.'){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(i < n - 1 && s[i] == ','){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(s[i] != ',' && s[i] != '.'){
            t.push_back(s[i]);
        }
    }
    return is_number(t) && freq[','] <= 1 && freq['.'] <= 1;
}

bool can_be_first(const string& s){
    string t;
    if(s.back() == ',' || s.back() == '.'){
        return 0;
    }
    int n = s.size();
    map<char,int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
        if(i < n - 1 && s[i] == '.'){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(i < n - 1 && s[i] == ','){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(s[i] != ',' && s[i] != '.'){
            t.push_back(s[i]);
        }
    }
    return is_number(t) && freq[','] <= 1 && freq['.'] <= 1;
}

bool can_be_second(const string& s){
    string t;
    if(s[0] == '.' || s[0] == ','){
        return 0;
    }
    int n = s.size();
    map<char,int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
        if(i < n - 1 && s[i] == '.'){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(i < n - 1 && s[i] == ','){
            if(s[i + 1] == ',' || s[i + 1] == '.') return 0;
        }
        if(s[i] != ',' && s[i] != '.'){
            t.push_back(s[i]);
        }
    }
    return is_number(t) && freq[','] <= 1 && freq['.'] <= 1;
}

pair<int,int> freq_dc(const string& s){
    int fc = 0, fd = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == ','){
            fc++;
        } else if(s[i] == '.'){
            fd++;
        }
    }
    return {fd, fc};
}

void clean(string& s){
    string t;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] != ',' && s[i] != '.'){
            t.push_back(s[i]);
        }
    }
    s = t;
}

void solve() {
    int nn; cin >> nn;
    map<int,int> m;
    vector<long long> numbers;
    for(int ii = 0; ii < nn; ii++){
        string s;
        getline(cin >> ws, s);
        vector<string> t;
        tokenize(s, ' ', t);
        debug(t);
        int n = t.size();
        for(int i = 0; i < n; i++){
            if(can_be_alone(t[i])){
                auto [fd, fc] = freq_dc(t[i]);
                if(can_be_first(t[i]) && i < n - 1 && can_be_second(t[i + 1])){
                    auto [fd1, fc1] = freq_dc(t[i + 1]);
                    if(fd + fd1 <= 1 && fc + fc1 <= 1){
                        string u = t[i] + t[i + 1];
                        clean(u);
                        debug(u);
                        numbers.emplace_back(stoll(u));
                        i++;
                    } else {
                        clean(t[i]);
                        numbers.emplace_back(stoll(t[i]));
                        debug(t[i]);
                    }
                } else {
                    clean(t[i]);
                    numbers.emplace_back(stoll(t[i]));
                    debug(t[i]);
                }
            }
        }
    }
    map<long long, int> f;
    for(long long u : numbers){
        f[u]++;
        if(f[u] && f[u - 1] && f[u - 2]){
            cout << "123" << '\n';
            return;
        }
    }
    cout << ":)" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
