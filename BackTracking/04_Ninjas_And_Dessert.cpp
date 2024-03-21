#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
/*this is the required function*/
#include <bits/stdc++.h>
using namespace std;

void update(int target, int curr, int &ans) {
    if (abs(target - curr) < abs(target - ans)) {
        ans = curr;
    } else if (abs(target - curr) == abs(target - ans)) {
        ans = min(curr, ans);
    }
}

void top(int index, vector<int>& topping, int target, int curr, int &ans) {
    // Base case
    if (index == topping.size()) {
        update(target, curr, ans);
        return;
    }

    // None
    top(index + 1, topping, target, curr, ans);
    // One topping
    top(index + 1, topping, target, curr + topping[index], ans);
    // Two toppings
    top(index + 1, topping, target, curr + 2 * topping[index], ans);
}

int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
    int ans = INT_MAX; 
 
    for (int base : baseCosts) {
        top(0, toppingCosts, target, base, ans);
    }

    return ans;
}

 
 

/*Driver code*/
class Runner
{
    int t;
    vector<int> n, m, target;
    vector<vector<int>> base, toppings;

public:
    void takeInput()
    {
        cin >> t;

        for (int i = 0; i < t; i++)
        {
            int N;
            cin >> N;
            n.push_back(N);

            vector<int> v;
            for (int j = 0; j < N; j++)
            {
                int B;
                cin >> B;
                v.push_back(B);
            }
            base.push_back(v);

            int M;
            cin >> M;
            m.push_back(M);

            vector<int> u;
            for (int k = 0; k < M; k++)
            {
                int top;
                cin >> top;
                u.push_back(top);
            }

            toppings.push_back(u);

            int tar;
            cin >> tar;

            target.push_back(tar);
        }
    }

    void execute()
    {
        vector<vector<int>> cpyB = base;
        vector<vector<int>> cpyT = toppings;

        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{

#ifndef ONLINE_JUDGE
//freopen("TestCases/large/in/input11.txt", "r", stdin);
//freopen("TestCases/large/out/output11.txt", "w", stdout);
#endif
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
