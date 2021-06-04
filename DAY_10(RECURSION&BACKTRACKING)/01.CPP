// Print all Permutations of a string/array

#include<bits/stdc++.h>
using namespace std;

void printAllPermutation(string s,int l,int r)
{
    if(l==r)
    {
        cout << s << endl;
        return;
    }
    for(int i=l;i<=r;i++)   
    {
        swap(s[l],s[i]);
        printAllPermutation(s,l+1,r);
        swap(s[l],s[i]);
    }
}
int main()
{
    string s;
    cout << "Enter any string: ";
    cin>>s;

    printAllPermutation(s,0,s.size()-1);
    return 0;
}
