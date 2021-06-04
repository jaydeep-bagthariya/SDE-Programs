#include<bits/stdc++.h>
using namespace std;


//with array
int main()
{
    vector<int> request = {1,2,3,4,1,3};
    vector<int> cacheSize(3);
    int n = cacheSize.size();
    int ind = 0;
    int pagingFault = 0;
    for(auto i : request)
    {
        if(ind<n) cacheSize[ind++]=i,pagingFault++;
        int j;
        for(j=0;j<n;j++)
            if(cacheSize[j]==i)
                break;
        if(j==n)
        {
            pagingFault++;
            for(int j=1;j<n;j++)
                cacheSize[j-1] = cacheSize[j];
            cacheSize[n-1] = i;
        }
        else if(ind>=n)
        {
            int temp = cacheSize[j];
            for(int k=j+1;k<n;k++)
                cacheSize[k-1] = cacheSize[k];
            cacheSize[n-1] = temp; 
        }
        
    }
    cout << pagingFault << endl;
    for(int i : cacheSize)
        cout << i << " ";
    
}

    
