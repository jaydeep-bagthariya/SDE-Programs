// create your own atoi and strstr function

#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{
    int n = s.size();
    int ans = 0;
    int i = 0;
    int sign = 1;
    if(s[0]=='-')
        sign = -1,i++;
    for(;i<n;i++)
    {
        int it = s[i]-'0';
        if(it>=0 && it<10)
            ans = ans*10 +(s[i]-'0');
        else break;
    }
    return sign*ans;
}
int main()
{
    string s = "12345";
    int i = myAtoi(s);
    cout << i;
    return 0;
}

//strStr function implementatiaon
//Currently I don't know KMP algo so unable to do that
//But I know RABIN CARP ALOG so this solution is with rabin carp algo with weak hash


// ******  28. Implement strStr()  ******

// Implement strStr().

// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2
// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
// Example 3:

// Input: haystack = "", needle = ""
// Output: 0'
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        if(n==NULL && m == NULL) return 0;
        int sum1 = 0;
        int sum2 = 0;
        for(char i : needle)
            sum1 += (i-'a');
        int i=0,j=0;
        while(j<n)
        {
            sum2 += (haystack[j]-'a');
            if(j-i+1 < m) j++;
            else {
                if(sum1 == sum2) {
                    int ind;
                    for(ind=0;ind<m;ind++)
                        if(needle[ind] != haystack[ind+i])
                            break;
                    if(ind == m)
                        return i;
                }
                sum2 -= (haystack[i]-'a');
                i++,j++;
            }
        }
        return -1;
    }
};
