#include <iostream>
#include <vector>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k, int startIndex) {
    if (startIndex == n) {
        if (k == 0) {
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }
    int arr1[100][50];
    int arr2[100][50];
    int size1 = subsetSumToK(input, n, arr1, k, startIndex + 1);
    int size2 = subsetSumToK(input, n, arr2, k - input[startIndex], startIndex + 1);
    int row = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j <= arr1[i][0]; j++) {
            output[row][j] = arr1[i][j];
        }
        row++;
    }
    for (int i = 0; i < size2; i++) {
        output[row][0] = arr2[i][0] + 1;
        output[row][1] = input[startIndex];
        for (int j = 1; j <= arr2[i][0]; j++) {
            output[row][j + 1] = arr2[i][j];
        }
        row++;
    }
    return row;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    return subsetSumToK(input, n, output, k, 0);
}
int main() {
    int n;
    // cout << "Enter the number of elements in the array: ";
    cin >> n;
       int k;
    // cout << "Enter the target sum: ";
    cin >> k;

    int input[n];
    // cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

 

    int output[100][50] = {0};
    int numSubsets = subsetSumToK(input, n, output, k);

    cout << "Number of subsets with sum " << k << ": " << numSubsets << endl;
    cout << "Subsets:" << endl;
    for (int i = 0; i < numSubsets; i++) {
        for (int j = 1; j <= output[i][0]; j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
