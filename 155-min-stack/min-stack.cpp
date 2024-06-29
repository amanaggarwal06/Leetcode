class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{

            if(val < mini){
                
                long long temp = val;
                temp = temp*2;
                temp = temp - mini;
                st.push(temp);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        
        if(!st.empty()){
            if(st.top() < mini){
                mini = 2*mini - st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        
        if(!st.empty()){
            if(st.top() < mini){
                return mini;
            }

            return st.top();
        }

        return -1;
    }
    
    int getMin() {
        return mini;
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