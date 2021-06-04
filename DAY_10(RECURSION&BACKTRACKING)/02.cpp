// N queens Problem (you should watch 51. N-Queens in leetcode);

#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>>& arr, int row, int col, int n)
{
    for(int i=0;i<row;i++)
        if(arr[i][col]==1)
            return false;
    
    int i=row;
    int j=col;
    while(i>=0 && j>=0)
        if(arr[i--][j--]==1)
            return false;
    i=row;
    j=col;
    while(i>=0 && j<n)
        if(arr[i--][j++]==1)
            return false;
        
    return true;
}
bool nQueen(vector<vector<int>>& arr, int row, int n,vector<vector<string>>& ans)
{
    if(row==n) return true;
    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,row,col,n))
        {
            arr[row][col]=1;
            if(nQueen(arr,row+1,n,ans))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;

    vector<vector<int>>board(n,vector<int>(n));
    vector<vector<string>>ans;
    if(nQueen(board,0,n,ans))
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        // for(auto i : ans)
        // {
        //     for(auto j : i)
        //         cout << j << " , ";
        //     cout << endl;
        // }
    }
}