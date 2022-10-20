// 1 - INDEXED
// suffixsum<T> sf(*start, *end);
template <class T>
class suffixsum {
private:
    vector<T> suff;
public:
    suffixsum (T* st, T* en){
        int n = (int)(en-st);
        suff.assign(n+1, 0);
        for(int i = 1, j = n-1; i <= n; i++, j--){
            suff[i] = (st[j] + suff[i-1]);
        }
    }
    T sum(int i){
        return suff[i];
    }
    T sum(int l, int r){
        return sum(l) - sum(r-1);
    }
};

