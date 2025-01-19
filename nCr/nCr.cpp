#define M 1000000007

// Function to calculate (a^b) % M using modular exponentiation
long long modExp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

// Function to compute modular inverse of a number using Fermat's Little Theorem
long long modInverse(long long a, long long mod) {
    return modExp(a, mod - 2, mod);
}

// Function to precompute factorials and their modular inverses
void precomputeFactorials(vector<long long>& fact, vector<long long>& invFact, int maxN) {
    fact[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    for (int i = 0; i <= maxN; i++) {
        invFact[i] = modInverse(fact[i], M);
    }
}

// Function to calculate nCr % M
long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
    if (r > n || r < 0) return 0;
    return (fact[n] * invFact[r] % M * invFact[n - r] % M) % M;
}

// Usage
vector<long long> fact(N + 1), invFact(N + 1);
precomputeFactorials(fact, invFact, maxN);

long long combinatorics = nCr(n, r, fact, invFact);