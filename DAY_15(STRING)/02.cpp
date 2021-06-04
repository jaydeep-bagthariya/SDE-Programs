//  ******  5. Longest Palindromic Substring ******

// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
// Example 3:

// Input: s = "a"
// Output: "a"
// Example 4:

// Input: s = "ac"
// Output: "a"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case)

#include<bits/stdc++.h>
using namespace std;

//brute force approach
class Solution {
public:
    bool isPalindrome(string s, int i , int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0 && n==1) return s;
        string ans = "";
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    if(j-i+1>ans.size())
                        ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};

//optimal approach can be solve with dynamic programming 
//and currently I am enable to wirte code in DP;
