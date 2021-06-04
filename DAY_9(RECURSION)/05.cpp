//   ******  131. Palindrome Partitioning ******

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// A palindrome string is a string that reads the same backward as forward.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string s,int l,int h)
    {
        if(l>=h) return true;
        if(s[l]!=s[h]) return false;
        return palindrome(s,++l,--h);
    }
    void helper(string s, vector<vector<string>>& ans, vector<string> &temp,int begin)
    {
        if(begin == s.size())
        {
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i=begin;i<s.size();i++)
        {
            t = t+s[i];
            if(palindrome(t,0,t.size()-1))
            {
                temp.push_back(t);
                helper(s,ans,temp,i+1);
                temp.pop_back();
            }
            //we can also right this without using 'string t'
            // if(palindrome(s,begin,i))
            // {
            //     temp.push_back(s.substr(begin,i-begin+1));
            //     helper(s,ans,temp,i+1);
            //     temp.pop_back();
            // }   
        }
    }
    vector<vector<string>> partition(string s) {  //Start from here
        vector<vector<string>> ans;
        vector<string> temp;
        helper(s,ans,temp,0);
        return ans;
    }
};