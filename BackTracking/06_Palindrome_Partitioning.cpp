#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Required Functions*/
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

void partitionHelper(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.length(); ++end) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s); // Function declaration

vector<vector<string>> partition(string &s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    return result;
}

/*Driver Code*/
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    //string str;
    //getline(cin, str);
    while(t--) {

        string S;
        getline(cin, S);

        vector<vector<string>> ans = partition(S);

        for(int i = 0; i < ans.size(); i++) {

            cout << "[";

            sort(ans[i].begin(), ans[i].end());
            for(int j = 0; j < ans[i].size(); j++) {

                if(j != ans[i].size() - 1) {
                    cout << "\"" << ans[i][j] << "\", ";
                }
                else {
                    cout << "\"" << ans[i][j] << "\"";
                }

            }

            cout << "]" << endl;

        }

    }

    return 0;

}
