#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

/*Required function*/
void helper(vector<int> &arr, int target, int index, vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < arr.size(); ++i)
    {
        if (arr[i] > target) // No need to continue if candidates[i] is greater than the target
        {
            break;
        }
        current.push_back(arr[i]);
        helper(arr, target - arr[i], i, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combSum(vector<int> &arr, int target)
{
    vector<vector<int>> result;
    vector<int> current;
    sort(arr.begin(), arr.end()); // Sorting the array to maintain non-decreasing order
    helper(arr, target, 0, current, result);
    return result;
}

/*Driver code*/
class Runner
{
    int t;

    vector<vector<int>> arr;
    vector<int> B;

public:
    void solve(vector<vector<int>> &res, int currIndex, int currSum, vector<int> &currList, int B, vector<int> &ARR)
    {
        if (currSum == B)
        {
            res.push_back(currList);
            return;
        }
        if (currIndex == ARR.size())
        {
            return;
        }

        solve(res, currIndex + 1, currSum, currList, B, ARR);

        int count = 0;
        while (currSum <= B)
        {
            count++;
            currSum += ARR[currIndex];
            currList.push_back(ARR[currIndex]);
            solve(res, currIndex + 1, currSum, currList, B, ARR);
        }

        while (count--)
        {
            currList.pop_back();
        }
    }

    vector<vector<int>> go(vector<int> &ARR, int B)
    {
        sort(ARR.begin(), ARR.end());
        vector<vector<int>> res;
        vector<int> currList;
        solve(res, 0, 0, currList, B, ARR);
        return res;
    }

    void takeInput()
    {

        t = 1;
        B.resize(t);
        for (int c = 0; c < t; c++)
        {
            int n;
            cin >> n >> B[c];
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
                cin >> temp[i];
            arr.push_back(temp);
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            vector<int> copy = arr[i];
            vector<vector<int>> res = combSum(copy, B[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            vector<vector<int>> res = combSum(arr[i], B[i]);
            vector<vector<int>> ans = go(arr[i], B[i]);
            sort(ans.begin(), ans.end());
            sort(res.begin(), res.end());
            if (ans == res)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
};

int main()
{

    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}