//  ASKED MANY TIME IN GOOGLE

// ******  62. Unique Paths ******

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
// Example 3:

// Input: m = 7, n = 3
// Output: 28
// Example 4:

// Input: m = 3, n = 3
// Output: 6
 

// Constraints:

// 1 <= m, n <= 100
// It's guaranteed that the answer will be less than or equal to 2 * 109.

//BRUTE FORCE APPROACH WITH RECURSION

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPath(int i,int j,int m,int n)
    {
        if(i==(m-1) && j==(n-1)) return 1;
        if(i>=m || j>=n) return 0;
        return countPath(i+1,j,m,n) + countPath(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return countPath(0,0,m,n);
    }
};

//BETTER APPORACH WITH DYNAMIC PROGRAMMING 

class Solution2 {
public:
    int countPath(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i==(m-1) && j==(n-1)) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j] = countPath(i+1,j,m,n,dp) + countPath(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp (m,vector<int>(n,-1));
        return countPath(0,0,m,n,dp);
    }
};



//BEST SOLUTION  (it can be done by recursion and dynamic programming)


int main()
{
    int m,n;
    cin>>m>>n;

    int N = m+n-2;
    int r = n-1;

    double ans=1;

    for(int i=1;i<=r;i++)
        ans = ans * (N-r+i)/i;
    
    cout << (int)ans;
    
}