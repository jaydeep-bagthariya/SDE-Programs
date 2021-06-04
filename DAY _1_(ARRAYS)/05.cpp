//KANDANE'S ALGORITHM

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> a(n);
    
    for(int i=0;i<n;i++)
        cin>>a[i];

    int sum = INT_MIN;
    int cur_sum = 0;
    for(int i=0;i<n;i++)
    {
        cur_sum = 0;
        for(int j=i;j<n;j++)
        {
            cur_sum += a[j];

            sum = max(sum, cur_sum);
        }
    }
    cout << sum;

    // int total_sum = 0;
    // int sum = INT_MIN;

    // for(int i=0;i<n;i++)
    // {
    //     total_sum += a[i];

    //     sum = max(total_sum, sum);

    //     if(total_sum<0)
    //         total_sum = 0;
    // }
    //  cout << sum;

     return 0;
}