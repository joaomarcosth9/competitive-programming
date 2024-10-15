struct compress {
    vector<int*> nums;
    vector<pair<int, int*>> p_nums;

    void push(int &x) {
        nums.emplace_back(&x);
    }

    void work(int f = 0) {
        for (int i = 0; i < (int)size(nums); i++) {
            p_nums.emplace_back(*nums[i], nums[i]);
        }
        sort(begin(p_nums), end(p_nums),
            [&] (auto x, auto y) {
            return x.first < y.first;
        });
        *p_nums[0].second = f;
        for (int i = 1; i < (int)size(nums); i++) {
            if (p_nums[i].first == p_nums[i - 1].first) *p_nums[i].second = f;
            else *p_nums[i].second = ++f;
        }
    }

    void clear() {
        nums.clear();
        p_nums.clear();
    }
} C;
