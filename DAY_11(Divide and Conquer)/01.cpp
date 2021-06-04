// N-th root of an integer (use binary search) (square root, cube root, ..)

// for e.g 
// 1.  n = 3  m = 27 
//     so ans is 3;

// 2.  n = 2  m = 16
//     ans is 4;

#include<bits/stdc++.h>

using namespace std;

int main() 
{
    int n = 3, m = 27;
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while((high-low) > eps)    //it means low and high are almost same;     
    {
        double mid = (low+high)/2.0;

        double temp = 1.0;
        for(int i=0; i<n; i++){
            temp *= mid;
            if(temp>m) break;    //for reducing time
        }

        if(temp>m) high = mid;
        else low = mid; 
    }
    cout << high << endl;  //low is also ans;
}