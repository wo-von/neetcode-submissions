class MinStack {
private:
    stack<long> stk;
    long min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            min = val;
        } else {
            stk.push(val - min);
            if (val < min) min = val;
        }
        
    }
    
    void pop() {
        if (stk.empty()) return;
        long tmp = stk.top();
        stk.pop();
        if(tmp < 0){
            min = min - tmp;
        }
    }
    
    int top() {
        long tmp = stk.top();
        return (stk.top()>0) ? stk.top() + min : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
