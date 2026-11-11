class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x;
        while (q1.size() > 1) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1, q2);
        x = q2.front();
        q2.pop();
        return x;
    }
    
    int top() {
        int x;
        while (q1.size() > 0) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1, q2);
        return x;

    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */