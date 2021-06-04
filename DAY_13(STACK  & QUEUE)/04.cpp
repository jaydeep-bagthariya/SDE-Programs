//   ****** 20. Valid Parentheses ******

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length()%2==1) return false;
        
        stack<char>stack;
        
        for(char c: s)
        {
            if(c=='(' || c=='[' || c=='{')
                stack.push(c);
            else if(c==')' && !stack.empty() && stack.top()=='(')
                stack.pop();
            else if(c=='}' && !stack.empty() && stack.top()=='{')
                stack.pop();
            else if(c==']' && !stack.empty() && stack.top()=='[')
                stack.pop();
            else 
                stack.push(c);
        }
        return stack.empty();
        
    }
};