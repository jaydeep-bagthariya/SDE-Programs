//   ******  18. 4Sum  ******
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [], target = 0
// Output: []
 

// Constraints:

// 0 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

//SOLUTION 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > ans;
        if(nums.size()<4) return ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-3;i++)
        {
            for(int j=i+1;j<nums.size()-2;j++)
            {
                int target2 = target-nums[i]-nums[j];
                int left = j+1;
                int right = nums.size()-1;
                while(left<right)
                {
                    if(nums[left]+nums[right]<target2)left++;
                    else if(nums[left]+nums[right]>target2)right--;
                    else
                    {
                        vector<int> temp({nums[i],nums[j],nums[left],nums[right]});
                        ans.push_back(temp);
                        
                        while(left<right && nums[left]==temp[2])left++;
                        while(left<right && nums[right]==temp[3])right--;
                    }
                }
                while(j+1<(nums.size()-1) && nums[j+1]==nums[j])j++;
            }
            while(i+1<(nums.size()-1) && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};