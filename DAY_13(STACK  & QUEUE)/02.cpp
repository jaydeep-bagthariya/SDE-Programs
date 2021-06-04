//stack using queue;

#include<bits/stdc++.h>
using namespace std;

class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }
    void Push(int i)
    {
        q2.push(i);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void Pop()
    {
        q1.pop(),N--;
    }
    int top()
    {
        return q1.front();
    }
    int Size()
    {
        return N;
    }

};
int main()
{
    Stack s;
    s.Push(10);
    s.Push(12);
    cout << s.Size() << " " << s.top();
    return 0;
}