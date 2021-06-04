// Rabin Carp Algorithm


//solution with poor hash
#include<bits/stdc++.h>
using namespace std;
bool rabinCarp(string s1, string s2,int n , int m)
{
    int sum = 0;
    int sum2 = 0;
    for(int i=0;i<m;i++)
        sum += (s2[i]-'a');
    int i = 0;
    int j = 0;
    while(j<n)
    {
        sum2 += (s1[j]-'a');
        if(j-i+1<m)j++;
        else
        {
            if(sum == sum2)
            {
                bool flag = true;
                for(int ind=0;ind<m;ind++)
                    if(s1[ind+i] != s2[ind])
                    {
                        flag = false;
                        break;
                    }
                if(flag) return true;
            }
            sum2 -= (s1[i]-'a');
            i++,j++;
        }   
    }
    return false;
}
int main()
{
    string s1 = "ababcbadadcabd";
    string s2 = "abdc";

    int n = s1.size();
    int m = s2.size();

    if(rabinCarp(s1,s2,n,m)) cout << "true";
    else cout << "false";

    return 0;
}

//we can make it strong by multiply with any nymber and mod by any large prime number 
// for that watch tack dose vedio