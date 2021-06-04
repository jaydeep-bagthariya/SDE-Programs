// ****** Count Inversions in an array | Set 1 (Using Merge Sort) ******

// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
// Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
// Example: 

// Input: arr[] = {8, 4, 2, 1}
// Output: 6

// Explanation: Given array has six inversions:
// (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


// Input: arr[] = {3, 1, 2}
// Output: 2

// Explanation: Given array has two inversions:
// (3, 1), (3, 2) 


//Method 1: BRUTE FORCE APPROACH O(n2)

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     int arr[n];

//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     int inv_count = 0;

//     for(int i=0;i<n-1;i++)
//         for(int j=i+1;j<n;j++)
//             if(arr[i]>arr[j])
//                 inv_count++;

//     cout << inv_count;

//     return 0;
// }


// OPTIOMAL APPROACH WITH MERGE SORT

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int right, int mid)
{
    int inv_count = 0;
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<=mid && j<=right)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];

            inv_count = inv_count + (mid-i+ 1);
        }
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];

    for(int i=left;i<=right;i++)
        arr[i]=temp[i];
    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int inv_count = 0;
    if(left < right)
    {
        int mid = (left+right)/2;

       inv_count += mergeSort(arr, temp, left, mid);
       inv_count += mergeSort(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, right, mid);
    }
    return inv_count;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int temp[n];

    int ans = mergeSort(arr, temp, 0, n-1);
    cout << ans;

    return 0;
}