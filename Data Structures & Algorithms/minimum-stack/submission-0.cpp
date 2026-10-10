class MinStack {
    int arr[30001];
    int mins[30001];
    int top_idx;
public:
    MinStack() {
        top_idx = 0;
        mins[0] = {INT_MAX};
    }
    
    void push(int val) {
        top_idx++;
        arr[top_idx] = val;
        mins[top_idx] = min(val, mins[top_idx-1]);
    }
    
    void pop() {
        top_idx--;
    }
    
    int top() {
        return arr[top_idx];
    }
    
    int getMin() {
        return mins[top_idx];
    }
};
