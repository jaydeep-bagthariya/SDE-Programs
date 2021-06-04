//  ****** 60. Permutation Sequence ******(LEETCODE HARD)
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"

#include<bits/stdc++.h>
using namespace std;

//silly solution ;)
class Solution {
public:
    string getPermutation(int n, int k) {
        
        int val=0;
        for(int i=1;i<=n;i++)
            val = val*10+i;
        string ans = to_string(val);
        for(int i=0;i<k-1;i++)
            next_permutation(ans.begin(),ans.end());
        return ans;
    }
};

//another brute force solution done by 
//1.find all permutation using recursion
//2.store value in vector
//3.then sort them and find k-1 value in vactor

// best solution

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> num;
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k = k-1;
        while(1)
        {
            ans = ans + to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            k = k%fact;
            fact = fact/num.size();
        }
        return ans;
    }
};