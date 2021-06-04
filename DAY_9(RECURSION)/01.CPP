// Subset Sums

// Given a list(Arr) of N integers, print sums of all subsets in it.
// Output should be printed in increasing order of sums.

// Example 1:

// Input:
// N = 2
// Arr = [2, 3]
// Output:
// 0 2 3 5
// Explanation:
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then 
// Sum = 2+3 = 5.
// Example 2:

// Input:
// N = 3
// Arr = [5, 2, 1]
// Output:
// 0 1 2 3 5 6 7 8

#include<bits/stdc++.h>
using namespace std;


void func(vector<int>&arr,vector<int>&sumSubset,int N,int ind,int sum)
    {
        if(ind == N)
        {
            sumSubset.push_back(sum);
            return;
        }
        func(arr,sumSubset,N,ind+1,sum+arr[ind]);
        func(arr,sumSubset,N,ind+1,sum);
    }
vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>sumSubset;
        int ind = 0;
        int sum = 0;
        func(arr,sumSubset,N,ind,sum);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }