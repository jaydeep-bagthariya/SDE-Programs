 // Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of 
// the same color are adjacent, with the colors in the order red, white, and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Follow up:

// Could you solve this problem without using the library's sort function?
// Could you come up with a one-pass algorithm using only O(1) constant space?
 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
// Example 3:

// Input: nums = [0]
// Output: [0]
// Example 4:

// Input: nums = [1]
// Output: [1]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is 0, 1, or 2.



// most optimal method.

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    int low = 0;
    int mid = 0;
    int hi = n-1;

    while(mid<=hi)
    {
        switch(nums[mid])
        {
            case 0:
                swap(nums[low++],nums[mid++]);
                break;
            
            case 1:
                mid++;
                break;
            
            case 2:
                swap(nums[mid],nums[hi--]);
                break;
        }
    }

    for(int i: nums)
        cout << i << " ";
}
