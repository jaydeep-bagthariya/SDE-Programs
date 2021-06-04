// ****** 121. Best Time to Buy and Sell Stock ******

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.



// NEIVE APPROACH

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     vector<int> prices(n);

//     for(int i=0;i<n;i++)
//         cin>>prices[i];

//     int max_value = 0;
//     int temp;
//     for(int i=0;i<n-1;i++)
//     {
//         temp = 0;
//         for(int j=i+1;j<n;j++)
//         {
//             if(prices[j]>prices[i])
//                 temp = prices[j]-prices[i];
            
//             max_value = max(max_value, temp);
//         }
//     }
//     cout << max_value;
// }


// OPTIOMAL APPROACH

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;

//     vector<int> prices(n);

//     for(int i=0;i<n;i++)
//         cin>>prices[i];

//     int minPrice = INT_MAX;
//     int maxProfit = 0;
//     for(int i=0;i<n;i++)
//     {
//         minPrice = min(minPrice, prices[i]);

//         maxProfit = max(maxProfit, prices[i]-minPrice);
//     }
//     cout << maxProfit;
// }


