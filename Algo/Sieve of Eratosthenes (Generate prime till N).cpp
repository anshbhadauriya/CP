void storePrimes(int n, vector<int>& primes) {
    primes[0] = false;
    if (n >= 1) primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}
