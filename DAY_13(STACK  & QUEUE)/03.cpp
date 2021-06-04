//queue using stack

#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int N;
    int front = -1;
    stack<int> s1;
    stack<int> s2;
public:
    Queue() {
        N = 0;
    }
    void Push(int val) {
        if(s2.empty()) front = val;
        s2.push(val);
        N++;
    }
    void Pop()
    {
        if(s1.empty() && s2.empty()) return;
        if(s1.empty()) {
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        s1.pop(),N--;
        front = s1.top();
    }
    int Size() {
        return N;
    }
    int Front()
    {
        return front;
    }
};

int main()
{
    Queue q;
    q.Push(5);
    q.Push(6);
    q.Push(7);
    q.Push(8);
    q.Pop();
    cout << q.Front() << " ";
    cout << q.Size();

}