// Hashing estatico (sem update)
// 
// Usa o mint e rng()
//
// Build: O(n)
// Query: O(1)
//
// LEMBRAR DE CHAMAR O initPrime() !
//
// para usar apenas 1 mod:
// using Hash = mint;

const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
using mint1 = Mint<mod1>;
using mint2 = Mint<mod2>;
using Hash = pair<mint1, mint2>;

Hash operator*(Hash a, Hash o) {
    return {a.first * o.first, a.second * o.second};
}
Hash operator+(Hash a, Hash o) {
    return {a.first + o.first, a.second + o.second};
}
Hash operator-(Hash a, Hash o) {
    return {a.first - o.first, a.second - o.second};
}

const int ORD = 1e6;
const int PRIME = ORD + (rng() % ORD); // nao necessariamente primo

const int MAXN = 1e6 + 5;

Hash P = {PRIME, PRIME};
Hash invP = {mint1(1) / PRIME, mint2(1) / PRIME};

Hash p[MAXN], invp[MAXN];

void initPrime() {
    p[0] = invp[0] = Hash(1, 1);
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * P;
        invp[i] = invp[i - 1] * invP;
    }
}

template<typename obj = string> struct Hashing {
    int N;
    vector<Hash> hsh;
    Hashing () {}
    Hashing(obj s) : N(size(s)), hsh(N + 1) {
        for (int i = 0; i < N; i++) {
            hsh[i + 1] = hsh[i] + (p[i + 1] * Hash(s[i], s[i]));
        }
    }
    Hash operator()(int l, int r) const {
        return (hsh[r + 1] - hsh[l]) * invp[l];
    }
};

template<typename obj = string> struct revHashing {
    // hash em que query(l, r) retorna o hash da substring de [l, r] invertida
    // util pra verificar palindromos e afins
    int N;
    vector<Hash> hsh;
    revHashing () {}
    revHashing(obj s) : N(size(s)), hsh(N + 1) {
        for (int i = N - 1; i >= 0; i--) {
            hsh[i] = hsh[i + 1] + (p[N - i] * Hash(s[i], s[i]));
        }
    }
    Hash operator()(int l, int r) const {
        return (hsh[l] - hsh[r + 1]) * invp[N - r - 1];
    }
};
