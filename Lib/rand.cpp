mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long uniform(long long l, long long r) {
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
}
