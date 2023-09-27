#include <bits/stdc++.h>
using namespace std;

#warning TESTES DA K TROCADOS COM C NO BEECROWD

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef tuple<int,int,int> i3;

i3 stotuple(string u){
    i3 ret;
    int s1 = 0, s2 = 0, first = 1;
    vector<string> nums;
    int last = 0;
    int size = 0;
    u.push_back(':');
    int count = 0;
    for(int i = 0; i < (int)u.size(); i++){
        if(u[i] == ':'){
            ++count;
            string temp = u.substr(last, size);
            nums.emplace_back(temp);
            last = i+1;
            size = 0;
            continue;
        }
        size++;
    }
    auto& [f, s, t] = ret;
    f = stoi(nums[0]);
    s = stoi(nums[1]);
    t = stoi(nums[2]);
    return ret;
}

i3 add(i3 &a, i3 &b){
    i3 ret;
    get<0>(ret) = get<0>(a) + get<0>(b);
    get<1>(ret) = get<1>(a) + get<1>(b);
    get<2>(ret) = get<2>(a) + get<2>(b);
    return ret;
}

void solve(){
    int n, l; cin >> n >> l;
    map<int,i3> total;
    map<int,pair<i3, int>> best;
    for(int i = 0; i < n; i++){
        int id; cin >> id;
        for(int j = 0; j < l; j++){
            string u; cin >> u;
            auto conv = stotuple(u);
            if(best.count(id)){
                best[id] = min(best[id], make_pair(conv, j));
            } else {
                best[id] = make_pair(conv, j);
            }
            if(total.count(id)){
                total[id] = add(total[id], conv);
            } else {
                total[id] = conv;
            }
        }
    }
    map<i3, int> ranking;
    for(auto [id, time] : total){
        ranking.emplace(time, id);
    }
    pair<i3,int> BEST_TIME = make_pair(make_tuple(1e9,1e9,1e9), 1e9);
    for(auto [id, time] : best){
        BEST_TIME = min(BEST_TIME, time);
    }
    bool db = 0;
    int i = 0;
    for(auto [time, id] : ranking){
        if(best[id] == BEST_TIME){
            cout << id << '\n';
            return;
        }
        if(++i == 10) break;
    }
    cout << "NENHUM" << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
