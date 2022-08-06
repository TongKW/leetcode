#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // (  )  [  ]  {   } 
        // 40 41 91 93 123 125
        stack<int> stack;
        for(char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                char top = stack.top();
                int diff = (int)c - (int)top;
                if (diff != 1 && diff != 2) return false;
                stack.pop();
            }
        }
        return stack.empty();
    }    
};
