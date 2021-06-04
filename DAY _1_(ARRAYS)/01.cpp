// ******  287. Find the Duplicate Number ******

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [1,1]
// Output: 1
// Example 4:

// Input: nums = [1,1,2]
// Output: 1


// method 1:

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            nums[abs(nums[i])] = -nums[abs(nums[i])];
            
            if(nums[abs(nums[i])]>0)
                return abs(nums[i]);
        }
        return 0;
    }
};

//optimal solution 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};



int main()
{
    Solution s;
    vector<int> arr = {1,3,4,2,2};
    int i = s.findDuplicate(arr);
    cout << i;
}