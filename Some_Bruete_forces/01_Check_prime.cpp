#include <iostream>
#include <vector>
#include<chrono>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
int main()
{
    long long n;
    cin >> n;
    bool No = true;
    auto start = high_resolution_clock::now();
    for (long long i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << n << " is Not Prime"<<" Due to "<<i<<" Divides "<<n<<endl;;
            No = false;
            //break;
        }
    }
    auto stop =high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(stop-start);
    
    if (No)
        cout << n << " is Prime";

    cout<<"\nTime :"<<duration.count()<<"ms"<<endl;
    return 0;
}