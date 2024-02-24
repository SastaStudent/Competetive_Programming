#include <iostream>
#include <chrono>

using namespace std::chrono;

const int mod = 1e9 + 7;

long binaryExpo1(int n, int k) {
    long res = 1;
    while (k > 0) {
        if (k & 1) {
            // odd (last set bit)
            res = (res * 1LL * n) % mod;
        }
        // even divide by two
        // right shift
        n = (n * 1LL * n) % mod;
        k = k >> 1;
    }
    return res;
}
//for larger n<=10^18
long long  binaryExpo(long long  n, long long k) {
    long long  res = 1;
    n=n%mod;
    while (k > 0) {
        if (k & 1) {
            // odd (last set bit)
            res = ((res%mod) *(n%mod)) % mod;
        }
        // even divide by two
        // right shift
        n = ((n%mod)* (n%mod)) % mod;
        k = k >> 1;
    }
    return res;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        auto start = high_resolution_clock::now();
        std::cout << binaryExpo(n, k) << std::endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        std::cout << "Time Taken:" << duration.count() << " ms" << std::endl;
    }
    return 0;
}
