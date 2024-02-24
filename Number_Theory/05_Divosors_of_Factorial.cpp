#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
const int k = 1e5 + 2;
const int m = 1e9 + 7;

void sieve() {
    bool arr[k + 1];
    for (int i = 0; i <= k; i++) {
        arr[i] = true;
    }
    arr[0] = arr[1] = false;
    for (int i = 2; i * i <= k; i++) {
        if (arr[i]) {
            for (int p = i * i; p <= k; p += i) {
                arr[p] = false;
            }
        }
    }
    for (int i = 2; i <= k; i++) {
        if (arr[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    sieve();
    while (t--) {
        long n;
        cin >> n;
        //for every primes divide n by primes and primes*primes till <=n
        //for n=9 p=2.. 
        /*n/p ---> n/p^2---> n/p^3----> ti p^k<=n 
        let this expression gives 5 
        and for p=3.. give 4
        and for p=5 give 3
        ans will be (5+1)* (4+1) * (3+1) */
        long ans = 1;
        for (int i = 0; primes[i] <= n; i++) {
            long temp = primes[i]*primes[i];
            long res = n / primes[i];
            while (temp <= n) {
                res+=n/temp;
                temp *= primes[i];
            }
            //cout<<res<<" ";
            ans = (ans * (res + 1)) % m;
        }
       // cout<<endl;
        cout << ans << endl;
    }
    return 0;
}
