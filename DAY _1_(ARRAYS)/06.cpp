// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<vector<int> > intervals(n, vector<int>(2));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
            cin>>intervals[i][j];
    }

    vector<vector<int> > ans;

    sort(intervals.begin(),intervals.end());

    vector<int> temp = intervals[0];

    for(auto x: intervals)
    {
        if(x[0]<=temp[1])
            temp[1] = max(x[1],temp[1]);
        else
        {
            ans.push_back(temp);
            temp = x;
        } 
    }
    ans.push_back(temp);

    cout << "[";
    for(auto y: ans)
        cout << "[" << y[0] << "," << y[1] << "]," << " ";
    cout << "]";
}