//   ****** 31. Next Permutation ******

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
// Example 4:

// Input: nums = [1]
// Output: [1]




// We can easily solve this using C++ STL Library

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());  <-----
//     }
// };




// SIMPLE SOLUTION

// Steps of this algorithm are
// 1.Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// 2.Find the largest index l > k such that nums[k] < nums[l].
// 3. Swap nums[k] and nums[l].
// 4.Reverse the sub-array nums[k + 1:].

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    int k,l;

    for(k=n-2;k>=0;k--)
    {
        if(nums[k]<nums[k+1])
            break;
    }

    if(k<0)
        reverse(nums.begin(),nums.end());

    else
    {
        for(l=n-1;l>k;l--)
            if(nums[l]>nums[k])
                break;

        swap(nums[l],nums[k]);

        reverse(nums.begin()+k+1, nums.end());
    }

    for(auto x: nums)
        cout << x << " ";
}