class MinStack {
private:
    stack<int> stk;     // actual values
    stack<int> minStk;  // running min

public:
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        
        // new min is val or previous min, whichever smaller
        if (minStk.empty() || minStk.top() > val)  
            minStk.push(val);
        else
            minStk.push(minStk.top());
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top(); 
    }
};
