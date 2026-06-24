// main idea: encode the value and min using difference
// Store val - min on each push
// pop - if the popped element is negative, restore old min with min = min - encoded
// top - if encoded > 0, val = encoded + min, if encoded <= 0, val = min


class MinStack {
private:
    stack<long> stk;   
    long min;

public:
    MinStack() {}
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(0); // push difference
            min = val;
        }
        else {
            stk.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (stk.empty()) return;

        long encoded = stk.top();
        stk.pop();
        
        if (encoded < 0) min = min - encoded;
    }
    
    int top() {
        long encoded = stk.top();
        return (encoded > 0)? encoded + min: (int) min;
    }
    
    int getMin() {
        return (int)min;
    }
};
