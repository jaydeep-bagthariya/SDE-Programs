// ****** 15. 3Sum  *****
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105

#include<bits/stdc++.h>
using namespace std;

// OPTIMAL SOLUTION 
// THE APPROACH IS SAME AS 4 SUM

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > ans;
        
        if(!nums.size()) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {   
                int target = -nums[i];
                int left = i+1;
                int right = nums.size()-1;

                while(left<right)
                {
                    if(nums[left]+nums[right] < target) left++;
                    else if( nums[left]+nums[right] > target) right--;
                    else
                    {
                        vector<int> temp ({nums[i], nums[left], nums[right]});
                        ans.push_back(temp);

                        while(left<right && nums[left] == temp[1]) left++;
                        while(left<right && nums[right] == temp[2]) right--;
                    }
                }
             while(i+1<(nums.size()) && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};