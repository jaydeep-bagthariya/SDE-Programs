//   ******  496. Next Greater Element I  ******

// You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.

// Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

// The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, return -1 for this number.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation:
// For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
// For number 1 in the first array, the next greater number for it in the second array is 3.
// For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation:
// For number 2 in the first array, the next greater number for it in the second array is 3.
// For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> um;
        for(int n : nums2) {
            while(!s.empty() && n>s.top())
            {
                um[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for(int n : nums1)
            ans.push_back(um.count(n)?um[n]:-1);
        return ans;
    }
};