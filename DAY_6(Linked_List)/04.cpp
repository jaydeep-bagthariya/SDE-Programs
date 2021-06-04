//   ****** 234. Palindrome Linked List ******

// iven the head of a singly linked list, return true if it is a palindrome.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9



// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
        
//         if(!head && !head->next) return true;
        
//         vector<int> arr;
        
//         while(head)
//         {
//             arr.push_back(head->val);
//             head = head->next;
//         }
        
//         int n = arr.size();
        
//         int i = 0;
//         int j = n-1;
        
//         while(i<j)
//         {
//             if(arr[i]!=arr[j])
//                 return false;
//             i++,j--;
//         }
//         return true; 
//     }
// };


//OPTIMAL SOLUTION

// class Solution {
// public:
//    ListNode* Reverse(ListNode* head)
//    {
//         ListNode* pre = NULL;
//         ListNode* nex = NULL;
       
//        while(head)
//        {
//             nex = head->next;
//             head->next = pre;
//             pre = head;
//             head = nex;
//        }
//        return pre;
//    }
//     bool isPalindrome(ListNode* head) {
        
//         if(!head && !head->next) return true;
        
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast->next && fast->next->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         slow->next = Reverse(slow->next);
//         slow = slow->next;
        
//         while(slow)
//         {
//             if(slow->val != head->val)
//                 return false;
//             slow = slow->next;
//             head = head->next;
//         }
//         return true;
//     }
// };