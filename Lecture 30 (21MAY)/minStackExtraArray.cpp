// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int>mi;
    stack<int>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty() or val < mi.top() )
        {
            mi.push(val);
            
        }   
        else
        {
            mi.push(mi.top());
        }
        s.push(val);
    }
    
    void pop() {
        mi.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mi.top();
    }
};