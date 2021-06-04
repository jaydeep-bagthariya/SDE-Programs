 // ****** 876. Middle of the Linked List ******

// 1st approach

// int Middle(Node* head)
// {
//     Node* temp = head;
//     int count = 0;
//     while(temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     int n = count/2 + 1;

//     temp = head;
//     for(int i=1;i<n;i++)
//     {
//         temp = temp->next;
//     }
//     return temp->data;
// }


//2nd AND BETTER APPROACH

// int MiddleBetter(Node* head)
// {
//     Node* slow = head, *fast = head;

//     while(fast && fast->next)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow->data;
// }