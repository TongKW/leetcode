class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string token : tokens) {
            if (isOperand(token)) {
                long int int2 = s.top();
                s.pop();
                long int int1 = s.top();
                s.pop();
                long int result = operate(int1, int2, token);
                s.push(result);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }

    long int operate(long int int1, long int int2, string s) {
        if (s == "+") return int1 + int2;
        if (s == "-") return int1 - int2;
        if (s == "*") return int1 * int2;
        if (s == "/") return int1 / int2;
        return -1;
    }

    bool isOperand(string s) {
        if (s == "+") return true;
        if (s == "-") return true;
        if (s == "*") return true;
        if (s == "/") return true;
        return false;
    }
};
