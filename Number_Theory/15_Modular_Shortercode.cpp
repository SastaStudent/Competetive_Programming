#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int ModularInverse(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a; // gcd is a
    }
    int x1, y1;
    int smallans = ModularInverse(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return smallans;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int x, y;
        int m = 1e9 + 7;
        int gcd = ModularInverse(n, m, x, y);
        if (gcd == 1)
        {
            cout << "Modular Inverse of n is " << (x % m + m) % m << endl;
        }
    }
    return 0;
}