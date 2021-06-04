//   ******  40. Combination Sum II  ******

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int begin, vector<int>& arr, int target,vector<vector<int>>& ans, vector<int>& ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=begin;i<arr.size();i++)
        {
            if(arr[i]>target) break;
            if(i!=begin && arr[i]==arr[i-1]) continue;
            
            ds.push_back(arr[i]);
            func(i+1,arr,target-arr[i],ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        func(0,candidates,target,ans,ds);
        return ans;
    }
};