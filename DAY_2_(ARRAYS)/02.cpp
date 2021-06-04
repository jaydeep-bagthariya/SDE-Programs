//   ******* 118. Pascal's Triangle *******

// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


// In Pascal's triangle, each number is the sum of the two numbers directly above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<int> > r(n);

    for(int i=0;i<n;i++)
    {
        r[i].resize(i+1);
        r[i][0]=r[i][i]=1;

        for(int j=1;j<i;j++)
            r[i][j]=r[i-1][j-1]+r[i-1][j];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<r[i].size();j++)
            cout << r[i][j];
        cout << endl;
    }
}