// ****** Largest subarray with 0 sum ******

// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.


//BRUTE FORCE APPROACH IS DONE N3 BY CHEAKING ALL POSSIBLE COMBINATIONS

//OPTIMAL SOLUTION

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    unordered_map<int,int> map;

    int sum = 0;
    int Max = 0;

    for(int i=0;i<n;i++)
    {
        sum += nums[i];
        if(sum==0)
            Max = i+1;
        else if(map.count(sum))
            Max = max(Max, i-map[sum]);
        else
            map[sum]=i;
    }
    cout << Max;
    return 0;
}