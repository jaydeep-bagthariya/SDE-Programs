// Efficiently merging two sorted arrays with O(1) extra space

// Example:  

// Input: ar1[] = {10};
//        ar2[] = {2, 3};
// Output: ar1[] = {2}
//         ar2[] = {3, 10}  

// Input: ar1[] = {1, 5, 9, 10, 15, 20};
//        ar2[] = {2, 3, 8, 13};
// Output: ar1[] = {1, 2, 3, 5, 8, 9}
//         ar2[] = {10, 13, 15, 20} 

// method 1 
// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n,m;
//     cin>>n>>m;

//     vector<int> a1(n);
//     vector<int> a2(m);

//     for(int i=0;i<n;i++)
//         cin>> a1[i];

//     for(int i=0;i<m;i++)
//         cin>>a2[i];

//     for(int i=0;i<n;i++)
//     {
//         if(a1[i]>a2[0])
//         {
//             swap(a1[i],a2[0]);

//             int temp = a2[0];
//             int j;
//             for(j=1;j<m && a2[j]<temp;j++)
//              {
//                  a2[j-1]=a2[j];
//              } 
//              a2[j-1]=temp;  
//         }
//     }

//     for(int i: a1)
//         cout << i << " ";

//     cout << endl;

//     for(int j: a2)
//         cout << j << " ";
    
//     return 0;
// }

//method 2:

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a1(n);
    vector<int> a2(m);

    for(int i=0;i<n;i++)
        cin>> a1[i];

    for(int i=0;i<m;i++)
        cin>>a2[i];
    
    for(int gap = ceil((m+n)/2);gap>0;gap=ceil(gap/2))
    {
        int i,j;
        for(i=0;i+gap<n;i++)
        {
            if(a1[i]>a1[i+gap])
                swap(a1[i],a1[i+gap]);
        }

        for(j=gap>n?gap-n:0;i<n && j<m ;i++,j++)
            if(a1[i]>a2[j])
                swap(a1[i],a2[j]);

        if(j<m)
        {
            for(j=0;j+gap<m;j++)
                if(a2[j]>a2[j+gap])
                    swap(a2[j],a2[j+gap]);
        }
    }

    for(int i: a1)
        cout << i << " ";
    
    cout << endl;

    for(int j: a2)
        cout << j << " ";

    return 0;
}

