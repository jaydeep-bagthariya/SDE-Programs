// ******  21. Merge Two Sorted Lists *****

// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

// Example 1:
// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: l1 = [], l2 = []
// Output: []

// Example 3:
// Input: l1 = [], l2 = [0]
// Output: [0]

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* Insert(Node* head, int d, int p)
{
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;

    if(p==1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node* temp = head;
        for(int i=1;i<p-1;i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

void print(Node* head)
{
    cout << "List is: ";
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void Merge(int d, Node **ans)
{
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    Node* temp = *ans;

    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* MergeLinkedList(Node* head, Node* head1)
{
    Node* n = new Node();
    n->data = 0;
    // Node* n3 = n;
    while(head && head1)
    {
        if(head->data <= head1->data)
        {
            Merge(head->data, &n);
            head = head->next;

            // n3->next = head;
            // head = head->next;
        }
        else
        {
            Merge(head1->data, &n);
            head1 = head1->next;

            // n3->next = head1;
            // head1 = head1->next;
        }

        // n3 = n3->next;
    }
    while(head)
    {
        Merge(head->data, &n);
        head = head->next;

        // n3->next = head;
        // head = head->next;
        // n3->next = head;
    }
    while(head1)
    {
        Merge(head1->data,&n);
        head1 = head1->next;

        // n3->next = head1;
        // head1 = head1->next;
        // n3->next = head;
    }
    return n->next;
}

Node* MergeLinkedListWithOptimalSolution(Node*l1, Node*l2)   //without extra space
{
    if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->data > l2->data)
            swap(l1,l2);
        Node* res = l1;
        while(l1 && l2)
        {
            Node* temp = NULL;
            
            while(l1 && l1->data<=l2->data)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
}

Node* MergeListMethod3(Node* head, Node* head1)
{
    Node* dummyNode = new Node();
    dummyNode->data = 0;

    Node* n3 = dummyNode;

    while(head && head1)
    {
        if(head->data < head1->data)
        {
            n3->next = head;
            head=head->next;
        }
        else
        {
            n3->next = head1;
            head1 = head1->next;
        }
        n3 = n3->next;
    }
    while(head)
    {
        n3->next = head;
        head=head->next;
        n3 = n3->next;
    }
    while(head1)
    {
        n3->next = head1;
        head1 = head1->next;
        n3 = n3->next;
    }
    return dummyNode->next;
}

Node* WithRecursion(Node* head, Node* head1)
{
    if(head == NULL) return head1;
    if(head1 == NULL) return head;

    if(head->data < head1->data)
    {
        head->next = WithRecursion(head->next, head1);
        return head;
    }
    else
    {
        head1->next = WithRecursion(head, head1->next);
        return head1;
    }  
}

int main()
{
    Node* head = NULL;

    head = Insert(head,2,1);
    head = Insert(head,4,2);
    head = Insert(head,1,1);
    print(head);

    Node* head1 = NULL;

    head1 = Insert(head1,1,1);
    head1 = Insert(head1,3,2);
    head1 = Insert(head1,4,3);
    head1 = Insert(head1,4,4);
    print(head1);

    Node* head5 = WithRecursion(head, head1); 
    print(head5);

    // Node* head2 = MergeLinkedList(head, head1);   
    // print(head2);

    Node* head3 = MergeListMethod3(head, head1); // Efficient and easy
    print(head3);

    // Node* head4 = MergeLinkedListWithOptimalSolution(head, head1);
    // print(head4);

    
}