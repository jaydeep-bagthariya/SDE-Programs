//   ******  42. Trapping Rain Water  ****** (leetcode hard)
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

// Example 1:


// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
//  In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9
 
// Constraints:

// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105

#include<bits/stdc++.h>
using namespace std;


//brute force approach
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            int left = height[i];
            for(int j=0;j<i;j++)
                left = max(left,height[j]);
            
            int right = height[i];
            for(int j=i+1;j<n;j++)
                right = max(right,height[j]);
            
            int x = min(left,right) - height[i];
            ans += x;

        }
        return ans;
    }
};


//BETTER APPROACH 
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<1) return 0;
        vector<int> pre(n);
        vector<int> post(n);
        
        pre[0] = height[0];
        for(int i=1;i<n;i++)
            pre[i] = max(pre[i-1],height[i]);
        
        post[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
            post[i] = max(post[i+1],height[i]);
        int ans = 0;
        for(int i=0;i<n;i++)  
            ans += (min(pre[i],post[i]) - height[i]);
        return ans;
    }
};

//optimal approach
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int res =0;
        
        while(left<=right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= leftMax)
                    leftMax = height[left];
                else res += leftMax - height[left];
                left++;
            }
            else
            {
                if(height[right] >= rightMax)
                    rightMax = height[right];
                else res += rightMax-height[right];
                right--;
            }
        }
        return res;
        
    }
};