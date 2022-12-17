class MyQueue {
public:
    MyQueue() {
        onS1 = true;
    }
    void push(int x) {
        if (!onS1) {
            reverseStack(s2, s1);
            onS1 = true;
        }
        s1.push(x);
    }
    int pop() {
        if (onS1) {
            reverseStack(s1, s2);
            onS1 = false;
        }
        int temp = s2.top();
        s2.pop();
        return temp;
    }
    int peek() {
        if (onS1) {
            reverseStack(s1, s2);
            onS1 = false;
        }
        return s2.top();
    }
    bool empty() {
        if (onS1) return s1.empty();
        return s2.empty();
    }
    void reverseStack(stack<int>& fromS, stack<int>& toS) {
        while (!fromS.empty()) {
            int temp = fromS.top();
            toS.push(temp);
            fromS.pop();
        }
    }
private:
    stack<int> s1;
    stack<int> s2;
    bool onS1;
};
