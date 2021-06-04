// ****** Count the number of subarrays having a given XOR ******
//(Note: You need to revice frequenty this question its hard to understand logic)

// Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
// Examples: 

// Input : arr[] = {4, 2, 2, 6, 4}, m = 6
// Output : 4
// Explanation : The subarrays having XOR of 
//               their elements as 6 are {4, 2}, 
//               {4, 2, 2, 6, 4}, {2, 2, 6},
//                and {6}

// Input : arr[] = {5, 6, 7, 8, 9}, m = 5
// Output : 2
// Explanation : The subarrays having XOR of
//               their elements as 5 are {5}
//               and {5, 6, 7, 8, 9}


//simple solution

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[] = {4,2,2,6,4};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int m = 6;
//     int count = 0;
//     for(int i=0;i<n;i++)
//     {
//         int xorr = 0;
//         for(int j=i;j<n;j++)
//         {
//              xorr ^= arr[j];
//              if(xorr == m)
//                 count++;
//         }
//     }
//     cout << count;
//     return 0;
// }


//OPTIOMAL APPROACH

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4,2,2,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 6;

    unordered_map<int, int> um;

    int count = 0;
    int xorr = 0;

    for(int a: arr)
    {
        xorr ^= a;

        if(xorr == m) 
            count++;
        
        if(um.find(xorr^m)!=um.end())
            count += um[xorr^m];
        
        um[xorr]+=1;
    }
    cout << count;
    return 0;
}