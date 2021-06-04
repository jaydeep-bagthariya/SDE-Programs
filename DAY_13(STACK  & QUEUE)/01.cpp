//implementation of stack;
#include<bits/stdc++.h>
using namespace std;


class Stack
{
    int stack[100];
    int top = -1;
    public:
    void push(int a)
    {
        top = top+1;
        stack[top] = a;
    }
    void pop()
    {
        top = top-1;
    }
    bool isEmpty()
    {
        if(top==-1) return true;
        return false;
    }
    int Top()
    {
        return stack[top];
    }

};
 
int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    cout << s.Top();
    while(!s.isEmpty())
    {
        cout << s.Top() <<  endl;
        s.pop();
    }
    return 0;
}