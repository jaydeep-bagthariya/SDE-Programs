//   ******  485. Max Consecutive Ones ******

// Given a binary array, find the maximum number of consecutive 1s in this array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

//SOLUTION

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
        
//         int n = nums.size();
        
//         int count = 0;
//         int ans = 0;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i] == 1) ans = max(ans,++count);
//             else count = 0;
//         }
//         return ans;
//     }
// };
#include<bits/stdc++.h>
using namespace std;

struct meeting
        {
            int start;
            int end;
            int pos;
        };
        bool comparator(struct meeting m1, meeting m2)
        {
            if(m1.end < m2.end) return true;
            else if(m1.end > m2.end) return false;
            else if(m1.pos < m2.pos) return true;
            return false;
        }
class Solution{
    public:
        
        int maxMeetings(int start[], int end[], int n) {
            struct meeting meet[n];
            for(int i=0;i<n;i++){
                meet[i].start = start[i],meet[i].end = end[i], meet[i].pos = i+1;
            }
            
            sort(meet,meet+n,comparator);
            
            int limit = meet[0].end;
            int count = 1;
            
            for(int i=1;i<n;i++)
            {
                if(meet[i].start > limit)
                {
                    limit = meet[i].end;
                    count++;
                }
            }
            cout << count << endl;
            return count;
    }
};
int main()
{
    int n;
    cin>>n;
    int start[n], end[n];
    for(int i=0;i<n;i++) cin>> start[i];
    for(int i=0;i<n;i++) cin>> end[i];

    Solution ob;
    int ans = ob.maxMeetings(start,end, n);
    cout << ans << end;
    return 0;
}

