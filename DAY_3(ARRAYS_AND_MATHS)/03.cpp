// ****** 169. Majority Element ******

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> num(n);

    for(int i=0;i<n;i++)
        cin >> num[i];

    int element=num[0];
    int count=1;

    for(int i=1;i<n;i++)
    {
        if(count==0)
            element = num[i];
        
        if(element == num[i])
            count++;
        else
        {
            count--;
        }    
    }
    cout << element;

    return 0;
}