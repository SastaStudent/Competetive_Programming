#include <iostream>
#include <vector>
using namespace std;

int modularInverse(int a, int d, int m) {
    long long res = 1;
    while (d > 0) {
        if (d & 1) {
            res = (res * a) % m;
        }
        a = (a * 1LL * a) % m; // Update a first, then perform right shift
        d >>= 1; // right shift
    }
    return static_cast<int>(res);
}

int main() {
     // Fermat's theorem
    /*a^(p-1)=1 mod m
     divide by a both side.
     a^(p-2)=a^-1 mod m .....where p is prime
     so a^-1 = a^(p-2)mod m.....*/
    int tc;
    cin >> tc;
    const int m = 7;
    while (tc--) {
        int n;
        cin >> n;
        cout << "Modulo Inverse of " << n << " is " << modularInverse(n, m - 2, m) << endl;
    }
    return 0;
}
