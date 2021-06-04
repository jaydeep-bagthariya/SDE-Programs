// ****** 206. Reverse Linked List ******



#include<bits/stdc++.h>
using namespace std;


//  ITERATIVE METHOD


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
        
//         ListNode* pre, *current, *next;
        
//         current = head;
//         pre = NULL;
        
//         while(current!=NULL)
//         {
//             next = current->next;
//             current->next = pre;
//             pre = current;
//             current = next;
//         }
        
//         head = pre;
//         return head;
        
//     }
// };


//RECURESIVE METHOD

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
        
//           if (! head || ! head->next)
//                     return head;
        
//         ListNode* next = head->next;
//         ListNode* newNode = reverseList(next);
//         head->next = NULL;
//         next->next = head;
        
//         return newNode;
        
        
//     }
// };