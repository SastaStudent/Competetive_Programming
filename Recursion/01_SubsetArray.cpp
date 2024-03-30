#include <iostream>
using namespace std;
int subset(int input[], int n, int startIndex, int output[][20])
{
    if (startIndex == n)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallSize = subset(input, n, startIndex + 1, output);

    for(int i=0;i<smallSize;i++)
    {
        int rowSize=output[i][0]+1;
        output[smallSize+i][0]=rowSize;
        //fill currindex value
        output[smallSize+i][1]=input[startIndex];
        for(int col=2;col<=rowSize;col++)
        {
            output[smallSize+i][col]=output[i][col-1];

        }
        



    }

    return 2 * smallSize;
}

int subset(int input[], int n, int output[][20])
{
    return subset(input, n, 0, output);
}

int main()
{
    int input[20], length, output[3500][20];
    cin >> length;
    for (int i = 0; i < length; i++){
        cin >> input[i];
    }

    int size = subset(input, length, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}
