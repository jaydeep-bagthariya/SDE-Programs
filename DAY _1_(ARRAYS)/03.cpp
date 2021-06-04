// Find the repeating and the missing

// Given an unsorted array of size n. Array elements are in the range from 1 to n.
// One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

// Examples: 

//  Input: arr[] = {3, 1, 3}
// Output: Missing = 2, Repeating = 3
// Explanation: In the array, 
// 2 is missing and 3 occurs twice 

// Input: arr[] = {4, 3, 6, 2, 1, 1}
// Output: Missing = 5, Repeating = 1


//optimal method 1


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++)
        cin>>nums[i];

    long long int sum_N = (n * (n+1))/2;
    long long int sum_Nsq = (n * (n+1) * (2*n+1))/6;
    long long int missing_number, repeating_number;

    for(int i=0;i<n;i++)
    {
        sum_N -= (long long int)nums[i];
        sum_Nsq -= (long long int)nums[i]*(long long int)nums[i];
    }

    missing_number = (sum_N + sum_Nsq/sum_N)/2;
    repeating_number = missing_number - sum_N;

    vector<int> res;
    res.push_back(repeating_number);
    res.push_back(missing_number);

        cout << "Repeating numeber is: "  << res[0] << endl;
        cout << "Missing number is: " << res[1];

    return 0;
}


// second optimal methos is using xor but I am unable to understand it so :(