// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<long long> s;
    long long cur_min;
    MinStack() {
        cur_min=(long long)1e12;
        // take appropriate infinity
    }
    
    void push(int val) {
        if(val >= cur_min)
        {
            s.push(val);
        }
        else
        {
            // ENCRYPTION
            long long toPush=2LL * val - cur_min;
            cur_min=val;
            s.push(toPush);
        }
    }
    
    void pop() {
        if(s.top() < cur_min)
        {

            // DECRYPTION
            long long pushedEle=s.top();
            long long oldMinAtThatTime=2LL * cur_min - pushedEle;
            cur_min=oldMinAtThatTime;
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
    
    int top() {
        if(s.top() < cur_min)
        {
            return cur_min;
        }
        else
        {
            return s.top();
        }
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */