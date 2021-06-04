#include<bits/stdc++.h>
using namespace std;

int main()
{
        int count = 0;
        vector<vector<int> > arr(5, vector<int>(5,-1));
        
        int i=0;
        int j=0;
        int x = 2;
        while(x--)
        {
                int t = j;
                while(j<5-t)
                        arr[i][j++] = ++count;
                j--, i++;
                while(i<5-t)
                        arr[i++][j] = ++count;
                i--,j--;
                while(j>=0+t)
                        arr[i][j--] = ++count;
                j++,i--;
                while(i>=1+t)
                        arr[i--][j] = ++count;
                j++,i++;
        }
        arr[2][2]=++count;

        for(int i=0;i<5;i++)
        {
                for(int j=0;j<5;j++)
                        cout << arr[i][j] << " ";
                cout << endl;
        }
               
}