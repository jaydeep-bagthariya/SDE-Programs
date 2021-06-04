//Remove N-th node from back of LinkedList 

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

Node* Delete(Node *head,int p)
{
   
    Node* fast = head;
    Node* slow = head;

    while(p--)
    {
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}

int main()
{
    Node* head = NULL;

    head = Insert(head,2,1);
    head = Insert(head,4,2);
    head = Insert(head,1,3);
    head = Insert(head,3,4);
    head = Insert(head,5,5);
    print(head);

    int position;
    cin>>position;

    head = Delete(head,position);
    print(head);

    return 0;
}