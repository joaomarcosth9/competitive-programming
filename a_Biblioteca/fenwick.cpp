// 0 - INDEXED
// fenwick<T> ft(*start, *end);
template <class T>
class fenwick {
private:
    vector<T> bit;
    int n;
public:
    fenwick (T* st, T* en) {
        n = int(en-st);
        bit.assign(n, 0);
        for(int i = 0; i < n; i++) add(i, st[i]);
    }
    T sum(int r){
        T res = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1){
            res += bit[r];
        }
        return res;
    }
    T sum(int l, int r){
        return sum(r) - sum(l-1);
    }
    void add(int i, T d){
        for(; i < n; i = (i | (i + 1))){
            bit[i] += d;
        }
    }
    void assign(int i, T d){
        d -= sum(i,i);
        for(; i < n; i = (i | (i + 1))){
            bit[i] += d;
        }
    }
};

