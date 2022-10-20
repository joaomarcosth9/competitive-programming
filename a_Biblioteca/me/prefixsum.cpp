// 1 - INDEXED
// prefixsum<T> pf(*start, *end);
template <class T>
class prefixsum {
private:
    vector<T> pref;
public:
    prefixsum (T* st, T* en){
        int n = (int)(en-st);
        pref.assign(n+1, 0);
        for(int i = 1; i <= n; i++){
            pref[i] = (st[i-1] + pref[i-1]);
        }
    }
    T sum(int i){
        return pref[i];
    }
    T sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

