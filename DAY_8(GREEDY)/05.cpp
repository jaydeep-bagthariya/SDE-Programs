// ****** Greedy Algorithm to find Minimum number of Coins ******

// Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?

// Examples:  

// Input: V = 70
// Output: 2
// We need a 50 Rs note and a 20 Rs note.

// Input: V = 121
// Output: 3
// We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coin[9]={1,2,5,10,20,50,100,500,1000};
    int v;
    cin>>v;
    int i = 8;
    int count = 0;
    while(v)
    {
        if(v<coin[i])i--;
        else {
            v -= coin[i];
            count++;
        }
    }
    cout << count;
}