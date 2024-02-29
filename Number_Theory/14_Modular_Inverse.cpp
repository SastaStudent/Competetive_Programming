#include <iostream>
using namespace std;

class Triplet
{
public:
    int gcd;
    int x;
    int y;
};

Triplet modularInverse(int a, int m)
{
    if (m == 0)
    {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallans = modularInverse(m, a % m);
    Triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a / m) * smallans.y;
    return ans;
}

int main()
{
    /*gcd = gcd(a,b)=gcd(b,a%b);
        x=y1;
        y=x1-(a/b)*y1*/
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int m = 1e9 + 7; // m is modulo
        Triplet ans = modularInverse(n, m);
        if (ans.gcd != 1)
        {
            // Modular inverse does not exist because a and b should be coprime
            cout << "Not exist" << endl;
            continue;
        }
        cout << ((ans.x % m) + m) % m << endl;
    }
    return 0;
}
