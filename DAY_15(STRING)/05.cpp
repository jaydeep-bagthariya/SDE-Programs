//   ******  14. Longest Common Prefix  ******

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.


#include<bits/stdc++.h>
using namespace std;

//In this algo we check first char of all string then second and so on
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        if(n==NULL) return prefix;
        for(int i=0;i<strs[0].size();i++)
        {
            int j = 1;
            for(;j<n && strs[j].size()>i; j++)
                if(strs[j][i] != strs[0][i])
                    return prefix;
            if(j==n) prefix += strs[0][i];
            else return prefix;
        }
        return prefix;
    }
};